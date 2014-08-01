#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QSpinBox>
#include <QtCore/QEvent>
#include "ListWidget.h"
#include "Cocos2dxView.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    //捕获鼠标进入窗口事件
	void enterEvent(QEvent *e);

	void mouseMoveEvent(QMouseEvent *e);

	//事件过滤
	void keyPressEvent(QKeyEvent *event);

private slots:
	//设置输出格式化
	void setFormatOut(bool pretty);

	//改变UI皮肤
	void changeSkin(int id);

	//菜单功能槽
    void newFile();
    void open();
    bool save();
    bool saveAs();
    bool publicData();
    bool publicDataAs();
    bool addSprites();
	void setSceneBackground();
    void about();

	//控件槽
    void rotateChange(double rotate);
    void scaleChange (double scale);

	void changePosX(int x);
	void changePosY(int y);
	void changeSizeX(int x);
	void changeSizeY(int y);
	void changeTypeName(QString name);

    //编辑模式的多种编辑方式
	//圆形编辑
    void circleEdit();
	//多边形编辑
    void polygonEdit(bool checked);
	//精灵编辑
    void commonEdit();
	//删除选中的精灵
    void deleteSelected();
	//选取精灵
	void choiceEdit(bool checked);
	//撤销编辑
	void undoEdit();

    //进入浏览模式和编辑模式
    void enterBrowseMode();
    void enterEditMode();

	 //形状点编辑的完成和撤销
    void completeShapeEdit();
    void cancelShapeEdit();

	void showGrid(bool show); 
	void gridNumChange(int num); 
	//形状拖拽启用
	void shapeDrag(bool isDrag);
	
public slots:
    //在场景中添加精灵
	void addSpriteToScene();

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
	void createTip();

private:
	//当前操作的文件名
	QString	m_curFile;
	
	//cocos2dx视图窗口
	Cocos2dxView	*cocos2dx_view;
public:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
