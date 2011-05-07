#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>
#include <QTreeWidgetItem>

//#include <OgreSceneNode.h>
//#include <OgreSceneManager.h>

MainWindow * MainWindow::instance = 0;
int MainWindow::objectsCount = 0;

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),  ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ogreWindow = new OgreWidget();

    QTabWidget *tab = new QTabWidget;
    QWidget *wi = new QWidget;
    tab->addTab(ogreWindow,"Scene");
    tab->addTab(wi,"Game");
    this->setCentralWidget(tab);

    initProjectExplorer();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initProjectExplorer()
{
    QFileSystemModel *fileSystemModel = new QFileSystemModel();
    fileSystemModel->setRootPath(QDir::currentPath());

    QStringList filters;
    filters.append("*.jpg");
    filters.append("*.png");
    filters.append("*.mesh");
    filters.append("*.material");
    fileSystemModel->setNameFilters(filters);
    fileSystemModel->setNameFilterDisables(false);

    ui->prExplorerTree->setModel(fileSystemModel);
    ui->prExplorerTree->setColumnHidden(1, true);
    ui->prExplorerTree->setColumnHidden(2, true);
    ui->prExplorerTree->setColumnHidden(3, true);

    ui->prExplorerTree->setRootIndex(fileSystemModel->index(QDir::currentPath()));

    ui->prExplorerTree->show();
}

void MainWindow::createRobot(Ogre::Vector3 pos)
{
    objectsCount++;

    Ogre::Entity * myEntity =
            ogreWindow->getSceneManager()->createEntity("robot" +
                           QString::number(objectsCount).toStdString(),
                                                            "robot.mesh");
    Ogre::SceneNode * mynode =
            ogreWindow->getSceneManager()->getRootSceneNode()->createChildSceneNode("robot" +
                                       QString::number(objectsCount).toStdString());

    mynode->attachObject( myEntity );
    myEntity->setMaterialName("RobotMaterial");
    mynode->setPosition(pos);
    mynode->scale(1.1, 1.1, 1.1);

    QStringList lst;
    lst << QString::fromStdString(mynode->getName());
    QTreeWidgetItem* pItem = new QTreeWidgetItem(lst, 0);

    ui->sceneNodesTree->addTopLevelItem(pItem);

}

