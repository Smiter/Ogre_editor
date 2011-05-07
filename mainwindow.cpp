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
    ogreWindow->setMouseTracking(true);
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
MainWindow* MainWindow::instance = 0;

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

 void MainWindow::updateTransform(Ogre::SceneNode* sceneNode,Ogre::Entity * entity)
 {

     ui->position_x->setText(QString::number( sceneNode->getPosition().x));
     ui->position_y->setText(QString::number(sceneNode->getPosition().y));
     ui->position_z->setText(QString::number(sceneNode->getPosition().z));
     ui->rotation_x->setText(QString::number(sceneNode->getOrientation().getYaw().valueDegrees()));
     ui->rotation_y->setText(QString::number(sceneNode->getOrientation().getPitch().valueDegrees()));
     ui->rotation_z->setText(QString::number(sceneNode->getOrientation().getRoll().valueDegrees()));
     ui->scale_x->setText(QString::number(sceneNode->getScale().x));
     ui->scale_y->setText(QString::number(sceneNode->getScale().y));
     ui->scale_z->setText(QString::number(sceneNode->getScale().z));
     ui->mesh_edit->setText(QString::fromStdString(entity->getMesh()->getName()));
     ui->texture_edit->setText(QString::fromStdString(entity->getSubEntity(0)->getMaterialName()));

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
