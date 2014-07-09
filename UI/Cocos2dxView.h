#ifndef COCOS2DXVIEW_H
#define COCOS2DXVIEW_H
#include "GL\glew.h"

#include "../Classes/AppDelegate.h"
#include <QtWidgets\QMainWindow>
#include <QtWidgets\QScrollArea>
#include <QtGui\QMouseEvent>
#include <QtCore\QTimer>

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

private slots:
	//渲染cocos2dx
	void renderCocos2dx();

	//设置鼠标上的精灵位置
	void mouseMoveInView();

public:
	void enterEvent(QEvent *event) override;
	void leaveEvent(QEvent *event) override;

	//将qt消息再封装成window消息发送给cocos2dx
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	//鼠标在视图移动的定时器
	QTimer m_mouseTimer;

	//渲染定时器
	QTimer m_timer;

	AppDelegate cocos2dx_app;
	cocos2d::CCSprite *m_mouseSprite;

	//内置默认分辨率
	const int defaultSizeX = 480;
	const int defaultSizeY = 320;
};

#endif
