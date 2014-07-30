#ifndef COCOS2DXVIEW_H
#define COCOS2DXVIEW_H
#include "GL\glew.h"

#include "../Classes/AppDelegate.h"
#include "../Classes/EditorScene.h"
#include "../Classes/CommonObject.h"
#include "../Classes/PolygonObject.h"
#include "../Classes/CircleObject.h"
#include "OperatioManage.h"
#include <QtWidgets\QMainWindow>
#include <QtWidgets\QScrollArea>
#include <QtGui\QMouseEvent>
#include <QtCore\QTimer>
#include "../proj.win32/ModeState.h"
#include "ListWidget.h"

USING_NS_CC;
//CloseNormal
class Cocos2dxView : public QWidget
{
	Q_OBJECT

public:
	Cocos2dxView(QWidget *parent = 0);

	virtual ~Cocos2dxView();

	//初始化cocos2dx视图并启动渲染
	void initCocos2dx();
	
	//获取cocos2dx gl视图
	CCEGLView* getView() { return CCEGLView::sharedOpenGLView(); }

	//设置视图的大小
	void setViewGeometry(const QRect &rect);
	//设置视图背景
	void setBackground(QString filename);
	CC_SYNTHESIZE(std::string, m_bkFileName, BackgroundFileName);
	//获取视图层指针
	EditorScene* getEditorScene() {return (EditorScene*)CCDirector::sharedDirector()->getRunningScene()->getChildByTag(view_tag);}

private slots:
	//渲染cocos2dx
	void renderCocos2dx();

	//设置鼠标上的精灵位置
	void mouseMoveInView();

	//右键菜单
	//删除选中对象
	void delChoiceObject();
	//设置对象属性
	void setObjectAttribute();

public:
	void enterEvent(QEvent *event) override;
	void leaveEvent(QEvent *event) override;
	//附着被选中的精灵到鼠标上
	void attachSpriteToMouse();

	//鼠标在视图移动的定时器
	QTimer m_mouseTimer;

	//渲染定时器
	QTimer m_timer;

	//将qt消息再封装成window消息发送给cocos2dx
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	//各个模式下独立的鼠标响应处理
	//左键响应
	//浏览模式
	void mousePressInBrowse(QMouseEvent *event);
	void mouseMoveInBrowse(QMouseEvent *event);
	void mouseReleaseInBrowse(QMouseEvent *event);
	QPointF	m_prePosition;
	//圆形编辑模式
	void mousePressInCircleEdit(QMouseEvent *event);
	void mouseMoveInCircleEdit(QMouseEvent *event);
	void mouseReleaseInCircleEdit(QMouseEvent *event);
	//多边形编辑模式
	void mousePressInPolygonEdit(QMouseEvent *event);
	void mouseMoveInPolygonEdit(QMouseEvent *event);
	void mouseReleaseInPolygonEdit(QMouseEvent *event);
	//普通编辑模式
	void mousePressInCommonEdit(QMouseEvent *event);
	void mouseMoveInCommonEdit(QMouseEvent *event);
	void mouseReleaseInCommonEdit(QMouseEvent *event);
	QPointF	m_commonPos;
	//选取编辑模式
	void mousePressInChoiceEdit(QMouseEvent *event);
	void mouseMoveInChoiceEdit(QMouseEvent *event);
	void mouseReleaseInChoiceEdit(QMouseEvent *event);
	//停止所有对象的闪烁
	void stopAllBlink();
	//右键响应
	//右键菜单事件处理
    void contextMenuEvent ( QContextMenuEvent * event);

	//将qt全局坐标点转换为2dx视图中的opengl点
	cocos2d::CCPoint convertToOpenglPoint(QPoint point)
	{
		QRect r = this->geometry();
		QPoint	pos = mapFromGlobal(point);
		return ccp(pos.rx(), r.height() - pos.ry());
	}

	AppDelegate cocos2dx_app;
	cocos2d::CCSprite *m_mouseSprite;	
	
	//存储当前编辑的圆形操作对象，无则为NULL
	CC_SYNTHESIZE(CircleEditOper*, m_curCircleOper, CurCircleOper);
	//存储当前编辑的多边形操作对象
	CC_SYNTHESIZE(PolygonEditOper*, m_curPolyOper, CurPolyOper);	

	//精灵图片列表
	CC_SYNTHESIZE(ListWidget*, m_listwidget, ListWidget);

	//当前被选中的对象,用于右键菜单
	CC_SYNTHESIZE_READONLY(BaseObject*, m_choicedObj, ChoiceObject);

	//是否格式化输出数据
	CC_SYNTHESIZE(bool, m_isPretty, IsPretty);

	//保存场景数据到文件
	bool saveDataToFile(QString filepath);
private:
	//保存对象相关的数据
	void saveObjectData(JsonX &data, BaseObject *object);
	//获取对象在列表项中的属性数据
	JsonX* getObjectAttr(std::string type_name, std::string filename="");
public:

	//内置默认分辨率
	const int defaultSizeX = 480;
	const int defaultSizeY = 320;
};

#endif
