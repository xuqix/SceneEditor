#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "OperatioManage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	ui->scrollArea->setWidgetResizable(false);
	ui->scrollArea->takeWidget();
	ui->scrollArea->setAlignment(Qt::AlignCenter);
	ui->radioButtonBrowse->setChecked(true);

	ui->pushButtonComplete->setVisible(false);
	ui->pushButtonCancel->setVisible(false);

	ui->toolButtonDelete->setVisible(false);

	ui->typeName->setDisabled(true);

	//设置背景色
	QPalette pal; 
	pal.setColor(ui->scrollArea->backgroundRole(), Qt::gray);
	ui->scrollArea->setPalette(pal);

	this->setWindowTitle("MyEditor");

	this->cocos2dx_view = new Cocos2dxView(this);
	cocos2dx_view->setListWidget(ui->listWidget);
	ui->scrollArea->setWidget(cocos2dx_view);

    connect(ui->lineEdit,SIGNAL(textChanged(QString)), ui->listWidget, SLOT(filter(QString)));
    connect(ui->rotateSpinBox, SIGNAL(valueChanged(double)), SLOT(rotateChange(double)));
    connect(ui->scaleSpinBox, SIGNAL(valueChanged(double)), SLOT(scaleChange(double)));

    connect(ui->toolButtonCircle, SIGNAL(clicked()), this, SLOT(circleEdit()));
	connect(ui->toolButtonPolygon, SIGNAL(toggled(bool)), this, SLOT(polygonEdit(bool)));
    connect(ui->toolButtonPaint, SIGNAL(clicked()), this, SLOT(commonEdit()) );
    connect(ui->toolButtonDelete, SIGNAL(clicked()), this, SLOT(deleteSelected()));
	connect(ui->toolButtonChoice, SIGNAL(toggled(bool)), this, SLOT(choiceEdit(bool)));
	connect(ui->toolButtonUndo, SIGNAL(clicked()), this, SLOT(undoEdit()));

    connect(ui->radioButtonBrowse, SIGNAL(clicked()), this, SLOT(enterBrowseMode()));
    connect(ui->radioButtonEdit, SIGNAL(clicked()), this, SLOT(enterEditMode()));

	connect(ui->sizeX, SIGNAL(valueChanged(int)), this, SLOT(changeSizeX(int)));
    connect(ui->sizeY, SIGNAL(valueChanged(int)), this, SLOT(changeSizeY(int)));
	connect(ui->posxSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changePosX(int)));
	connect(ui->posySpinBox, SIGNAL(valueChanged(int)), this, SLOT(changePosY(int)));

	connect(ui->checkBoxGrid, SIGNAL(clicked(bool)),this, SLOT(showGrid(bool)));
    connect(ui->spinBoxGridNum, SIGNAL(valueChanged(int)), this, SLOT(gridNumChange(int)));
	connect(ui->checkBoxDragShape, SIGNAL(clicked(bool)), this, SLOT(shapeDrag(bool)));

	connect(ui->pushButtonComplete, SIGNAL(clicked()), this, SLOT(completeShapeEdit()));
    connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(cancelShapeEdit()));

	connect(ui->typeName, SIGNAL(textChanged(QString)), this, SLOT(changeTypeName(QString)));

	//test
	QFileInfo info("H:\\test\\TollgateEditor\\images\\change.png");
	qDebug("%s %s", info.fileName().toLatin1().data(), info.absoluteFilePath().toLatin1().data());
    ListWidgetItem *item1;
    item1 = new ListWidgetItem(info);
    item1->setIcon(QIcon(":/images/change.png"));
    item1->setSizeHint(QSize(100,100));
    item1->setText("LOCK");
    ui->listWidget->addItem(item1);


    createActions();
    createMenus();
    createToolBars();
    createStatusBar();

	ui->radioButtonBrowse->clicked(true);
//	ModeStateX->setPrimaryMode(ModeState::BrowseMode);
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

    ui->actionSet_Background->setIcon(QIcon(":/images/setbk.png"));
    connect(ui->actionSet_Background, SIGNAL(triggered()), this, SLOT(setSceneBackground()));

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
	ui->mainToolBar->addAction(ui->actionSet_Background);
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
    QMessageBox::warning(this, "tip", "wait to do -_-");
}

void MainWindow::open()
{
    QMessageBox::warning(this, "tip", "wait to do -_-");
}

bool MainWindow::save()
{
	delete cocos2dx_view;
    QMessageBox::warning(this, "tip", "wait to do -_-");
    return true;
}

bool MainWindow::saveAs()
{
    QMessageBox::warning(this, "tip", "wait to do -_-");
    return true;
}

bool MainWindow::publicData()
{
	if (m_curFile.isEmpty())
	{
		publicDataAs();
	}
	else
	{
		cocos2dx_view->saveDataToFile(m_curFile);
	}
    return true;
}

bool MainWindow::publicDataAs()
{
	m_curFile = QFileDialog::getSaveFileName(this, QStringLiteral("导出场景数据到"), QString(), "JsonFile (*)");
	if (m_curFile.isEmpty())
		return false;

	cocos2dx_view->saveDataToFile(m_curFile);
    return true;
}

void MainWindow::setSceneBackground()
{
    QString filename =  QFileDialog::getOpenFileName(this, QStringLiteral("设置场景背景"), QString(),
                                                      "Images (*.png *.jpg)");

    if(!filename.isEmpty())
    {
		cocos2dx_view->setBackground(filename);
    }
}

bool MainWindow::addSprites()
{
    QStringList list =  QFileDialog::getOpenFileNames(this, QStringLiteral("添加关卡元素"), QString(),
                                                      "Images (*.bmp *.tiff *.gif *.png *.jpg)");

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
	BaseObject *object = cocos2dx_view->getChoiceObject();
	if (!object) return;
	if ((object->getObjectType() == ObjectType::COMMON_OBJECT) && object->getisBlink())
		object->setRotation(rotate);
}

