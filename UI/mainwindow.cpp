#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	ui->scrollArea->setWidgetResizable(false);
	ui->scrollArea->takeWidget();
	ui->scrollArea->setAlignment(Qt::AlignCenter);

	//设置背景色
	QPalette pal; 
	pal.setColor(ui->scrollArea->backgroundRole(), Qt::gray);
	ui->scrollArea->setPalette(pal);

	this->setWindowTitle("MyEditor");

    connect(ui->lineEdit,SIGNAL(textChanged(QString)), ui->listWidget, SLOT(filter(QString)));
    connect(ui->rotateSpinBox, SIGNAL(valueChanged(double)), SLOT(rotateChange(double)));
    connect(ui->scaleSpinBox, SIGNAL(valueChanged(double)), SLOT(scaleChange(double)));

    connect(ui->toolButtonCircle, SIGNAL(clicked()), this, SLOT(circleEdit()));
    connect(ui->toolButtonPolygon, SIGNAL(clicked()), this, SLOT(polygonEdit()));
    connect(ui->toolButtonPaint, SIGNAL(clicked()), this, SLOT(commonEdit()) );
    connect(ui->toolButtonDelete, SIGNAL(clicked()), this, SLOT(deleteSelected()));
	connect(ui->toolButtonChoice, SIGNAL(clicked()), this, SLOT(choiceEdit()));

    connect(ui->radioButtonBrowse, SIGNAL(clicked()), this, SLOT(enterBrowseMode()));
    connect(ui->radioButtonEdit, SIGNAL(clicked()), this, SLOT(enterEditMode()));

	connect(ui->sizeX, SIGNAL(valueChanged(int)), SLOT(changeSizeX(int)));
    connect(ui->sizeY, SIGNAL(valueChanged(int)), SLOT(changeSizeY(int)));

	qDebug("%d", ui->sizeX->text().toInt());
	this->cocos2dx_view = new Cocos2dxView(this);
	ui->scrollArea->setWidget(cocos2dx_view);


    QListWidgetItem *item1;
    item1 = new QListWidgetItem;

	//test
    item1->setIcon(QIcon(":/images/change.png"));
    item1->setSizeHint(QSize(100,100));
    item1->setText("LOCK");
    ui->listWidget->addItem(item1);

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();
}

void MainWindow::createActions()
{
    ui->actionNew->setIcon(QIcon(":/images/new.png"));
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(newFile()));

    ui->actionOpen->setIcon(QIcon(":/images/open.png"));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));

    ui->actionSave_As->setIcon(QIcon(":/images/saveas.png"));
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(saveAs()));

    ui->actionPublic_As->setIcon(QIcon(":/images/publicas.png"));
    connect(ui->actionPublic_As, SIGNAL(triggered()), this, SLOT(publicDataAs()));

    ui->actionAdd_Sprites->setIcon(QIcon(":/images/addsprites.png"));
    connect(ui->actionAdd_Sprites, SIGNAL(triggered()), this, SLOT(addSprites()));

    ui->actionDelete_Sprite->setIcon(QIcon(":/images/trash.png"));
    connect(ui->actionDelete_Sprite, SIGNAL(triggered()), ui->listWidget, SLOT(delSelectedSprite()));

    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui->actionPublic, SIGNAL(triggered()), this, SLOT(publicData()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::createMenus()
{
}

void MainWindow::createToolBars()
{
    ui->mainToolBar->addAction(ui->actionNew);
    ui->mainToolBar->addAction(ui->actionOpen);
    ui->mainToolBar->addAction(ui->actionSave_As);
    ui->mainToolBar->addAction(ui->actionPublic_As);

    ui->mainToolBar->addAction(ui->actionAdd_Sprites);
}

void MainWindow::createStatusBar()
{
    ui->statusBar->show();
}

MainWindow::~MainWindow()
{
	delete cocos2dx_view;
    delete ui;
}

void MainWindow::newFile()
{
    qDebug("press");
    QMessageBox::warning(this, "tip", "wait to do -_-");
}

void MainWindow::open()
{
    qDebug("press");
    QMessageBox::warning(this, "tip", "wait to do -_-");
}

bool MainWindow::save()
{
	delete cocos2dx_view;
    qDebug("press");
    QMessageBox::warning(this, "tip", "wait to do -_-");
    return true;
}

bool MainWindow::saveAs()
{
    qDebug("press");
    QMessageBox::warning(this, "tip", "wait to do -_-");
    return true;
}

bool MainWindow::publicData()
{
    qDebug("press");
    QMessageBox::warning(this, "tip", "wait to do -_-");
    return true;
}

bool MainWindow::publicDataAs()
{
    qDebug("press");
    QMessageBox::warning(this, "tip", "wait to do -_-");
    return true;
}

bool MainWindow::addSprites()
{
    qDebug("press");
    QStringList list =  QFileDialog::getOpenFileNames(this, "添加关卡元素", QString(),
                                                      "Images (*.bmp *.tiff *.gif *.png *.jpg)");
    qDebug("%d", list.length());
    if(list.length() > 0)
    {
        for(QString &path : list)
        {
            if(ui->listWidget->canAdd(path))
                ui->listWidget->addSpriteToList(path);
        }
        return true;
    }
    return false;
}

void MainWindow::about()
{
    QMessageBox::about(this, "about", "this is a tollage editor by xiaok");
}

void MainWindow::rotateChange(double rotate)
{
    qDebug("%lf", rotate);
}

void MainWindow::scaleChange(double scale)
{
    qDebug("%lf", scale);
}

void MainWindow::addSpriteToScene()
{
   qDebug("%d", 5);
}

void MainWindow::circleEdit()
{
    qDebug("circle");
}

void MainWindow::polygonEdit()
{
    qDebug("polygon");
}

void MainWindow::commonEdit()
{
    qDebug("common");
}

void MainWindow::deleteSelected()
{
    qDebug("delete");
}

void MainWindow::choiceEdit()
{
	qDebug("select");
}

void MainWindow::enterBrowseMode()
{
    qDebug("browse");
}

void MainWindow::enterEditMode()
{
    qDebug("edit");
}

void MainWindow::changeSizeX(int x)
{
	qDebug("%d", x);
	QRect r = cocos2dx_view->geometry();
	r.setWidth(x);
	cocos2dx_view->setViewGeometry(r);
}

void MainWindow::changeSizeY(int y)
{
	qDebug("%d", y);
	QRect r = cocos2dx_view->geometry();
	r.setHeight(y);
	cocos2dx_view->setViewGeometry(r);
}

void MainWindow::enterEvent(QEvent *e)
{
	//qDebug("%d %d", QCursor::pos().rx(), QCursor::pos().ry());
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
	//qDebug("%d %d", e->pos().rx(), e->pos().ry());
}
