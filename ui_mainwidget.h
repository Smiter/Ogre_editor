/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created: Thu 5. May 09:32:54 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

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
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QDockWidget *componentsGUI;
    QWidget *dockWidgetContents;
    QGroupBox *sceneNodeGUI;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLabel *label_6;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QGroupBox *enitityGUI;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *material;
    QLabel *label_10;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_12;
    QGraphicsView *graphicsView;
    QScrollBar *verticalScrollBar;
    QDockWidget *sceneNodesGUI;
    QWidget *dockWidgetContents_2;
    QTreeView *treeView;
    QDockWidget *projExplorerGUI;
    QWidget *dockWidgetContents_3;
    QTreeView *treeView_2;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(647, 391);
        componentsGUI = new QDockWidget(MainWidget);
        componentsGUI->setObjectName(QString::fromUtf8("componentsGUI"));
        componentsGUI->setGeometry(QRect(410, 0, 231, 401));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        sceneNodeGUI = new QGroupBox(dockWidgetContents);
        sceneNodeGUI->setObjectName(QString::fromUtf8("sceneNodeGUI"));
        sceneNodeGUI->setGeometry(QRect(0, 0, 211, 121));
        label = new QLabel(sceneNodeGUI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 41, 16));
        label_2 = new QLabel(sceneNodeGUI);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 10, 16, 16));
        label_3 = new QLabel(sceneNodeGUI);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 10, 16, 16));
        label_4 = new QLabel(sceneNodeGUI);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 10, 16, 16));
        lineEdit = new QLineEdit(sceneNodeGUI);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 30, 41, 16));
        lineEdit_2 = new QLineEdit(sceneNodeGUI);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 30, 41, 16));
        lineEdit_3 = new QLineEdit(sceneNodeGUI);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(160, 30, 41, 16));
        lineEdit_4 = new QLineEdit(sceneNodeGUI);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(110, 60, 41, 16));
        label_5 = new QLabel(sceneNodeGUI);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 60, 41, 16));
        lineEdit_5 = new QLineEdit(sceneNodeGUI);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(160, 60, 41, 16));
        lineEdit_6 = new QLineEdit(sceneNodeGUI);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(60, 60, 41, 16));
        lineEdit_7 = new QLineEdit(sceneNodeGUI);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(110, 90, 41, 16));
        label_6 = new QLabel(sceneNodeGUI);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 90, 41, 16));
        lineEdit_8 = new QLineEdit(sceneNodeGUI);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(160, 90, 41, 16));
        lineEdit_9 = new QLineEdit(sceneNodeGUI);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(60, 90, 41, 16));
        enitityGUI = new QGroupBox(dockWidgetContents);
        enitityGUI->setObjectName(QString::fromUtf8("enitityGUI"));
        enitityGUI->setGeometry(QRect(0, 120, 211, 81));
        label_7 = new QLabel(enitityGUI);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 30, 46, 13));
        label_8 = new QLabel(enitityGUI);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 60, 46, 13));
        lineEdit_10 = new QLineEdit(enitityGUI);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(70, 30, 91, 16));
        lineEdit_11 = new QLineEdit(enitityGUI);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(70, 60, 91, 16));
        pushButton = new QPushButton(enitityGUI);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 30, 31, 16));
        pushButton_2 = new QPushButton(enitityGUI);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 60, 31, 16));
        material = new QGroupBox(dockWidgetContents);
        material->setObjectName(QString::fromUtf8("material"));
        material->setGeometry(QRect(0, 200, 211, 121));
        label_10 = new QLabel(material);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 30, 71, 16));
        pushButton_3 = new QPushButton(material);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 30, 31, 16));
        lineEdit_12 = new QLineEdit(material);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(70, 30, 91, 16));
        graphicsView = new QGraphicsView(material);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(80, 50, 71, 61));
        verticalScrollBar = new QScrollBar(dockWidgetContents);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(210, 9, 20, 351));
        verticalScrollBar->setOrientation(Qt::Vertical);
        componentsGUI->setWidget(dockWidgetContents);
        sceneNodesGUI = new QDockWidget(MainWidget);
        sceneNodesGUI->setObjectName(QString::fromUtf8("sceneNodesGUI"));
        sceneNodesGUI->setGeometry(QRect(10, 310, 201, 80));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        treeView = new QTreeView(dockWidgetContents_2);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(0, 0, 211, 51));
        sceneNodesGUI->setWidget(dockWidgetContents_2);
        projExplorerGUI = new QDockWidget(MainWidget);
        projExplorerGUI->setObjectName(QString::fromUtf8("projExplorerGUI"));
        projExplorerGUI->setGeometry(QRect(220, 310, 191, 80));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        treeView_2 = new QTreeView(dockWidgetContents_3);
        treeView_2->setObjectName(QString::fromUtf8("treeView_2"));
        treeView_2->setGeometry(QRect(0, 0, 191, 51));
        projExplorerGUI->setWidget(dockWidgetContents_3);

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "Pigmy 3D", 0, QApplication::UnicodeUTF8));
        componentsGUI->setWindowTitle(QApplication::translate("MainWidget", "Components", 0, QApplication::UnicodeUTF8));
        sceneNodeGUI->setTitle(QApplication::translate("MainWidget", "Scene Node", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWidget", "Position:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWidget", "X", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWidget", "\320\243", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWidget", "Z", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWidget", "Rotation^", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWidget", "Scale:", 0, QApplication::UnicodeUTF8));
        enitityGUI->setTitle(QApplication::translate("MainWidget", "Entity", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWidget", "Mesh:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWidget", "Material:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWidget", "Pick", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWidget", "Pick", 0, QApplication::UnicodeUTF8));
        material->setTitle(QApplication::translate("MainWidget", "Material", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWidget", "Texture:", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWidget", "Pick", 0, QApplication::UnicodeUTF8));
        sceneNodesGUI->setWindowTitle(QApplication::translate("MainWidget", "Scene Nodes", 0, QApplication::UnicodeUTF8));
        projExplorerGUI->setWindowTitle(QApplication::translate("MainWidget", "Project Explorer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
