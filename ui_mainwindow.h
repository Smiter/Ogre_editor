/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 21. May 23:13:03 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTranslate;
    QAction *actionRotate;
    QAction *actionScale;
    QAction *actionLocal;
    QAction *actionGlobal;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuCreate;
    QMenu *menuComponent;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QDockWidget *projExplorerGUI;
    QWidget *dockWidgetContents_15;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QDockWidget *sceneNodesGUI;
    QWidget *dockWidgetContents_14;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *sceneNodesTree;
    QDockWidget *componentsGUI;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QGroupBox *sceneNodeGUI_4;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLineEdit *position_y;
    QLineEdit *rotation_y;
    QLineEdit *scale_y;
    QLabel *label_30;
    QLabel *label_29;
    QLabel *label_31;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *position_x;
    QLineEdit *position_z;
    QLineEdit *rotation_x;
    QLineEdit *rotation_z;
    QLineEdit *scale_x;
    QLineEdit *scale_z;
    QGroupBox *enitityGUI_4;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QLineEdit *mesh_edit;
    QLineEdit *texture_edit;
    QLabel *label_34;
    QPushButton *meshPickButton;
    QPushButton *materialPickButton;
    QLabel *label_36;
    QGroupBox *material_4;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QGraphicsView *materialViwer;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_9;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(762, 589);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionTranslate = new QAction(MainWindow);
        actionTranslate->setObjectName(QString::fromUtf8("actionTranslate"));
        actionTranslate->setCheckable(true);
        actionTranslate->setAutoRepeat(true);
        actionTranslate->setVisible(true);
        actionTranslate->setMenuRole(QAction::TextHeuristicRole);
        actionTranslate->setSoftKeyRole(QAction::NoSoftKey);
        actionTranslate->setPriority(QAction::NormalPriority);
        actionRotate = new QAction(MainWindow);
        actionRotate->setObjectName(QString::fromUtf8("actionRotate"));
        actionRotate->setCheckable(true);
        actionScale = new QAction(MainWindow);
        actionScale->setObjectName(QString::fromUtf8("actionScale"));
        actionScale->setCheckable(true);
        actionLocal = new QAction(MainWindow);
        actionLocal->setObjectName(QString::fromUtf8("actionLocal"));
        actionLocal->setCheckable(true);
        actionGlobal = new QAction(MainWindow);
        actionGlobal->setObjectName(QString::fromUtf8("actionGlobal"));
        actionGlobal->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 762, 21));
        menubar->setDefaultUp(false);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuCreate = new QMenu(menubar);
        menuCreate->setObjectName(QString::fromUtf8("menuCreate"));
        menuComponent = new QMenu(menubar);
        menuComponent->setObjectName(QString::fromUtf8("menuComponent"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        projExplorerGUI = new QDockWidget(MainWindow);
        projExplorerGUI->setObjectName(QString::fromUtf8("projExplorerGUI"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(projExplorerGUI->sizePolicy().hasHeightForWidth());
        projExplorerGUI->setSizePolicy(sizePolicy);
        projExplorerGUI->setMinimumSize(QSize(91, 113));
        projExplorerGUI->setMaximumSize(QSize(5000, 5000));
        projExplorerGUI->setFeatures(QDockWidget::DockWidgetMovable);
        projExplorerGUI->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        projExplorerGUI->setWindowTitle(QString::fromUtf8("Project Explorer"));
        dockWidgetContents_15 = new QWidget();
        dockWidgetContents_15->setObjectName(QString::fromUtf8("dockWidgetContents_15"));
        horizontalLayout_3 = new QHBoxLayout(dockWidgetContents_15);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        horizontalLayout_3->addLayout(horizontalLayout);

        projExplorerGUI->setWidget(dockWidgetContents_15);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), projExplorerGUI);
        sceneNodesGUI = new QDockWidget(MainWindow);
        sceneNodesGUI->setObjectName(QString::fromUtf8("sceneNodesGUI"));
        sizePolicy.setHeightForWidth(sceneNodesGUI->sizePolicy().hasHeightForWidth());
        sceneNodesGUI->setSizePolicy(sizePolicy);
        sceneNodesGUI->setMinimumSize(QSize(103, 113));
        sceneNodesGUI->setFloating(false);
        sceneNodesGUI->setFeatures(QDockWidget::DockWidgetMovable);
        sceneNodesGUI->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        sceneNodesGUI->setWindowTitle(QString::fromUtf8("Scene Nodes"));
        dockWidgetContents_14 = new QWidget();
        dockWidgetContents_14->setObjectName(QString::fromUtf8("dockWidgetContents_14"));
        horizontalLayout_4 = new QHBoxLayout(dockWidgetContents_14);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sceneNodesTree = new QTreeWidget(dockWidgetContents_14);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        sceneNodesTree->setHeaderItem(__qtreewidgetitem);
        sceneNodesTree->setObjectName(QString::fromUtf8("sceneNodesTree"));
        sceneNodesTree->setDragDropOverwriteMode(false);
        sceneNodesTree->setDragDropMode(QAbstractItemView::NoDragDrop);
        sceneNodesTree->setDefaultDropAction(Qt::IgnoreAction);
        sceneNodesTree->header()->setVisible(false);

        horizontalLayout_2->addWidget(sceneNodesTree);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        sceneNodesGUI->setWidget(dockWidgetContents_14);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), sceneNodesGUI);
        componentsGUI = new QDockWidget(MainWindow);
        componentsGUI->setObjectName(QString::fromUtf8("componentsGUI"));
        sizePolicy.setHeightForWidth(componentsGUI->sizePolicy().hasHeightForWidth());
        componentsGUI->setSizePolicy(sizePolicy);
        componentsGUI->setMinimumSize(QSize(270, 270));
        componentsGUI->setMaximumSize(QSize(700, 700));
        componentsGUI->setFeatures(QDockWidget::DockWidgetMovable);
        componentsGUI->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dockWidgetContents->sizePolicy().hasHeightForWidth());
        dockWidgetContents->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(dockWidgetContents);