void MainWindow::scaleChange(double scale)
{
	BaseObject *object = cocos2dx_view->getChoiceObject();
	if (!object) return;
	if ((object->getObjectType() == ObjectType::COMMON_OBJECT) && object->getisBlink())
		object->setScale(scale);
}

void MainWindow::addSpriteToScene()
{

}

void MainWindow::circleEdit()
{
	if (ModeStateX->getPrimaryMode() == ModeState::BrowseMode) return;
	ModeStateX->setSubMode(ModeState::CircleEdit);
}

void MainWindow::polygonEdit(bool checked)
{
	if (!checked) ui->pushButtonComplete->click();
	if (ModeStateX->getPrimaryMode() == ModeState::BrowseMode) return;
	ui->pushButtonComplete->setVisible(checked);
	ui->pushButtonCancel->setVisible(checked);

	if(checked)	ModeStateX->setSubMode(ModeState::PolygonEdit);
}

void MainWindow::commonEdit()
{
	if (ModeStateX->getPrimaryMode() == ModeState::BrowseMode) return;
	ModeStateX->setSubMode(ModeState::CommonEdit);
}

void MainWindow::choiceEdit(bool checked)
{
	if (!checked) { ui->typeName->setText(""); ui->typeName->setDisabled(true); }
	if (!checked) cocos2dx_view->stopAllBlink();
	if (ModeStateX->getPrimaryMode() == ModeState::BrowseMode) return;
	cocos2dx_view->setCursor( checked ? Qt::ClosedHandCursor : Qt::ArrowCursor);
	if (!checked) return;
	qDebug("select");
	ModeStateX->setSubMode(ModeState::ChoiceEdit);
}

void MainWindow::deleteSelected()
{

}

void MainWindow::undoEdit()
{
	//撤销操作
	cocos2dx_view->setCurPolyOper(NULL);
	if(!OperationManageX->undo())
		QMessageBox::warning(this, QStringLiteral("提示"), QStringLiteral("无法撤销!"));
}

void MainWindow::enterBrowseMode()
{
	ui->pushButtonComplete->setVisible(false);
	ui->pushButtonCancel->setVisible(false);
	cocos2dx_view->stopAllBlink();

	cocos2dx_view->setCursor(Qt::OpenHandCursor);
    qDebug("browse");
	ModeStateX->setPrimaryMode(ModeState::BrowseMode);
	ModeStateX->setSubMode(ModeState::NoSubMode);
}

void MainWindow::enterEditMode()
{
	cocos2dx_view->setCursor(Qt::ArrowCursor);
    qDebug("edit");
	ModeStateX->setPrimaryMode(ModeState::EditMode);
	ui->toolButtonPaint->click();
}

void MainWindow::changePosX(int x)
{
	BaseObject *obj = cocos2dx_view->getChoiceObject();
	if (obj && obj->getObjectType()==ObjectType::COMMON_OBJECT)
		cocos2dx_view->getChoiceObject()->setPositionX(x);
}

void MainWindow::changePosY(int y)
{
	BaseObject *obj = cocos2dx_view->getChoiceObject();
	if (obj && obj->getObjectType()==ObjectType::COMMON_OBJECT)
		cocos2dx_view->getChoiceObject()->setPositionY(y);
}

void MainWindow::changeSizeX(int x)
{
	QRect r = cocos2dx_view->geometry();
	r.setWidth(x);
	cocos2dx_view->setViewGeometry(r);
}

void MainWindow::changeSizeY(int y)
{
	QRect r = cocos2dx_view->geometry();
	r.setHeight(y);
	cocos2dx_view->setViewGeometry(r);
}

void MainWindow::changeTypeName(QString name)
{
	if (name.isEmpty()) return;
	if (ModeStateX->getPrimaryMode() == ModeState::EditMode && ModeStateX->getSubMode() == ModeState::ChoiceEdit)
	{
		cocos2dx_view->getChoiceObject()->setTypeName(name.toLatin1().data());
		if (cocos2dx_view->getChoiceObject()->getObjectType() == ObjectType::COMMON_OBJECT)
			ui->typeName->setDisabled(true);
		else
			ui->typeName->setDisabled(false);
	}
}

void MainWindow::enterEvent(QEvent *e)
{
	//qDebug("%d %d", QCursor::pos().rx(), QCursor::pos().ry());
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
	//qDebug("%d %d", e->pos().rx(), e->pos().ry());
}

void MainWindow::showGrid(bool show)
{
	int gap = ui->spinBoxGridNum->value();
	cocos2dx_view->getEditorScene()->setGridView(show, gap);
}

void MainWindow::gridNumChange(int num)
{
	bool show = ui->checkBoxGrid->isChecked();
	cocos2dx_view->getEditorScene()->setGridView(show, num);
}

void MainWindow::completeShapeEdit()
{
	cocos2dx_view->setCurPolyOper(NULL);
}

void MainWindow::cancelShapeEdit()
{
	//撤销上次增加的顶点
	if (cocos2dx_view->getCurPolyOper())
		cocos2dx_view->getCurPolyOper()->popPoint();
}

void MainWindow::shapeDrag(bool isDrag)
{
	CCArray *children = cocos2dx_view->getEditorScene()->getObjectLayer()->getChildren();
	CCObject *_obj;
	CCARRAY_FOREACH(children, _obj)
	{
		BaseObject *object = (BaseObject*)_obj;
		if (object->getObjectType() == ObjectType::CIRCLE_OBJECT || object->getObjectType() == ObjectType::POLYGON_OBJECT)
			object->setIsDrag(isDrag);
	}
}

