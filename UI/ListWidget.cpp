#include "ListWidget.h"
#include "mainwindow.h"
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QInputDialog>


ListWidget::ListWidget(QWidget *parent):QListWidget(parent)
{
    setAcceptDrops(true);
}

void ListWidget::dragEnterEvent(QDragEnterEvent *event)
{
    QList<QUrl> urls=event->mimeData()->urls();
    for(QUrl url : urls)
    {
        if(!canAdd(url.toLocalFile()))
            return;
    }
    event->accept();
    qDebug("ok");
    return;
}

void ListWidget::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
}

void ListWidget::dropEvent(QDropEvent *event)
{
    //添加列表
    QList<QUrl> urls=event->mimeData()->urls();
    for(QUrl url : urls)
    {
        addSpriteToList(url.toLocalFile());
    }
}

bool ListWidget::canAdd(QString path)
{
    return path.endsWith(".png");
}

bool ListWidget::addSpriteToList(QString path)
{
    //允许重复
    //忽略重复项
    QFileInfo fileinfo= QFileInfo(path);
//    QList<QListWidgetItem *> res = findItems(fileinfo.baseName(),Qt::MatchCaseSensitive);
//    if(res.count() > 0)
//        return false;
    qDebug("%s", fileinfo.baseName().toLatin1().data() );

    ListWidgetItem *item = new ListWidgetItem(fileinfo);
    item->setIcon(QIcon(path));
    item->setText(fileinfo.baseName());
//      item1->setBackgroundColor(QColor(100,0,0));
//      item->setSizeHint(QSize(100,100));

    this->addItem(item);
    return true;
}

void ListWidget::filter(QString str)
{
    QList<QListWidgetItem *> res = findItems(str,Qt::MatchContains);
    for(int i=0; i < count(); i++)
    {
        this->item(i)->setHidden(true);
    }
    for(QListWidgetItem *item : res)
    {
        item->setHidden(false);
    }
}

void ListWidget::contextMenuEvent( QContextMenuEvent * event)
{
    QMenu *popMenu = new QMenu(this);
    if(itemAt(mapFromGlobal(QCursor::pos()))!=NULL)
    {
        QAction *add = new QAction(QIcon(":/images/add.png"), QStringLiteral("在场景中添加此精灵"), this);
        connect(add, SIGNAL(triggered()), this, SLOT(addSpriteToScene()));
        popMenu->addAction(add);

        QAction *setting = new QAction(QIcon(":/images/setting.png"), QStringLiteral("设置精灵属性"), this);
        connect(setting, SIGNAL(triggered()), this, SLOT(setSpriteAttribute()));
        popMenu->addAction(setting);

        QAction *change = new QAction(QIcon(":/images/change.png"), QStringLiteral("修改精灵类型"), this);
        connect(change, SIGNAL(triggered()), this, SLOT(changeSpriteType()));
        popMenu->addAction(change);

        QAction *del = new QAction(QIcon(":/images/trash.png"), QStringLiteral("删除精灵"), this);
        connect(del, SIGNAL(triggered()), this, SLOT(delSelectedSprite()));
        popMenu->addAction(del);
    }
    else
    {
        delete popMenu;return;
        //空白处点击的菜单
    }
    popMenu->exec(QCursor::pos()); // 菜单出现的位置为当前鼠标的位置
}

void ListWidget::changeSpriteType()
{
    bool ok;
    QListWidgetItem *item = this->currentItem();
    QString name = QInputDialog::getText(this, QStringLiteral("提示"), QStringLiteral("请输入新的精灵类型名:"), QLineEdit::Normal, item->text(), &ok);
    if(ok)
    {
        item->setText(name);
    }
}

void ListWidget::delSelectedSprite()
{
//    QList<QListWidgetItem*> list = this->selectedItems()
    QListWidgetItem *item = this->currentItem();
    if(item == NULL)
        return;
    int res = QMessageBox::question(this, QStringLiteral("警告!"),QStringLiteral("你确定要删除此项吗?"),  QMessageBox::Yes, QMessageBox::No);
    if(res == QMessageBox::Yes)
    {
        this->takeItem(this->currentRow());
    }
}

void ListWidget::setSpriteAttribute()
{
    Dialog *d = new Dialog(this);
    int x = d->exec();
    qDebug(" exec %d", x);
}

void ListWidget::addSpriteToScene()
{
   MainWindow *w = (MainWindow*)this->parent();
   w->addSpriteToScene();
}

