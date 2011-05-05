/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 5. May 21:16:47 2011
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QDockWidget *dockOgre;
    QWidget *dockWidgetContents_13;
    QDockWidget *componentsGUI;
    QWidget *dockWidgetContents_12;
    QGroupBox *sceneNodeGUI_4;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLineEdit *lineEdit_37;
    QLineEdit *lineEdit_38;
    QLineEdit *lineEdit_39;
    QLineEdit *lineEdit_40;
    QLabel *label_32;
    QLineEdit *lineEdit_41;
    QLineEdit *lineEdit_42;
    QLineEdit *lineEdit_43;
    QLabel *label_33;
    QLineEdit *lineEdit_44;
    QLineEdit *lineEdit_45;
    QGroupBox *enitityGUI_4;
    QLabel *label_34;
    QLabel *label_35;
    QLineEdit *lineEdit_46;
    QLineEdit *lineEdit_47;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QGroupBox *material_4;
    QLabel *label_36;
    QPushButton *pushButton_12;
    QLineEdit *lineEdit_48;
    QGraphicsView *graphicsView_4;
    QScrollBar *verticalScrollBar_4;
    QDockWidget *sceneNodesGUI;
    QWidget *dockWidgetContents_14;
    QTreeView *treeView_7;
    QDockWidget *projExplorerGUI;
    QWidget *dockWidgetContents_15;
    QTreeView *prExplorerTree;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(756, 488);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 756, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        dockOgre = new QDockWidget(MainWindow);
        dockOgre->setObjectName(QString::fromUtf8("dockOgre"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockOgre->sizePolicy().hasHeightForWidth());
        dockOgre->setSizePolicy(sizePolicy);
        dockOgre->setMinimumSize(QSize(200, 200));
        dockOgre->setBaseSize(QSize(0, 0));
        dockOgre->setLayoutDirection(Qt::RightToLeft);
        dockOgre->setFeatures(QDockWidget::DockWidgetMovable);
        dockWidgetContents_13 = new QWidget();
        dockWidgetContents_13->setObjectName(QString::fromUtf8("dockWidgetContents_13"));
        dockOgre->setWidget(dockWidgetContents_13);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockOgre);
        componentsGUI = new QDockWidget(MainWindow);
        componentsGUI->setObjectName(QString::fromUtf8("componentsGUI"));
        sizePolicy.setHeightForWidth(componentsGUI->sizePolicy().hasHeightForWidth());
        componentsGUI->setSizePolicy(sizePolicy);
        componentsGUI->setMinimumSize(QSize(240, 38));
        componentsGUI->setAutoFillBackground(true);
        componentsGUI->setFeatures(QDockWidget::DockWidgetMovable);
        dockWidgetContents_12 = new QWidget();
        dockWidgetContents_12->setObjectName(QString::fromUtf8("dockWidgetContents_12"));
        dockWidgetContents_12->setLayoutDirection(Qt::RightToLeft);
        sceneNodeGUI_4 = new QGroupBox(dockWidgetContents_12);
        sceneNodeGUI_4->setObjectName(QString::fromUtf8("sceneNodeGUI_4"));
        sceneNodeGUI_4->setGeometry(QRect(0, 0, 211, 121));
        label_28 = new QLabel(sceneNodeGUI_4);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(10, 30, 41, 16));
        label_29 = new QLabel(sceneNodeGUI_4);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(80, 10, 16, 16));
        label_30 = new QLabel(sceneNodeGUI_4);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(130, 10, 16, 16));
        label_31 = new QLabel(sceneNodeGUI_4);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(180, 10, 16, 16));
        lineEdit_37 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_37->setObjectName(QString::fromUtf8("lineEdit_37"));
        lineEdit_37->setGeometry(QRect(60, 30, 41, 16));
        lineEdit_38 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_38->setObjectName(QString::fromUtf8("lineEdit_38"));
        lineEdit_38->setGeometry(QRect(110, 30, 41, 16));
        lineEdit_39 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_39->setObjectName(QString::fromUtf8("lineEdit_39"));
        lineEdit_39->setGeometry(QRect(160, 30, 41, 16));
        lineEdit_40 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_40->setObjectName(QString::fromUtf8("lineEdit_40"));
        lineEdit_40->setGeometry(QRect(110, 60, 41, 16));
        label_32 = new QLabel(sceneNodeGUI_4);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(10, 60, 41, 16));
        lineEdit_41 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_41->setObjectName(QString::fromUtf8("lineEdit_41"));
        lineEdit_41->setGeometry(QRect(160, 60, 41, 16));
        lineEdit_42 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_42->setObjectName(QString::fromUtf8("lineEdit_42"));
        lineEdit_42->setGeometry(QRect(60, 60, 41, 16));
        lineEdit_43 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_43->setObjectName(QString::fromUtf8("lineEdit_43"));
        lineEdit_43->setGeometry(QRect(110, 90, 41, 16));
        label_33 = new QLabel(sceneNodeGUI_4);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(10, 90, 41, 16));
        lineEdit_44 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_44->setObjectName(QString::fromUtf8("lineEdit_44"));
        lineEdit_44->setGeometry(QRect(160, 90, 41, 16));
        lineEdit_45 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_45->setObjectName(QString::fromUtf8("lineEdit_45"));
        lineEdit_45->setGeometry(QRect(60, 90, 41, 16));
        enitityGUI_4 = new QGroupBox(dockWidgetContents_12);
        enitityGUI_4->setObjectName(QString::fromUtf8("enitityGUI_4"));
        enitityGUI_4->setGeometry(QRect(0, 120, 211, 81));
        label_34 = new QLabel(enitityGUI_4);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(10, 30, 46, 13));
        label_35 = new QLabel(enitityGUI_4);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(10, 60, 46, 13));
        lineEdit_46 = new QLineEdit(enitityGUI_4);
        lineEdit_46->setObjectName(QString::fromUtf8("lineEdit_46"));
        lineEdit_46->setGeometry(QRect(70, 30, 91, 16));
        lineEdit_47 = new QLineEdit(enitityGUI_4);
        lineEdit_47->setObjectName(QString::fromUtf8("lineEdit_47"));
        lineEdit_47->setGeometry(QRect(70, 60, 91, 16));
        pushButton_10 = new QPushButton(enitityGUI_4);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(170, 30, 31, 16));
        pushButton_11 = new QPushButton(enitityGUI_4);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(170, 60, 31, 16));
        material_4 = new QGroupBox(dockWidgetContents_12);
        material_4->setObjectName(QString::fromUtf8("material_4"));
        material_4->setGeometry(QRect(0, 200, 211, 121));
        label_36 = new QLabel(material_4);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(10, 30, 71, 16));
        pushButton_12 = new QPushButton(material_4);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(170, 30, 31, 16));
        lineEdit_48 = new QLineEdit(material_4);
        lineEdit_48->setObjectName(QString::fromUtf8("lineEdit_48"));
        lineEdit_48->setGeometry(QRect(70, 30, 91, 16));
        graphicsView_4 = new QGraphicsView(material_4);
        graphicsView_4->setObjectName(QString::fromUtf8("graphicsView_4"));
        graphicsView_4->setGeometry(QRect(80, 50, 71, 61));
        verticalScrollBar_4 = new QScrollBar(dockWidgetContents_12);
        verticalScrollBar_4->setObjectName(QString::fromUtf8("verticalScrollBar_4"));
        verticalScrollBar_4->setGeometry(QRect(210, -10, 20, 351));
        verticalScrollBar_4->setOrientation(Qt::Vertical);
        componentsGUI->setWidget(dockWidgetContents_12);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), componentsGUI);
        sceneNodesGUI = new QDockWidget(MainWindow);
        sceneNodesGUI->setObjectName(QString::fromUtf8("sceneNodesGUI"));
        sizePolicy.setHeightForWidth(sceneNodesGUI->sizePolicy().hasHeightForWidth());
        sceneNodesGUI->setSizePolicy(sizePolicy);
        sceneNodesGUI->setMinimumSize(QSize(100, 100));
        sceneNodesGUI->setFloating(false);
        sceneNodesGUI->setFeatures(QDockWidget::DockWidgetMovable);
        sceneNodesGUI->setWindowTitle(QString::fromUtf8("Scene Nodes"));
        dockWidgetContents_14 = new QWidget();
        dockWidgetContents_14->setObjectName(QString::fromUtf8("dockWidgetContents_14"));
        treeView_7 = new QTreeView(dockWidgetContents_14);
        treeView_7->setObjectName(QString::fromUtf8("treeView_7"));
        treeView_7->setGeometry(QRect(0, 0, 381, 81));
        treeView_7->setLayoutDirection(Qt::LeftToRight);
        treeView_7->setAutoFillBackground(true);
        sceneNodesGUI->setWidget(dockWidgetContents_14);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), sceneNodesGUI);
        projExplorerGUI = new QDockWidget(MainWindow);
        projExplorerGUI->setObjectName(QString::fromUtf8("projExplorerGUI"));
        sizePolicy.setHeightForWidth(projExplorerGUI->sizePolicy().hasHeightForWidth());
        projExplorerGUI->setSizePolicy(sizePolicy);
        projExplorerGUI->setMinimumSize(QSize(100, 100));
        projExplorerGUI->setFeatures(QDockWidget::DockWidgetMovable);
        dockWidgetContents_15 = new QWidget();
        dockWidgetContents_15->setObjectName(QString::fromUtf8("dockWidgetContents_15"));
        prExplorerTree = new QTreeView(dockWidgetContents_15);
        prExplorerTree->setObjectName(QString::fromUtf8("prExplorerTree"));
        prExplorerTree->setGeometry(QRect(0, 0, 381, 81));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(prExplorerTree->sizePolicy().hasHeightForWidth());
        prExplorerTree->setSizePolicy(sizePolicy1);
        prExplorerTree->setLayoutDirection(Qt::LeftToRight);
        prExplorerTree->setAutoFillBackground(true);
        projExplorerGUI->setWidget(dockWidgetContents_15);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), projExplorerGUI);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        dockOgre->setWindowTitle(QApplication::translate("MainWindow", "Scene", 0, QApplication::UnicodeUTF8));
        componentsGUI->setWindowTitle(QApplication::translate("MainWindow", "Components", 0, QApplication::UnicodeUTF8));
        sceneNodeGUI_4->setTitle(QApplication::translate("MainWindow", "Scene Node", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "Position:", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "\320\243", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("MainWindow", "Rotation^", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("MainWindow", "Scale:", 0, QApplication::UnicodeUTF8));
        enitityGUI_4->setTitle(QApplication::translate("MainWindow", "Entity", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("MainWindow", "Mesh:", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("MainWindow", "Material:", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("MainWindow", "Pick", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("MainWindow", "Pick", 0, QApplication::UnicodeUTF8));
        material_4->setTitle(QApplication::translate("MainWindow", "Material", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("MainWindow", "Texture:", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("MainWindow", "Pick", 0, QApplication::UnicodeUTF8));
        projExplorerGUI->setWindowTitle(QApplication::translate("MainWindow", "Project Explorer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