#ifndef Q_OS_MAC
        verticalLayout->setSpacing(6);
#endif
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(dockWidgetContents);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setAutoFillBackground(true);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, -106, 449, 375));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_3->setSizePolicy(sizePolicy2);
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(2, 0, 2, 2);
        sceneNodeGUI_4 = new QGroupBox(scrollAreaWidgetContents_3);
        sceneNodeGUI_4->setObjectName(QString::fromUtf8("sceneNodeGUI_4"));
        sizePolicy2.setHeightForWidth(sceneNodeGUI_4->sizePolicy().hasHeightForWidth());
        sceneNodeGUI_4->setSizePolicy(sizePolicy2);
        sceneNodeGUI_4->setLayoutDirection(Qt::LeftToRight);
        sceneNodeGUI_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayout_4 = new QGridLayout(sceneNodeGUI_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        position_y = new QLineEdit(sceneNodeGUI_4);
        position_y->setObjectName(QString::fromUtf8("position_y"));
        sizePolicy2.setHeightForWidth(position_y->sizePolicy().hasHeightForWidth());
        position_y->setSizePolicy(sizePolicy2);
        position_y->setStyleSheet(QString::fromUtf8("QLineEdit {	\n"
"     border: 2px solid gray;\n"
"     border-radius: 7px;\n"
"     padding: 0 8px;\n"
"     background: rgb(225, 248, 250);	\n"
"	 border-color:rgb(16, 18, 12);\n"
"\n"
" }"));

        gridLayout_3->addWidget(position_y, 1, 2, 1, 1);

        rotation_y = new QLineEdit(sceneNodeGUI_4);
        rotation_y->setObjectName(QString::fromUtf8("rotation_y"));
        sizePolicy2.setHeightForWidth(rotation_y->sizePolicy().hasHeightForWidth());
        rotation_y->setSizePolicy(sizePolicy2);
        rotation_y->setStyleSheet(QString::fromUtf8("QLineEdit {	\n"
"     border: 2px solid gray;\n"
"     border-radius: 7px;\n"
"     padding: 0 8px;\n"
"     background: rgb(225, 248, 250);	\n"
"	 border-color:rgb(16, 18, 12);\n"
"\n"
" }"));

        gridLayout_3->addWidget(rotation_y, 2, 2, 1, 1);

        scale_y = new QLineEdit(sceneNodeGUI_4);
        scale_y->setObjectName(QString::fromUtf8("scale_y"));
        sizePolicy2.setHeightForWidth(scale_y->sizePolicy().hasHeightForWidth());
        scale_y->setSizePolicy(sizePolicy2);
        scale_y->setStyleSheet(QString::fromUtf8("QLineEdit {	\n"
"     border: 2px solid gray;\n"
"     border-radius: 7px;\n"
"     padding: 0 8px;\n"
"     background: rgb(225, 248, 250);	\n"
"	 border-color:rgb(16, 18, 12);\n"
"\n"
" }"));

        gridLayout_3->addWidget(scale_y, 3, 2, 1, 1);

        label_30 = new QLabel(sceneNodeGUI_4);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        sizePolicy2.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy2);
        label_30->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_30, 0, 2, 1, 1);

        label_29 = new QLabel(sceneNodeGUI_4);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        sizePolicy2.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy2);
        label_29->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_29, 0, 1, 1, 1);

        label_31 = new QLabel(sceneNodeGUI_4);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        sizePolicy2.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy2);
        label_31->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_31, 0, 3, 1, 1);

        label = new QLabel(sceneNodeGUI_4);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(sceneNodeGUI_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(sceneNodeGUI_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_3, 3, 0, 1, 1);

        position_x = new QLineEdit(sceneNodeGUI_4);
        position_x->setObjectName(QString::fromUtf8("position_x"));
        sizePolicy2.setHeightForWidth(position_x->sizePolicy().hasHeightForWidth());
        position_x->setSizePolicy(sizePolicy2);
        position_x->setStyleSheet(QString::fromUtf8("QLineEdit {	\n"
"     border: 2px solid gray;\n"
"     border-radius: 7px;\n"
"     padding: 0 8px;\n"
"     background: rgb(225, 248, 250);	\n"
"	 border-color:rgb(16, 18, 12);\n"
"\n"
" }"));

        gridLayout_3->addWidget(position_x, 1, 1, 1, 1);

        position_z = new QLineEdit(sceneNodeGUI_4);
        position_z->setObjectName(QString::fromUtf8("position_z"));
        sizePolicy2.setHeightForWidth(position_z->sizePolicy().hasHeightForWidth());
        position_z->setSizePolicy(sizePolicy2);
        position_z->setStyleSheet(QString::fromUtf8("QLineEdit {	\n"
"     border: 2px solid gray;\n"
"     border-radius: 7px;\n"
"     padding: 0 8px;\n"
"     background: rgb(225, 248, 250);	\n"
"	 border-color:rgb(16, 18, 12);\n"
"\n"
" }"));

        gridLayout_3->addWidget(position_z, 1, 3, 1, 1);

        rotation_x = new QLineEdit(sceneNodeGUI_4);
        rotation_x->setObjectName(QString::fromUtf8("rotation_x"));
        sizePolicy2.setHeightForWidth(rotation_x->sizePolicy().hasHeightForWidth());
        rotation_x->setSizePolicy(sizePolicy2);
        rotation_x->setStyleSheet(QString::fromUtf8("QLineEdit {	\n"
"     border: 2px solid gray;\n"
"     border-radius: 7px;\n"
"     padding: 0 8px;\n"
"     background: rgb(225, 248, 250);	\n"
"	 border-color:rgb(16, 18, 12);\n"
"\n"
" }"));

        gridLayout_3->addWidget(rotation_x, 2, 1, 1, 1);

        rotation_z = new QLineEdit(sceneNodeGUI_4);
        rotation_z->setObjectName(QString::fromUtf8("rotation_z"));
        sizePolicy2.setHeightForWidth(rotation_z->sizePolicy().hasHeightForWidth());
        rotation_z->setSizePolicy(sizePolicy2);
        rotation_z->setStyleSheet(QString::fromUtf8("QLineEdit {	\n"
"     border: 2px solid gray;\n"
"     border-radius: 7px;\n"
"     padding: 0 8px;\n"
"     background: rgb(225, 248, 250);	\n"
"	 border-color:rgb(16, 18, 12);\n"
"\n"
" }"));

        gridLayout_3->addWidget(rotation_z, 2, 3, 1, 1);

        scale_x = new QLineEdit(sceneNodeGUI_4);
        scale_x->setObjectName(QString::fromUtf8("scale_x"));
        sizePolicy2.setHeightForWidth(scale_x->sizePolicy().hasHeightForWidth());
        scale_x->setSizePolicy(sizePolicy2);
        scale_x->setStyleSheet(QString::fromUtf8("QLineEdit {	\n"
"     border: 2px solid gray;\n"
"     border-radius: 7px;\n"
"     padding: 0 8px;\n"
"     background: rgb(225, 248, 250);	\n"
"	 border-color:rgb(16, 18, 12);\n"
"\n"
" }"));

        gridLayout_3->addWidget(scale_x, 3, 1, 1, 1);

        scale_z = new QLineEdit(sceneNodeGUI_4);
        scale_z->setObjectName(QString::fromUtf8("scale_z"));
        sizePolicy2.setHeightForWidth(scale_z->sizePolicy().hasHeightForWidth());
        scale_z->setSizePolicy(sizePolicy2);
        scale_z->setStyleSheet(QString::fromUtf8("QLineEdit {	\n"
"     border: 2px solid gray;\n"
"     border-radius: 7px;\n"
"     padding: 0 8px;\n"
"     background: rgb(225, 248, 250);	\n"
"	 border-color:rgb(16, 18, 12);\n"
"\n"
" }"));

        gridLayout_3->addWidget(scale_z, 3, 3, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        gridLayout->addWidget(sceneNodeGUI_4, 0, 0, 1, 1);

        enitityGUI_4 = new QGroupBox(scrollAreaWidgetContents_3);
        enitityGUI_4->setObjectName(QString::fromUtf8("enitityGUI_4"));
        sizePolicy2.setHeightForWidth(enitityGUI_4->sizePolicy().hasHeightForWidth());
        enitityGUI_4->setSizePolicy(sizePolicy2);
        enitityGUI_4->setLayoutDirection(Qt::LeftToRight);
        enitityGUI_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayout_6 = new QGridLayout(enitityGUI_4);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        mesh_edit = new QLineEdit(enitityGUI_4);
        mesh_edit->setObjectName(QString::fromUtf8("mesh_edit"));
        sizePolicy2.setHeightForWidth(mesh_edit->sizePolicy().hasHeightForWidth());
        mesh_edit->setSizePolicy(sizePolicy2);
        mesh_edit->setStyleSheet(QString::fromUtf8("QLineEdit {	\n"
"     border: 2px solid gray;\n"
"     border-radius: 7px;\n"
"     padding: 0 8px;\n"
"     background: rgb(225, 248, 250);	\n"
"	 border-color:rgb(16, 18, 12);\n"
"\n"
" }"));

        gridLayout_5->addWidget(mesh_edit, 0, 1, 1, 1);

        texture_edit = new QLineEdit(enitityGUI_4);
        texture_edit->setObjectName(QString::fromUtf8("texture_edit"));
        sizePolicy2.setHeightForWidth(texture_edit->sizePolicy().hasHeightForWidth());
        texture_edit->setSizePolicy(sizePolicy2);
        texture_edit->setStyleSheet(QString::fromUtf8("QLineEdit {	\n"
"     border: 2px solid gray;\n"
"     border-radius: 7px;\n"
"     padding: 0 8px;\n"
"     background: rgb(225, 248, 250);	\n"
"	 border-color:rgb(16, 18, 12);\n"
"\n"
" }"));

        gridLayout_5->addWidget(texture_edit, 1, 1, 1, 1);

        label_34 = new QLabel(enitityGUI_4);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        sizePolicy3.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(label_34, 0, 0, 1, 1);

        meshPickButton = new QPushButton(enitityGUI_4);
        meshPickButton->setObjectName(QString::fromUtf8("meshPickButton"));
        sizePolicy2.setHeightForWidth(meshPickButton->sizePolicy().hasHeightForWidth());
        meshPickButton->setSizePolicy(sizePolicy2);
        meshPickButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 7px;\n"
"    border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-width: 80px;   \n"
"	padding: 2 8px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
"\n"
""));

        gridLayout_5->addWidget(meshPickButton, 0, 2, 1, 1);

        materialPickButton = new QPushButton(enitityGUI_4);
        materialPickButton->setObjectName(QString::fromUtf8("materialPickButton"));
        sizePolicy2.setHeightForWidth(materialPickButton->sizePolicy().hasHeightForWidth());
        materialPickButton->setSizePolicy(sizePolicy2);
        materialPickButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 7px;\n"
