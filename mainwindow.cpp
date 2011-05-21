#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTreeWidgetItemIterator>
#include <QFileDialog>

#include <OgreMaterial.h>

MainWindow * MainWindow::instance = 0;

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),  ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ogreWindow = new OgreWidget(ui->dockWidgetContents_2);
    ogreWindow->setMouseTracking(true);
    ui->gridLayout_9->addWidget(ogreWindow);

    initProjectExplorer();

    this->setCentralWidget(0);
    this->addDockWidget(static_cast<Qt::DockWidgetArea>(2), ui->sceneNodesGUI);
    this->addDockWidget(static_cast<Qt::DockWidgetArea>(1), ui->projExplorerGUI);

    // Slot connections
    QObject::connect(ui->sceneNodesTree, SIGNAL(itemSelectionChanged()),
            this,    SLOT(OnSceneNodeClicked()) );

    QObject::connect(ui->position_x, SIGNAL(textChanged(const QString &)), this, SLOT(OnPositionChanged(const QString &)) );
    QObject::connect(ui->position_y, SIGNAL(textChanged(const QString &)), this, SLOT(OnPositionChanged(const QString &)) );
    QObject::connect(ui->position_z, SIGNAL(textChanged(const QString &)), this, SLOT(OnPositionChanged(const QString &)) );
    QObject::connect(ui->rotation_x, SIGNAL(textChanged(const QString &)), this, SLOT(OnPositionChanged(const QString &)) );
    QObject::connect(ui->rotation_y, SIGNAL(textChanged(const QString &)), this, SLOT(OnPositionChanged(const QString &)) );
    QObject::connect(ui->rotation_z, SIGNAL(textChanged(const QString &)), this, SLOT(OnPositionChanged(const QString &)) );
    QObject::connect(ui->scale_x, SIGNAL(textChanged(const QString &)), this, SLOT(OnPositionChanged(const QString &)) );
    QObject::connect(ui->scale_y, SIGNAL(textChanged(const QString &)), this, SLOT(OnPositionChanged(const QString &)) );
    QObject::connect(ui->scale_z, SIGNAL(textChanged(const QString &)), this, SLOT(OnPositionChanged(const QString &)) );


    QObject::connect(ui->materialPickButton, SIGNAL(pressed()), this, SLOT(OnMaterialButtonDown()));
    QObject::connect(ui->meshPickButton, SIGNAL(pressed()), this, SLOT(OnMeshButtonDown()));

    ////////////
    // MaterialViwer initialize
    QGraphicsScene *scn = new QGraphicsScene(ui->materialViwer);
    ui->materialViwer->setScene( scn );

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initProjectExplorer()
{
    // Project Explorer
    prExplorerTree = new ProjectExplorerTree(ui->dockWidgetContents_15);

    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(ui->projExplorerGUI->sizePolicy().hasHeightForWidth());
    sizePolicy.setHeightForWidth(prExplorerTree->sizePolicy().hasHeightForWidth());
    prExplorerTree->setSizePolicy(sizePolicy);

    ui->horizontalLayout->addWidget(prExplorerTree);

}

 void MainWindow::UpdateComponents(Ogre::SceneNode* sceneNode,Ogre::Entity * entity)
 {
     ui->position_x->clearFocus(); ui->position_y->clearFocus(); ui->position_z->clearFocus();
     ui->rotation_x->clearFocus(); ui->rotation_y->clearFocus(); ui->rotation_z->clearFocus();
     ui->scale_x->clearFocus(); ui->scale_y->clearFocus(); ui->scale_z->clearFocus();
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

void MainWindow::OnSceneNodeClicked()
{
      QTreeWidgetItem *item = ui->sceneNodesTree->selectedItems()[0];
      Ogre::SceneNode *node = ogreWindow->getSceneManager()->getSceneNode(item->data(0, Qt::UserRole).toString().toStdString());
      ogreWindow->setCurrentNode(node);

      Ogre::Entity *entity = ogreWindow->getSceneManager()->getEntity(item->data(0, Qt::UserRole).toString().toStdString());

      UpdateComponents(node, entity);
      UpdateMaterialView(entity);
}

void MainWindow::UpdateSceneNodesList(QString nodeName)
{
    QTreeWidgetItemIterator it(ui->sceneNodesTree);
       while (*it)
       {
           if ((*it)->data(0, Qt::UserRole).toString() == nodeName)
           {
               ui->sceneNodesTree->setCurrentItem((*it));
               break;
           }
          ++it;
       }
}

void MainWindow::UpdateMaterialView(Ogre::Entity *entity)
{
    // Get Texture file name
     Ogre::Material *mat = static_cast<Ogre::Material*>
             (Ogre::MaterialManager::getSingletonPtr()->getByName(entity->getSubEntity(0)->getMaterialName()).get());

     Ogre::String str = mat->getTechnique(0)->getPass(0)->getTextureUnitState(0)->getTextureName();


     // Image Rendering
     QPixmap pix( QDir::currentPath() + "/media/materials/textures/" + QString::fromStdString(str) );
     ui->materialViwer->scene()->addPixmap (pix.scaled(ui->materialViwer->width(),
                                                        ui->materialViwer->height()) );

}

void MainWindow::AddItemToSceneList(Ogre::String name)
{
    QStringList lst;
    lst << QString::fromStdString("Object");
    QTreeWidgetItem* pItem = new QTreeWidgetItem(lst, 0);
    pItem->setData(0, Qt::UserRole, QString::fromStdString(name));

    ui->sceneNodesTree->addTopLevelItem(pItem);
}

void MainWindow::OnPositionChanged(const QString & str)
{
    if (ogreWindow->getCurrentNode())
    {

if (ui->position_x->hasFocus() || ui->position_x->hasFocus()|| ui->position_y->hasFocus() || ui->position_z->hasFocus() || ui->rotation_x->hasFocus()||
        ui->rotation_y->hasFocus() || ui->rotation_z->hasFocus() || ui->scale_x->hasFocus() || ui->scale_y->hasFocus() || ui->scale_z->hasFocus())
{

   float x=ui->position_x->text().toFloat();
   float y=ui->position_y->text().toFloat();
   float z=ui->position_z->text().toFloat();
   float scalex=ui->scale_x->text().toFloat();
   float scaley=ui->scale_y->text().toFloat();
   float scalez=ui->scale_z->text().toFloat();
   float rotatex=ui->rotation_x->text().toFloat();
   float rotatey=ui->rotation_y->text().toFloat();
   float rotatez=ui->rotation_z->text().toFloat();

   qDebug()<<"str= "<<str;
   ogreWindow->getCurrentNode()->setOrientation(ogreWindow->getCurrentNode()->getOrientation().w,0,ogreWindow->getCurrentNode()->getOrientation().y,ogreWindow->getCurrentNode()->getOrientation().z);
   ogreWindow->getCurrentNode()->pitch(Ogre::Degree(rotatex));
   ogreWindow->getCurrentNode()->setOrientation(ogreWindow->getCurrentNode()->getOrientation().w,ogreWindow->getCurrentNode()->getOrientation().x,0,ogreWindow->getCurrentNode()->getOrientation().z);
   ogreWindow->getCurrentNode()->yaw(Ogre::Degree(rotatey));
   ogreWindow->getCurrentNode()->setOrientation(ogreWindow->getCurrentNode()->getOrientation().w,ogreWindow->getCurrentNode()->getOrientation().x,ogreWindow->getCurrentNode()->getOrientation().y,0);
   ogreWindow->getCurrentNode()->roll(Ogre::Degree(rotatez));
   ogreWindow->getCurrentNode()->setScale(scalex,scaley,scalez);
   ogreWindow->getCurrentNode()->setPosition(x,y,z);
   }

  }
}

void MainWindow::OnMaterialButtonDown()
{

    QString fileName = QFileInfo((QFileDialog::getOpenFileName(this, "Load Material",
                                              QDir::currentPath() + "/media",
                                              "Materials (*.material)"))).baseName();
    Ogre::SceneNode *node;
    Ogre::Entity *entity;
    if ((node = ogreWindow->getCurrentNode())  && (fileName != ""))
    {
        entity = static_cast<Ogre::Entity*>(node->getAttachedObject(node->getName()));
        entity->setMaterialName(fileName.toStdString());

        UpdateMaterialView(entity);
        ui->texture_edit->setText(fileName);
    }
}

void MainWindow::OnMeshButtonDown()
{

    QString fileName = QFileInfo((QFileDialog::getOpenFileName(this, "Load Mesh",
                                              QDir::currentPath() + "/media",
                                              "Models (*.mesh)"))).fileName();
    Ogre::SceneNode *node;
    if ((node = ogreWindow->getCurrentNode()) && (fileName != ""))
    {
        Ogre::Entity *entity = static_cast<Ogre::Entity*>(node->getAttachedObject(node->getName()));
        Ogre::String materialName = entity->getSubEntity(0)->getMaterialName();

        ogreWindow->getSceneManager()->destroyEntity(entity);

        entity = ogreWindow->getSceneManager()->createEntity(node->getName(), fileName.toStdString());
        entity->setMaterialName(materialName);

        node->attachObject( entity );

        ui->mesh_edit->setText(fileName);
    }
}
