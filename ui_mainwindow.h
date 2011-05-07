/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 7. May 15:53:41 2011
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
#include <QtGui/QStatusBar>
#include <QtGui/QTreeView>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QDockWidget *componentsGUI;
    QWidget *dockWidgetContents_12;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QGroupBox *sceneNodeGUI_4;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_42;
    QLineEdit *lineEdit_45;
    QLineEdit *lineEdit_39;
    QLineEdit *lineEdit_37;
    QLineEdit *lineEdit_40;
    QLineEdit *lineEdit_44;
    QLineEdit *lineEdit_41;
    QLineEdit *lineEdit_38;
    QLineEdit *lineEdit_43;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QGroupBox *material_4;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_12;
    QLineEdit *lineEdit_48;
    QLabel *label_35;
    QGraphicsView *graphicsView_4;
    QGroupBox *enitityGUI_4;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QLineEdit *lineEdit_46;
    QLabel *label_34;
    QLineEdit *lineEdit_47;
    QLabel *label_36;
    QDockWidget *sceneNodesGUI;
    QWidget *dockWidgetContents_14;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *sceneNodesTree;
    QDockWidget *projExplorerGUI;
    QWidget *dockWidgetContents_15;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QTreeView *prExplorerTree;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(602, 557);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 602, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        componentsGUI = new QDockWidget(MainWindow);
        componentsGUI->setObjectName(QString::fromUtf8("componentsGUI"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(componentsGUI->sizePolicy().hasHeightForWidth());
        componentsGUI->setSizePolicy(sizePolicy);
        componentsGUI->setMinimumSize(QSize(330, 402));
        componentsGUI->setLayoutDirection(Qt::LeftToRight);
        componentsGUI->setAutoFillBackground(true);
        componentsGUI->setFeatures(QDockWidget::DockWidgetMovable);
        dockWidgetContents_12 = new QWidget();
        dockWidgetContents_12->setObjectName(QString::fromUtf8("dockWidgetContents_12"));
        dockWidgetContents_12->setLayoutDirection(Qt::RightToLeft);
        gridLayout_2 = new QGridLayout(dockWidgetContents_12);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        sceneNodeGUI_4 = new QGroupBox(dockWidgetContents_12);
        sceneNodeGUI_4->setObjectName(QString::fromUtf8("sceneNodeGUI_4"));
        gridLayout_4 = new QGridLayout(sceneNodeGUI_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lineEdit_42 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_42->setObjectName(QString::fromUtf8("lineEdit_42"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_42->sizePolicy().hasHeightForWidth());
        lineEdit_42->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(lineEdit_42, 1, 0, 1, 1);

        lineEdit_45 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_45->setObjectName(QString::fromUtf8("lineEdit_45"));
        sizePolicy1.setHeightForWidth(lineEdit_45->sizePolicy().hasHeightForWidth());
        lineEdit_45->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(lineEdit_45, 1, 2, 1, 1);

        lineEdit_39 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_39->setObjectName(QString::fromUtf8("lineEdit_39"));
        sizePolicy1.setHeightForWidth(lineEdit_39->sizePolicy().hasHeightForWidth());
        lineEdit_39->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(lineEdit_39, 1, 1, 1, 1);

        lineEdit_37 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_37->setObjectName(QString::fromUtf8("lineEdit_37"));
        sizePolicy1.setHeightForWidth(lineEdit_37->sizePolicy().hasHeightForWidth());
        lineEdit_37->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(lineEdit_37, 2, 2, 1, 1);

        lineEdit_40 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_40->setObjectName(QString::fromUtf8("lineEdit_40"));
        sizePolicy1.setHeightForWidth(lineEdit_40->sizePolicy().hasHeightForWidth());
        lineEdit_40->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(lineEdit_40, 2, 1, 1, 1);

        lineEdit_44 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_44->setObjectName(QString::fromUtf8("lineEdit_44"));
        sizePolicy1.setHeightForWidth(lineEdit_44->sizePolicy().hasHeightForWidth());
        lineEdit_44->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(lineEdit_44, 2, 0, 1, 1);

        lineEdit_41 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_41->setObjectName(QString::fromUtf8("lineEdit_41"));
        sizePolicy1.setHeightForWidth(lineEdit_41->sizePolicy().hasHeightForWidth());
        lineEdit_41->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(lineEdit_41, 3, 2, 1, 1);

        lineEdit_38 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_38->setObjectName(QString::fromUtf8("lineEdit_38"));
        sizePolicy1.setHeightForWidth(lineEdit_38->sizePolicy().hasHeightForWidth());
        lineEdit_38->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(lineEdit_38, 3, 1, 1, 1);

        lineEdit_43 = new QLineEdit(sceneNodeGUI_4);
        lineEdit_43->setObjectName(QString::fromUtf8("lineEdit_43"));
        sizePolicy1.setHeightForWidth(lineEdit_43->sizePolicy().hasHeightForWidth());
        lineEdit_43->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(lineEdit_43, 3, 0, 1, 1);

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

        material_4 = new QGroupBox(dockWidgetContents_12);
        material_4->setObjectName(QString::fromUtf8("material_4"));
        gridLayout_8 = new QGridLayout(material_4);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(50);
        pushButton_12 = new QPushButton(material_4);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        gridLayout_7->addWidget(pushButton_12, 1, 0, 1, 1);

        lineEdit_48 = new QLineEdit(material_4);
        lineEdit_48->setObjectName(QString::fromUtf8("lineEdit_48"));
        sizePolicy1.setHeightForWidth(lineEdit_48->sizePolicy().hasHeightForWidth());
        lineEdit_48->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(lineEdit_48, 1, 1, 1, 1);

        label_35 = new QLabel(material_4);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy2);

        gridLayout_7->addWidget(label_35, 1, 2, 1, 1);

        graphicsView_4 = new QGraphicsView(material_4);
        graphicsView_4->setObjectName(QString::fromUtf8("graphicsView_4"));
        sizePolicy.setHeightForWidth(graphicsView_4->sizePolicy().hasHeightForWidth());
        graphicsView_4->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(graphicsView_4, 2, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);


        gridLayout->addWidget(material_4, 2, 0, 1, 1);

        enitityGUI_4 = new QGroupBox(dockWidgetContents_12);
        enitityGUI_4->setObjectName(QString::fromUtf8("enitityGUI_4"));
        gridLayout_6 = new QGridLayout(enitityGUI_4);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(20);
        pushButton_11 = new QPushButton(enitityGUI_4);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        sizePolicy1.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(pushButton_11, 0, 0, 1, 1);

        pushButton_10 = new QPushButton(enitityGUI_4);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(pushButton_10, 1, 0, 1, 1);

        lineEdit_46 = new QLineEdit(enitityGUI_4);
        lineEdit_46->setObjectName(QString::fromUtf8("lineEdit_46"));
        sizePolicy1.setHeightForWidth(lineEdit_46->sizePolicy().hasHeightForWidth());
        lineEdit_46->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(lineEdit_46, 0, 1, 1, 1);

        label_34 = new QLabel(enitityGUI_4);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        sizePolicy2.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(label_34, 0, 2, 1, 1);

        lineEdit_47 = new QLineEdit(enitityGUI_4);
        lineEdit_47->setObjectName(QString::fromUtf8("lineEdit_47"));
        sizePolicy1.setHeightForWidth(lineEdit_47->sizePolicy().hasHeightForWidth());
        lineEdit_47->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(lineEdit_47, 1, 1, 1, 1);

        label_36 = new QLabel(enitityGUI_4);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        sizePolicy2.setHeightForWidth(label_36->sizePolicy().hasHeightForWidth());
        label_36->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(label_36, 1, 2, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);


        gridLayout->addWidget(enitityGUI_4, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        componentsGUI->setWidget(dockWidgetContents_12);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), componentsGUI);
        sceneNodesGUI = new QDockWidget(MainWindow);
        sceneNodesGUI->setObjectName(QString::fromUtf8("sceneNodesGUI"));
        sizePolicy.setHeightForWidth(sceneNodesGUI->sizePolicy().hasHeightForWidth());
        sceneNodesGUI->setSizePolicy(sizePolicy);
        sceneNodesGUI->setMinimumSize(QSize(91, 113));
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
        projExplorerGUI = new QDockWidget(MainWindow);
        projExplorerGUI->setObjectName(QString::fromUtf8("projExplorerGUI"));
        sizePolicy.setHeightForWidth(projExplorerGUI->sizePolicy().hasHeightForWidth());
        projExplorerGUI->setSizePolicy(sizePolicy);
        projExplorerGUI->setMinimumSize(QSize(91, 113));
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

        horizontalLayout->addWidget(prExplorerTree);


        horizontalLayout_3->addLayout(horizontalLayout);

        projExplorerGUI->setWidget(dockWidgetContents_15);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), projExplorerGUI);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        componentsGUI->setWindowTitle(QApplication::translate("MainWindow", "Components", 0, QApplication::UnicodeUTF8));
        sceneNodeGUI_4->setTitle(QApplication::translate("MainWindow", "Scene Node", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "\320\243", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        material_4->setTitle(QApplication::translate("MainWindow", "Material", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("MainWindow", "Pick", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("MainWindow", "Material:", 0, QApplication::UnicodeUTF8));
        enitityGUI_4->setTitle(QApplication::translate("MainWindow", "Entity", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("MainWindow", "Pick", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("MainWindow", "Pick", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("MainWindow", "Mesh:", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("MainWindow", "Texture:", 0, QApplication::UnicodeUTF8));
        projExplorerGUI->setWindowTitle(QApplication::translate("MainWindow", "Project Explorer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
