/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 7. May 18:07:48 2011
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
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QTreeView>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QDockWidget *projExplorerGUI;
    QWidget *dockWidgetContents_15;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QTreeView *prExplorerTree;
    QDockWidget *sceneNodesGUI;
    QWidget *dockWidgetContents_14;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *sceneNodesTree;
    QDockWidget *componentsGUI;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_9;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QGroupBox *sceneNodeGUI_4;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLineEdit *position_z;
    QLineEdit *position_x;
    QLineEdit *position_y;
    QLineEdit *rotation_x;
    QLineEdit *rotation_y;
    QLineEdit *rotation_z;
    QLineEdit *scale_x;
    QLineEdit *scale_y;
    QLineEdit *scale_z;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QGroupBox *enitityGUI_4;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QLineEdit *mesh_edit;
    QLineEdit *texture_edit;
    QLabel *label_34;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QLabel *label_36;
    QGroupBox *material_4;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QGraphicsView *graphicsView_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(762, 589);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 762, 20));
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
        projExplorerGUI->setMinimumSize(QSize(82, 103));
        projExplorerGUI->setMaximumSize(QSize(5000, 5000));
        projExplorerGUI->setFeatures(QDockWidget::DockWidgetMovable);
        dockWidgetContents_15 = new QWidget();
        dockWidgetContents_15->setObjectName(QString::fromUtf8("dockWidgetContents_15"));
        horizontalLayout_3 = new QHBoxLayout(dockWidgetContents_15);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        prExplorerTree = new QTreeView(dockWidgetContents_15);
        prExplorerTree->setObjectName(QString::fromUtf8("prExplorerTree"));
        sizePolicy.setHeightForWidth(prExplorerTree->sizePolicy().hasHeightForWidth());
        prExplorerTree->setSizePolicy(sizePolicy);
        prExplorerTree->setMinimumSize(QSize(0, 0));
        prExplorerTree->setMaximumSize(QSize(65656, 76767));
        prExplorerTree->setSizeIncrement(QSize(0, 0));
        prExplorerTree->setAnimated(true);

        horizontalLayout->addWidget(prExplorerTree);


        horizontalLayout_3->addLayout(horizontalLayout);

        projExplorerGUI->setWidget(dockWidgetContents_15);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), projExplorerGUI);
        sceneNodesGUI = new QDockWidget(MainWindow);
        sceneNodesGUI->setObjectName(QString::fromUtf8("sceneNodesGUI"));
        sizePolicy.setHeightForWidth(sceneNodesGUI->sizePolicy().hasHeightForWidth());
        sceneNodesGUI->setSizePolicy(sizePolicy);
        sceneNodesGUI->setMinimumSize(QSize(82, 103));
        sceneNodesGUI->setFloating(false);
        sceneNodesGUI->setFeatures(QDockWidget::DockWidgetMovable);
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
        sceneNodesTree->header()->setVisible(false);

        horizontalLayout_2->addWidget(sceneNodesTree);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        sceneNodesGUI->setWidget(dockWidgetContents_14);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), sceneNodesGUI);
        componentsGUI = new QDockWidget(MainWindow);
        componentsGUI->setObjectName(QString::fromUtf8("componentsGUI"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(componentsGUI->sizePolicy().hasHeightForWidth());
        componentsGUI->setSizePolicy(sizePolicy1);
        componentsGUI->setMinimumSize(QSize(350, 200));
        componentsGUI->setMaximumSize(QSize(700, 700));
        componentsGUI->setFeatures(QDockWidget::DockWidgetMovable);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        sizePolicy1.setHeightForWidth(dockWidgetContents->sizePolicy().hasHeightForWidth());
        dockWidgetContents->setSizePolicy(sizePolicy1);
        gridLayout_9 = new QGridLayout(dockWidgetContents);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        scrollArea = new QScrollArea(dockWidgetContents);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setAutoFillBackground(true);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, -66, 385, 472));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        sceneNodeGUI_4 = new QGroupBox(scrollAreaWidgetContents_3);
        sceneNodeGUI_4->setObjectName(QString::fromUtf8("sceneNodeGUI_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sceneNodeGUI_4->sizePolicy().hasHeightForWidth());
        sceneNodeGUI_4->setSizePolicy(sizePolicy2);
        sceneNodeGUI_4->setLayoutDirection(Qt::LeftToRight);
        gridLayout_4 = new QGridLayout(sceneNodeGUI_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        position_z = new QLineEdit(sceneNodeGUI_4);
        position_z->setObjectName(QString::fromUtf8("position_z"));
        sizePolicy2.setHeightForWidth(position_z->sizePolicy().hasHeightForWidth());
        position_z->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(position_z, 1, 0, 1, 1);

        position_x = new QLineEdit(sceneNodeGUI_4);
        position_x->setObjectName(QString::fromUtf8("position_x"));
        sizePolicy2.setHeightForWidth(position_x->sizePolicy().hasHeightForWidth());
        position_x->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(position_x, 1, 2, 1, 1);

        position_y = new QLineEdit(sceneNodeGUI_4);
        position_y->setObjectName(QString::fromUtf8("position_y"));
        sizePolicy2.setHeightForWidth(position_y->sizePolicy().hasHeightForWidth());
        position_y->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(position_y, 1, 1, 1, 1);

        rotation_x = new QLineEdit(sceneNodeGUI_4);
        rotation_x->setObjectName(QString::fromUtf8("rotation_x"));
        sizePolicy2.setHeightForWidth(rotation_x->sizePolicy().hasHeightForWidth());
        rotation_x->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(rotation_x, 2, 2, 1, 1);

        rotation_y = new QLineEdit(sceneNodeGUI_4);
        rotation_y->setObjectName(QString::fromUtf8("rotation_y"));
        sizePolicy2.setHeightForWidth(rotation_y->sizePolicy().hasHeightForWidth());
        rotation_y->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(rotation_y, 2, 1, 1, 1);

        rotation_z = new QLineEdit(sceneNodeGUI_4);
        rotation_z->setObjectName(QString::fromUtf8("rotation_z"));
        sizePolicy2.setHeightForWidth(rotation_z->sizePolicy().hasHeightForWidth());
        rotation_z->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(rotation_z, 2, 0, 1, 1);

        scale_x = new QLineEdit(sceneNodeGUI_4);
        scale_x->setObjectName(QString::fromUtf8("scale_x"));
        sizePolicy2.setHeightForWidth(scale_x->sizePolicy().hasHeightForWidth());
        scale_x->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(scale_x, 3, 2, 1, 1);

        scale_y = new QLineEdit(sceneNodeGUI_4);
        scale_y->setObjectName(QString::fromUtf8("scale_y"));
        sizePolicy2.setHeightForWidth(scale_y->sizePolicy().hasHeightForWidth());
        scale_y->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(scale_y, 3, 1, 1, 1);

        scale_z = new QLineEdit(sceneNodeGUI_4);
        scale_z->setObjectName(QString::fromUtf8("scale_z"));
        sizePolicy2.setHeightForWidth(scale_z->sizePolicy().hasHeightForWidth());
        scale_z->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(scale_z, 3, 0, 1, 1);

        label_29 = new QLabel(sceneNodeGUI_4);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        sizePolicy.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_29, 0, 2, 1, 1);

        label_30 = new QLabel(sceneNodeGUI_4);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_3->addWidget(label_30, 0, 1, 1, 1);

        label_31 = new QLabel(sceneNodeGUI_4);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_3->addWidget(label_31, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        gridLayout->addWidget(sceneNodeGUI_4, 0, 0, 1, 1);

        enitityGUI_4 = new QGroupBox(scrollAreaWidgetContents_3);
        enitityGUI_4->setObjectName(QString::fromUtf8("enitityGUI_4"));
        sizePolicy2.setHeightForWidth(enitityGUI_4->sizePolicy().hasHeightForWidth());
        enitityGUI_4->setSizePolicy(sizePolicy2);
        enitityGUI_4->setLayoutDirection(Qt::LeftToRight);
        gridLayout_6 = new QGridLayout(enitityGUI_4);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(20);
        mesh_edit = new QLineEdit(enitityGUI_4);
        mesh_edit->setObjectName(QString::fromUtf8("mesh_edit"));
        sizePolicy2.setHeightForWidth(mesh_edit->sizePolicy().hasHeightForWidth());
        mesh_edit->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(mesh_edit, 0, 1, 1, 1);

        texture_edit = new QLineEdit(enitityGUI_4);
        texture_edit->setObjectName(QString::fromUtf8("texture_edit"));
        sizePolicy2.setHeightForWidth(texture_edit->sizePolicy().hasHeightForWidth());
        texture_edit->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(texture_edit, 1, 1, 1, 1);

        label_34 = new QLabel(enitityGUI_4);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(label_34, 0, 0, 1, 1);

        pushButton_11 = new QPushButton(enitityGUI_4);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        sizePolicy2.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(pushButton_11, 0, 2, 1, 1);

        pushButton_10 = new QPushButton(enitityGUI_4);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        sizePolicy2.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(pushButton_10, 1, 2, 1, 1);

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
        gridLayout_8 = new QGridLayout(material_4);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(50);
        graphicsView_4 = new QGraphicsView(material_4);
        graphicsView_4->setObjectName(QString::fromUtf8("graphicsView_4"));
        graphicsView_4->setEnabled(true);
        sizePolicy2.setHeightForWidth(graphicsView_4->sizePolicy().hasHeightForWidth());
        graphicsView_4->setSizePolicy(sizePolicy2);

        gridLayout_7->addWidget(graphicsView_4, 1, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);


        gridLayout->addWidget(material_4, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        scrollArea->setWidget(scrollAreaWidgetContents_3);

        gridLayout_9->addWidget(scrollArea, 0, 0, 1, 1);

        componentsGUI->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), componentsGUI);
        componentsGUI->raise();
        componentsGUI->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        projExplorerGUI->setWindowTitle(QApplication::translate("MainWindow", "Project Explorer", 0, QApplication::UnicodeUTF8));
        sceneNodeGUI_4->setTitle(QApplication::translate("MainWindow", "Scene Node", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "\320\243", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        enitityGUI_4->setTitle(QApplication::translate("MainWindow", "Entity", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("MainWindow", "Mesh:", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("MainWindow", "Pick", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("MainWindow", "Pick", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("MainWindow", "Material:", 0, QApplication::UnicodeUTF8));
        material_4->setTitle(QApplication::translate("MainWindow", "Material", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