"    border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-width: 80px;   \n"
"	padding: 2 8px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
"\n"
""));

        gridLayout_5->addWidget(materialPickButton, 1, 2, 1, 1);

        label_36 = new QLabel(enitityGUI_4);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        sizePolicy3.setHeightForWidth(label_36->sizePolicy().hasHeightForWidth());
        label_36->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(label_36, 1, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);


        gridLayout->addWidget(enitityGUI_4, 1, 0, 1, 1);

        material_4 = new QGroupBox(scrollAreaWidgetContents_3);
        material_4->setObjectName(QString::fromUtf8("material_4"));
        sizePolicy2.setHeightForWidth(material_4->sizePolicy().hasHeightForWidth());
        material_4->setSizePolicy(sizePolicy2);
        material_4->setLayoutDirection(Qt::LeftToRight);
        material_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayout_8 = new QGridLayout(material_4);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        materialViwer = new QGraphicsView(material_4);
        materialViwer->setObjectName(QString::fromUtf8("materialViwer"));
        materialViwer->setEnabled(true);
        sizePolicy3.setHeightForWidth(materialViwer->sizePolicy().hasHeightForWidth());
        materialViwer->setSizePolicy(sizePolicy3);
        materialViwer->setMinimumSize(QSize(100, 100));
        materialViwer->setMaximumSize(QSize(100, 100));
        materialViwer->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        materialViwer->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        materialViwer->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(materialViwer, 1, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);


        gridLayout->addWidget(material_4, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_3);

        verticalLayout->addWidget(scrollArea);

        componentsGUI->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), componentsGUI);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        sizePolicy.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy);
        dockWidget->setMinimumSize(QSize(200, 200));
        dockWidget->setFeatures(QDockWidget::DockWidgetMovable);
        dockWidget->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        dockWidgetContents_2->setAutoFillBackground(false);
        gridLayout_10 = new QGridLayout(dockWidgetContents_2);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));

        gridLayout_10->addLayout(gridLayout_9, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        sizePolicy.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy);
        toolBar->setMinimumSize(QSize(0, 60));
        toolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget->raise();
        componentsGUI->raise();

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuCreate->menuAction());
        menubar->addAction(menuComponent->menuAction());
        menubar->addAction(menuHelp->menuAction());
        toolBar->addAction(actionTranslate);
        toolBar->addAction(actionRotate);
        toolBar->addAction(actionScale);
        toolBar->addSeparator();
        toolBar->addAction(actionLocal);
        toolBar->addAction(actionGlobal);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionTranslate->setText(QApplication::translate("MainWindow", "Translate", 0, QApplication::UnicodeUTF8));
        actionRotate->setText(QApplication::translate("MainWindow", "Rotate", 0, QApplication::UnicodeUTF8));
        actionScale->setText(QApplication::translate("MainWindow", "Scale", 0, QApplication::UnicodeUTF8));
        actionLocal->setText(QApplication::translate("MainWindow", "local", 0, QApplication::UnicodeUTF8));
        actionGlobal->setText(QApplication::translate("MainWindow", "global", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuCreate->setTitle(QApplication::translate("MainWindow", "Create", 0, QApplication::UnicodeUTF8));
        menuComponent->setTitle(QApplication::translate("MainWindow", "Component", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        componentsGUI->setWindowTitle(QApplication::translate("MainWindow", "Components", 0, QApplication::UnicodeUTF8));
        sceneNodeGUI_4->setTitle(QApplication::translate("MainWindow", "Scene Node", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "\320\243", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Position", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Rotation", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Scale", 0, QApplication::UnicodeUTF8));
        enitityGUI_4->setTitle(QApplication::translate("MainWindow", "Entity", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("MainWindow", "Mesh:", 0, QApplication::UnicodeUTF8));
        meshPickButton->setText(QApplication::translate("MainWindow", "Pick", 0, QApplication::UnicodeUTF8));
        materialPickButton->setText(QApplication::translate("MainWindow", "Pick", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("MainWindow", "Material:", 0, QApplication::UnicodeUTF8));
        material_4->setTitle(QApplication::translate("MainWindow", "Material", 0, QApplication::UnicodeUTF8));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "Scene", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
