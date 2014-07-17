#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtGui/QtEvents>
#include <QtCore/QMimeData>
#include <QtCore/QFileInfo>
#include <QtWidgets/QListWidget>
#include "dialog.h"
#include "../Classes/JsonX.h"

//选择列表项
class ListWidgetItem : public QListWidgetItem
{
public:
    ListWidgetItem() {}
    ListWidgetItem(QFileInfo &fileinfo) { file_info = fileinfo; }
    QString getFileName() { return file_info.fileName(); }
	QString getAbsoluteFilePath() { return file_info.absoluteFilePath(); }
	
	//获取列表项精灵的类型
	QString getSpriteType() { return this->text(); }
	//精灵属性
	JsonX	m_attr;
private:
	//列表项图片文件信息
	QFileInfo file_info;

};

//图片选择列表
class ListWidget : public QListWidget
{
    Q_OBJECT

public:
    ListWidget(QWidget *parent = 0);

    //拖拽事件处理
    void dragEnterEvent(QDragEnterEvent *event);

    void dragMoveEvent(QDragMoveEvent *event);

    void dropEvent(QDropEvent *event);

    //右键菜单事件处理
    void contextMenuEvent ( QContextMenuEvent * event);

    //是否可添加到列表中
    bool canAdd(QString path);

    //列表中添加一个条目
    bool addSpriteToList(QString path);

 public slots:
    //在场景中添加精灵
    void addSpriteToScene();

    //设置添加精灵属性
    void setSpriteAttribute();

    //修改精灵类型名
    void changeSpriteType();

    //删除被选中列表项
    void delSelectedSprite();

    //列表过滤操作
    void filter(QString str);

};

#endif // LISTWIDGET_H
