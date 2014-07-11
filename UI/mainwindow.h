#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
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

private slots:
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

	void changeSizeX(int x);
	void changeSizeY(int y);

    //编辑模式的多种编辑方式
	//圆形编辑
    void circleEdit();
	//多边形编辑
    void polygonEdit();
	//精灵编辑
    void commonEdit();
	//删除选中的精灵
    void deleteSelected();
	//选取精灵
	void choiceEdit();
	//撤销编辑
	void undoEdit();

    //进入浏览模式和编辑模式
    void enterBrowseMode();
    void enterEditMode();

	void showGrid(bool show); 
	void gridNumChange(int num); 
	
public slots:
    //在场景中添加精灵
	void addSpriteToScene();

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();

private:
	//cocos2dx视图窗口
	Cocos2dxView	*cocos2dx_view;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
