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
    ogreWindow->setFocusPolicy(Qt::ClickFocus);
    ui->gridLayout_9->addWidget(ogreWindow);
    this->setCentralWidget(0);
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



    connect(ui->actionTranslate, SIGNAL(triggered()), this, SLOT(ProcessToolBar()));
    connect(ui->actionRotate, SIGNAL(triggered()), this, SLOT(ProcessToolBar()));
    connect(ui->actionScale, SIGNAL(triggered()), this, SLOT(ProcessToolBar()));
    connect(ui->actionLocal, SIGNAL(triggered()), this, SLOT(ProcessToolBar()));
    connect(ui->actionGlobal, SIGNAL(triggered()), this, SLOT(ProcessToolBar()));


    ui->actionTranslate->toggle();
    ui->actionGlobal->toggle();

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

void MainWindow::ProcessToolBar()
{

   if (QObject::sender() == ui->actionTranslate)
   {
       ui->actionRotate->setChecked(false);
       ui->actionScale->setChecked(false);
       ui->actionTranslate->setChecked(true);
       if(ogreWindow->getCurrentNode())
       {
       GizmoManager::Hide(GizmoManager::getScaleGizmo());
       GizmoManager::Hide(GizmoManager::getRotateGizmo());
       GizmoManager::Show(GizmoManager::getTranslateGizmo());
       GizmoManager::SetGizmoPosition(GizmoManager::getTranslateGizmo(),ogreWindow->getCurrentNode()->getPosition());
       GizmoManager::UpdateAxisSize(GizmoManager::getTranslateGizmo(),ogreWindow->getCurrentNode(),"",0);
       if(ui->actionGlobal->isChecked())
           GizmoManager::ConvertGizmo(false,true,ogreWindow->getCurrentNode());
       if(ui->actionLocal->isChecked())
           GizmoManager::ConvertGizmo(true,false,ogreWindow->getCurrentNode());
       }
   }
   if (QObject::sender() == ui->actionRotate)
   {      
       ui->actionScale->setChecked(false);
       ui->actionTranslate->setChecked(false);
       ui->actionRotate->setChecked(true);
       if(ogreWindow->getCurrentNode())
       {
       GizmoManager::Hide(GizmoManager::getScaleGizmo());
       GizmoManager::Hide(GizmoManager::getTranslateGizmo());
       GizmoManager::Show(GizmoManager::getRotateGizmo());
       GizmoManager::SetGizmoPosition(GizmoManager::getRotateGizmo(),ogreWindow->getCurrentNode()->getPosition());
       GizmoManager::UpdateAxisSize(GizmoManager::getRotateGizmo(),ogreWindow->getCurrentNode(),"",0);
       }
   }
   if (QObject::sender() == ui->actionScale)
   {
       ui->actionRotate->setChecked(false);
       ui->actionTranslate->setChecked(false);
       ui->actionScale->setChecked(true);
       if(ogreWindow->getCurrentNode())
       {
       GizmoManager::Hide(GizmoManager::getRotateGizmo());
       GizmoManager::Hide(GizmoManager::getTranslateGizmo());
       GizmoManager::Show(GizmoManager::getScaleGizmo());
       GizmoManager::SetGizmoPosition(GizmoManager::getScaleGizmo(),ogreWindow->getCurrentNode()->getPosition());
       GizmoManager::UpdateAxisSize(GizmoManager::getScaleGizmo(),ogreWindow->getCurrentNode(),"",0);
       }
   }
   if (QObject::sender() == ui->actionLocal)
   {
        ui->actionLocal->setChecked(true);
        ui->actionGlobal->setChecked(false);
        if(ogreWindow->getCurrentNode())
        {
        GizmoManager::ConvertGizmo(true,false,ogreWindow->getCurrentNode());
        }
   }
   if (QObject::sender() == ui->actionGlobal)
   {
       ui->actionLocal->setChecked(false);
       ui->actionGlobal->setChecked(true);
       if(ogreWindow->getCurrentNode())
       {
       GizmoManager::ConvertGizmo(false,true,ogreWindow->getCurrentNode());
       }
   }
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
	  
      GizmoManager::cameraNode->setPosition(node->getPosition());
      if( ui->actionTranslate->isChecked())
      {
           GizmoManager::Show(GizmoManager::getTranslateGizmo());
           GizmoManager::SetGizmoPosition(GizmoManager::getTranslateGizmo(),node->getPosition());
           GizmoManager::UpdateAxisSize(GizmoManager::getTranslateGizmo(),node,"",0);

           if(ui->actionGlobal->isChecked())
               GizmoManager::ConvertGizmo(false,true,node);
           if(ui->actionLocal->isChecked())
               GizmoManager::ConvertGizmo(true,false,node);

      }
      if( ui->actionRotate->isChecked())
      {
           GizmoManager::Show(GizmoManager::getRotateGizmo());
           GizmoManager::SetGizmoPosition(GizmoManager::getRotateGizmo(),node->getPosition());
           GizmoManager::UpdateAxisSize(GizmoManager::getRotateGizmo(),node,"",0);
      }
      if(ui->actionScale->isChecked())
      {
           GizmoManager::Show(GizmoManager::getScaleGizmo());
           GizmoManager::SetGizmoPosition(GizmoManager::getScaleGizmo(),node->getPosition());
           GizmoManager::UpdateAxisSize(GizmoManager::getScaleGizmo(),node,"",0);
      }

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

     Ogre::Pass::TextureUnitStateIterator texIter =  mat->getTechnique(0)->getPass(0)->getTextureUnitStateIterator();
     if(texIter.hasMoreElements() )
     {
          Ogre::String str = mat->getTechnique(0)->getPass(0)->getTextureUnitState(0)->getTextureName();

          // Image Rendering
          QPixmap pix( QDir::currentPath() + "/media/materials/textures/" + QString::fromStdString(str) );
          ui->materialViwer->scene()->addPixmap (pix.scaled(ui->materialViwer->width(), ui->materialViwer->height()) );
     }
     else
         qDebug()<<"\n There is no texture in material...Check your .material file \n";
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
