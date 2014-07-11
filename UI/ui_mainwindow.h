/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ListWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionPublic;
    QAction *actionPublic_As;
    QAction *actionAdd_Sprites;
    QAction *actionAbout;
    QAction *actionDelete_Sprite;
    QAction *actionSet_Background;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    ListWidget *listWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButtonCircle;
    QToolButton *toolButtonPolygon;
    QToolButton *toolButtonPaint;
    QToolButton *toolButtonChoice;
    QToolButton *toolButtonDelete;
    QToolButton *toolButtonUndo;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *sizeX;
    QLabel *label_5;
    QSpinBox *sizeY;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButtonBrowse;
    QRadioButton *radioButtonEdit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QDoubleSpinBox *scaleSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *rotateSpinBox;
    QLabel *label;
    QGroupBox *groupBox_4;
    QCheckBox *checkBoxGrid;
    QLabel *label_6;
    QSpinBox *spinBoxGridNum;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuE_dit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(969, 683);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionPublic = new QAction(MainWindow);
        actionPublic->setObjectName(QStringLiteral("actionPublic"));
        actionPublic_As = new QAction(MainWindow);
        actionPublic_As->setObjectName(QStringLiteral("actionPublic_As"));
        actionAdd_Sprites = new QAction(MainWindow);
        actionAdd_Sprites->setObjectName(QStringLiteral("actionAdd_Sprites"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionDelete_Sprite = new QAction(MainWindow);
        actionDelete_Sprite->setObjectName(QStringLiteral("actionDelete_Sprite"));
        actionSet_Background = new QAction(MainWindow);
        actionSet_Background->setObjectName(QStringLiteral("actionSet_Background"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_10 = new QHBoxLayout(centralWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(0, 0));
        lineEdit->setMaximumSize(QSize(219, 16777215));

        verticalLayout->addWidget(lineEdit);

        listWidget = new ListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMinimumSize(QSize(0, 0));
        listWidget->setMaximumSize(QSize(219, 16777215));
        listWidget->setAcceptDrops(true);
        listWidget->setLineWidth(1);
        listWidget->setDragEnabled(true);
        listWidget->setDragDropOverwriteMode(false);
        listWidget->setDragDropMode(QAbstractItemView::DragDrop);
        listWidget->setDefaultDropAction(Qt::MoveAction);
        listWidget->setIconSize(QSize(100, 100));
        listWidget->setViewMode(QListView::ListMode);

        verticalLayout->addWidget(listWidget);


        horizontalLayout_10->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMaximumSize(QSize(200, 60));
        groupBox_3->setBaseSize(QSize(0, 0));
        groupBox_3->setFlat(true);
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        toolButtonCircle = new QToolButton(groupBox_3);
        toolButtonCircle->setObjectName(QStringLiteral("toolButtonCircle"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(toolButtonCircle->sizePolicy().hasHeightForWidth());
        toolButtonCircle->setSizePolicy(sizePolicy2);
        toolButtonCircle->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/ellipse.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonCircle->setIcon(icon1);
        toolButtonCircle->setIconSize(QSize(48, 48));
        toolButtonCircle->setCheckable(true);
        toolButtonCircle->setChecked(false);
        toolButtonCircle->setAutoExclusive(true);
        toolButtonCircle->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(toolButtonCircle);

        toolButtonPolygon = new QToolButton(groupBox_3);
        toolButtonPolygon->setObjectName(QStringLiteral("toolButtonPolygon"));
        sizePolicy2.setHeightForWidth(toolButtonPolygon->sizePolicy().hasHeightForWidth());
        toolButtonPolygon->setSizePolicy(sizePolicy2);
        toolButtonPolygon->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/polygon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonPolygon->setIcon(icon2);
        toolButtonPolygon->setIconSize(QSize(48, 48));
        toolButtonPolygon->setCheckable(true);
        toolButtonPolygon->setAutoExclusive(true);

        horizontalLayout->addWidget(toolButtonPolygon);

        toolButtonPaint = new QToolButton(groupBox_3);
        toolButtonPaint->setObjectName(QStringLiteral("toolButtonPaint"));
        sizePolicy2.setHeightForWidth(toolButtonPaint->sizePolicy().hasHeightForWidth());
        toolButtonPaint->setSizePolicy(sizePolicy2);
        toolButtonPaint->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/paint.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonPaint->setIcon(icon3);
        toolButtonPaint->setIconSize(QSize(48, 48));
        toolButtonPaint->setCheckable(true);
        toolButtonPaint->setAutoExclusive(true);

        horizontalLayout->addWidget(toolButtonPaint);

        toolButtonChoice = new QToolButton(groupBox_3);
        toolButtonChoice->setObjectName(QStringLiteral("toolButtonChoice"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(toolButtonChoice->sizePolicy().hasHeightForWidth());
        toolButtonChoice->setSizePolicy(sizePolicy3);
        toolButtonChoice->setMinimumSize(QSize(0, 0));
        toolButtonChoice->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/choice.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonChoice->setIcon(icon4);
        toolButtonChoice->setIconSize(QSize(32, 32));
        toolButtonChoice->setCheckable(true);
        toolButtonChoice->setAutoExclusive(true);

        horizontalLayout->addWidget(toolButtonChoice);


        horizontalLayout_2->addWidget(groupBox_3);

        toolButtonDelete = new QToolButton(centralWidget);
        toolButtonDelete->setObjectName(QStringLiteral("toolButtonDelete"));
        sizePolicy2.setHeightForWidth(toolButtonDelete->sizePolicy().hasHeightForWidth());
        toolButtonDelete->setSizePolicy(sizePolicy2);
        toolButtonDelete->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonDelete->setIcon(icon5);
        toolButtonDelete->setIconSize(QSize(38, 38));
        toolButtonDelete->setCheckable(false);
        toolButtonDelete->setAutoExclusive(false);

        horizontalLayout_2->addWidget(toolButtonDelete);

        toolButtonUndo = new QToolButton(centralWidget);
        toolButtonUndo->setObjectName(QStringLiteral("toolButtonUndo"));
        toolButtonUndo->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonUndo->setIcon(icon6);
        toolButtonUndo->setIconSize(QSize(38, 38));
        toolButtonUndo->setCheckable(false);
        toolButtonUndo->setAutoExclusive(false);

        horizontalLayout_2->addWidget(toolButtonUndo);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        sizeX = new QSpinBox(centralWidget);
        sizeX->setObjectName(QStringLiteral("sizeX"));
        sizeX->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sizeX->setMinimum(480);
        sizeX->setMaximum(4096);
        sizeX->setValue(480);

        horizontalLayout_2->addWidget(sizeX);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        sizeY = new QSpinBox(centralWidget);
        sizeY->setObjectName(QStringLiteral("sizeY"));
        sizeY->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sizeY->setMinimum(320);
        sizeY->setMaximum(4096);

        horizontalLayout_2->addWidget(sizeY);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(3, 2);

        verticalLayout_3->addLayout(horizontalLayout_2);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 574, 536));
        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_3->addWidget(scrollArea);


        horizontalLayout_10->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 0));
        groupBox_2->setMaximumSize(QSize(168, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        radioButtonBrowse = new QRadioButton(groupBox_2);
        radioButtonBrowse->setObjectName(QStringLiteral("radioButtonBrowse"));

        verticalLayout_2->addWidget(radioButtonBrowse);

        radioButtonEdit = new QRadioButton(groupBox_2);
        radioButtonEdit->setObjectName(QStringLiteral("radioButtonEdit"));

        verticalLayout_2->addWidget(radioButtonEdit);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(168, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scaleSpinBox = new QDoubleSpinBox(groupBox);
        scaleSpinBox->setObjectName(QStringLiteral("scaleSpinBox"));
        scaleSpinBox->setMaximum(99);
        scaleSpinBox->setSingleStep(0.2);
        scaleSpinBox->setValue(1);

        gridLayout->addWidget(scaleSpinBox, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        rotateSpinBox = new QDoubleSpinBox(groupBox);
        rotateSpinBox->setObjectName(QStringLiteral("rotateSpinBox"));
        rotateSpinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        rotateSpinBox->setMinimum(-360);
        rotateSpinBox->setMaximum(360);
        rotateSpinBox->setSingleStep(5);

        gridLayout->addWidget(rotateSpinBox, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        checkBoxGrid = new QCheckBox(groupBox_4);
        checkBoxGrid->setObjectName(QStringLiteral("checkBoxGrid"));
        checkBoxGrid->setGeometry(QRect(10, 20, 71, 16));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 50, 51, 21));
        spinBoxGridNum = new QSpinBox(groupBox_4);
        spinBoxGridNum->setObjectName(QStringLiteral("spinBoxGridNum"));
        spinBoxGridNum->setGeometry(QRect(70, 50, 42, 22));
        spinBoxGridNum->setValue(10);

        verticalLayout_4->addWidget(groupBox_4);


        horizontalLayout_10->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 969, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuE_dit = new QMenu(menuBar);
        menuE_dit->setObjectName(QStringLiteral("menuE_dit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuE_dit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionPublic);
        menuFile->addAction(actionPublic_As);
        menuE_dit->addAction(actionAdd_Sprites);
        menuE_dit->addAction(actionDelete_Sprite);
        menuE_dit->addSeparator();
        menuE_dit->addAction(actionSet_Background);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_STATUSTIP
        MainWindow->setStatusTip(QApplication::translate("MainWindow", "Ready", 0));
#endif // QT_NO_STATUSTIP
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
#ifndef QT_NO_STATUSTIP
        actionNew->setStatusTip(QApplication::translate("MainWindow", "create new project", 0));
#endif // QT_NO_STATUSTIP
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
#ifndef QT_NO_STATUSTIP
        actionOpen->setStatusTip(QApplication::translate("MainWindow", "open already exist project", 0));
#endif // QT_NO_STATUSTIP
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
#ifndef QT_NO_STATUSTIP
        actionSave->setStatusTip(QApplication::translate("MainWindow", "save project", 0));
#endif // QT_NO_STATUSTIP
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", 0));
#ifndef QT_NO_STATUSTIP
        actionSave_As->setStatusTip(QApplication::translate("MainWindow", "save project as ...", 0));
#endif // QT_NO_STATUSTIP
        actionPublic->setText(QApplication::translate("MainWindow", "Public", 0));
#ifndef QT_NO_STATUSTIP
        actionPublic->setStatusTip(QApplication::translate("MainWindow", "public tollgate scene data", 0));
#endif // QT_NO_STATUSTIP
        actionPublic_As->setText(QApplication::translate("MainWindow", "Public As", 0));
#ifndef QT_NO_STATUSTIP
        actionPublic_As->setStatusTip(QApplication::translate("MainWindow", "public tollgate scene data as ...", 0));
#endif // QT_NO_STATUSTIP
        actionAdd_Sprites->setText(QApplication::translate("MainWindow", "Add Sprites", 0));
#ifndef QT_NO_STATUSTIP
        actionAdd_Sprites->setStatusTip(QApplication::translate("MainWindow", "add tollgate elements(sprite)", 0));
#endif // QT_NO_STATUSTIP
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionDelete_Sprite->setText(QApplication::translate("MainWindow", "Delete Sprite", 0));
        actionSet_Background->setText(QApplication::translate("MainWindow", "Set Background", 0));
#ifndef QT_NO_STATUSTIP
        actionSet_Background->setStatusTip(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\234\272\346\231\257\347\232\204\350\203\214\346\231\257", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        lineEdit->setStatusTip(QApplication::translate("MainWindow", "\345\234\250\345\210\227\350\241\250\344\270\255\346\220\234\347\264\242\346\214\207\345\256\232\347\232\204\347\262\276\347\201\265\347\261\273\345\236\213", 0));
#endif // QT_NO_STATUSTIP
        groupBox_3->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        toolButtonCircle->setToolTip(QApplication::translate("MainWindow", "\345\234\206\345\275\242\347\274\226\350\276\221", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        toolButtonCircle->setStatusTip(QApplication::translate("MainWindow", "\345\234\250\345\234\272\346\231\257\344\270\255\345\210\233\345\273\272\344\270\200\344\270\252\345\234\206", 0));
#endif // QT_NO_STATUSTIP
        toolButtonCircle->setText(QApplication::translate("MainWindow", "...", 0));
#ifndef QT_NO_TOOLTIP
        toolButtonPolygon->setToolTip(QApplication::translate("MainWindow", "\345\244\232\350\276\271\345\275\242\347\274\226\350\276\221", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        toolButtonPolygon->setStatusTip(QApplication::translate("MainWindow", "\345\234\250\345\234\272\346\231\257\344\270\255\345\210\233\345\273\272\344\270\200\344\270\252\345\244\232\350\276\271\345\275\242", 0));
#endif // QT_NO_STATUSTIP
        toolButtonPolygon->setText(QApplication::translate("MainWindow", "...", 0));
#ifndef QT_NO_TOOLTIP
        toolButtonPaint->setToolTip(QApplication::translate("MainWindow", "\347\262\276\347\201\265\347\274\226\350\276\221", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        toolButtonPaint->setStatusTip(QApplication::translate("MainWindow", "\345\234\250\345\234\272\346\231\257\344\270\255\345\257\271\345\210\227\350\241\250\346\241\206\351\200\211\344\270\255\347\232\204\347\262\276\347\201\265\350\277\233\350\241\214\347\274\226\350\276\221", 0));
#endif // QT_NO_STATUSTIP
        toolButtonPaint->setText(QApplication::translate("MainWindow", "...", 0));
#ifndef QT_NO_TOOLTIP
        toolButtonChoice->setToolTip(QApplication::translate("MainWindow", "\351\200\211\345\217\226\347\262\276\347\201\265", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        toolButtonChoice->setStatusTip(QApplication::translate("MainWindow", "\345\257\271\345\234\272\346\231\257\344\270\255\351\200\211\344\270\255\347\232\204\347\262\276\347\201\265\350\277\233\350\241\214\346\213\226\346\213\275\343\200\201\350\260\203\346\225\264\347\255\211\346\223\215\344\275\234", 0));
#endif // QT_NO_STATUSTIP
        toolButtonChoice->setText(QApplication::translate("MainWindow", "...", 0));
#ifndef QT_NO_TOOLTIP
        toolButtonDelete->setToolTip(QApplication::translate("MainWindow", "\345\210\240\351\231\244", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        toolButtonDelete->setStatusTip(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\234\272\346\231\257\344\270\255\350\242\253\351\200\211\344\270\255\347\232\204\345\205\203\347\264\240", 0));
#endif // QT_NO_STATUSTIP
        toolButtonDelete->setText(QApplication::translate("MainWindow", "...", 0));
#ifndef QT_NO_TOOLTIP
        toolButtonUndo->setToolTip(QApplication::translate("MainWindow", "\346\222\244\351\224\200", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        toolButtonUndo->setStatusTip(QApplication::translate("MainWindow", "\346\222\244\351\224\200\344\270\212\344\270\200\346\254\241\347\274\226\350\276\221\346\223\215\344\275\234", 0));
#endif // QT_NO_STATUSTIP
        toolButtonUndo->setText(QApplication::translate("MainWindow", "...", 0));
        label_3->setText(QApplication::translate("MainWindow", "\345\210\206\350\276\250\347\216\207\350\256\276\347\275\256:", 0));
        label_4->setText(QApplication::translate("MainWindow", "X", 0));
        label_5->setText(QApplication::translate("MainWindow", "Y", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\250\241\345\274\217\351\200\211\346\213\251", 0));
#ifndef QT_NO_STATUSTIP
        radioButtonBrowse->setStatusTip(QApplication::translate("MainWindow", "\351\200\211\344\270\255\350\277\233\345\205\245\346\265\217\350\247\210\346\250\241\345\274\217\346\265\217\350\247\210\345\234\272\346\231\257", 0));
#endif // QT_NO_STATUSTIP
        radioButtonBrowse->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210\346\250\241\345\274\217", 0));
#ifndef QT_NO_STATUSTIP
        radioButtonEdit->setStatusTip(QApplication::translate("MainWindow", "\351\200\211\344\270\255\350\277\233\345\205\245\347\274\226\350\276\221\346\250\241\345\274\217\347\274\226\350\276\221\345\234\272\346\231\257", 0));
#endif // QT_NO_STATUSTIP
        radioButtonEdit->setText(QApplication::translate("MainWindow", "\347\274\226\350\276\221\346\250\241\345\274\217", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Attribute", 0));
#ifndef QT_NO_TOOLTIP
        scaleSpinBox->setToolTip(QApplication::translate("MainWindow", "\350\256\276\347\275\256\351\200\211\344\270\255\347\232\204\347\262\276\347\201\265\347\274\251\346\224\276\346\257\224", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("MainWindow", "Scale", 0));
#ifndef QT_NO_TOOLTIP
        rotateSpinBox->setToolTip(QApplication::translate("MainWindow", "\350\256\276\347\275\256\351\200\211\344\270\255\347\232\204\347\262\276\347\201\265\346\227\213\350\275\254\350\247\222\345\272\246", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "Rotate:", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\351\200\211\351\241\271\350\256\276\347\275\256", 0));
        checkBoxGrid->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\347\275\221\346\240\274", 0));
        label_6->setText(QApplication::translate("MainWindow", "\347\275\221\346\240\274\346\225\260\357\274\232", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "F&ile", 0));
        menuE_dit->setTitle(QApplication::translate("MainWindow", "E&dit", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
