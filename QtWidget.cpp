#include "QtWidget.h"
#include "mainwindow.h"

#include "Engine/GameObject.h"
#include "Engine/MeshRenderer.h"

OgreWidget::OgreWidget( QWidget *parent ): QGLWidget( parent ), mOgreWindow(NULL), counter(0)
{
  init( "plugins.cfg", "ogre.cfg", "ogre.log" );  
  setAcceptDrops(true);
}

void OgreWidget::init( std::string plugins_file,  std::string ogre_cfg_file, std::string ogre_log )
{
  mOgreRoot = new Ogre::Root( plugins_file, ogre_cfg_file, ogre_log );
  Ogre::RenderSystemList renderers = mOgreRoot->getAvailableRenderers();
  assert( !renderers.empty() );
  Ogre::RenderSystem *renderSystem = chooseRenderer(& renderers );
  assert( renderSystem );
  mOgreRoot->setRenderSystem( renderSystem );
  QString dimensions = QString( "%1x%2" ).arg(this->width()).arg(this->height());
  renderSystem->setConfigOption( "Video Mode", dimensions.toStdString() );
  mOgreRoot->getRenderSystem()->setConfigOption( "Full Screen", "No" );
  mOgreRoot->saveConfig();
  mOgreRoot->initialise(false);
  initResourses();
}

void OgreWidget::initializeGL()
{

  // Get the parameters of the window QT created
  Ogre::String winHandle = Ogre::StringConverter::toString((unsigned int)(winId()));
  Ogre::NameValuePairList params;
  params["externalWindowHandle"] = winHandle;

  mOgreWindow = mOgreRoot->createRenderWindow( "QOgreWidget_RenderWindow",   this->width(),   this->height(), false,  &params );
  mOgreWindow->setActive(true);
  WId ogreWinId = 0x0;
  mOgreWindow->getCustomAttribute( "WINDOW", &ogreWinId );
  setAttribute( Qt::WA_PaintOnScreen, true );
  setAttribute( Qt::WA_NoBackground );

  //== Ogre Initialization ==//
  Ogre::SceneType scene_manager_type = Ogre::ST_GENERIC;
  mSceneMgr = mOgreRoot->createSceneManager( scene_manager_type );
  mCamera = mSceneMgr->createCamera( "QOgreWidget_Cam" );
  mCamera->setNearClipDistance(1.0f);
  mCamera->setFarClipDistance(10000.0f);
  mCamera->setPosition(Ogre::Vector3(-500.0f, 300.0f, 0.0f));
  mCamera->setOrientation(Ogre::Quaternion(1,-0.27,-0.95,-0.27));
  mCamera->setAutoAspectRatio(true);

  mViewport = mOgreWindow->addViewport( mCamera );
  mViewport->setBackgroundColour( Ogre::ColourValue( 0.2,0.2,0.2 ) );

  mRaySceneQuery = new Ogre::DefaultRaySceneQuery(mSceneMgr);

  mCurrentNode=0;

  timer = new QTimer;
  QObject::connect(timer, SIGNAL(timeout()), this,SLOT(OnRenderTimer()));
  timer->setInterval(10);
  timer->start();
  GizmoManager::CreateGizmo();
  altClick=false; 

 // mCamera->setPolygonMode(Ogre::PM_SOLID);
 // mCamera->setPolygonMode(Ogre::PM_WIREFRAME);
  mCamera->setFOVy(Ogre::Radian(0.3));
  //mSceneMgr->showBoundingBoxes(true);
}

void OgreWidget::paintGL()
{
  assert( mOgreWindow );
  mOgreRoot->renderOneFrame();

}

void OgreWidget::resizeGL( int width, int height )
{
  assert( mOgreWindow );
  mOgreWindow->windowMovedOrResized();


  GizmoManager::ActionsAfterResizeWindow(width,height);


}

Ogre::RenderSystem* OgreWidget::chooseRenderer( Ogre::RenderSystemList *renderers )
{
  return *renderers->begin();
}

void OgreWidget::initResourses()
{

  Ogre::String path = QDir::currentPath().toStdString();
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(path + "/media/materials/textures", std::string("FileSystem"), "MyGroup", false);
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(path + "/media/models",std::string("FileSystem"), "MyGroup", false);
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(path + "/media/materials",std::string("FileSystem"), "MyGroup", false);
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(path + "/media/myGUI",std::string("FileSystem"), "MyGroup", false);
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(path + "/media/scenes",std::string("FileSystem"), "MyGroup", false);
  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

}

OgreWidget::~OgreWidget()
{
    mOgreRoot->shutdown();
    delete mOgreRoot;
    destroy();
}
void OgreWidget::OnRenderTimer()
{
    Ogre::Root::getSingleton().renderOneFrame();
}

void OgreWidget::mousePressEvent ( QMouseEvent * event )
{
    Ogre::Vector3 startMousePosition;

    if(event->button() == Qt::LeftButton &&  !altClick )
    {

        if( (mCurrentEntity = RayManager::raycastEntityOnScene(event->x() ,   event->y(), AXIS_CAMERA )) != 0 &&  !altClick )
        {
            GizmoManager::ClickOnCameraGizmo(mCurrentEntity->getName());
            return;
        }

       if( (startMousePosition = RayManager::raycastIntersectionOnScene(event->x() ,   event->y(), AXIS_MASK_XYZ,true )) != Ogre::Vector3::ZERO )

       {
           GizmoManager::SetStartPoint(startMousePosition);
           return;

       }


       if( (mCurrentNode = RayManager::raycastNodeOnScene(event->x() ,   event->y(), NONE_MASK )) != 0 )
        {
            MainWindow::getInstance()->UpdateComponents(mCurrentNode,mSceneMgr->getEntity(mCurrentNode->getName()));

            MainWindow::getInstance()->UpdateSceneNodesList(QString::fromStdString(mCurrentNode->getName()));            
            GizmoManager::cameraNode->setPosition(mCurrentNode->getPosition());

            if( MainWindow::getInstance()->ui->actionTranslate->isChecked())
            {
                 GizmoManager::Show(GizmoManager::getTranslateGizmo());
                 GizmoManager::SetGizmoPosition(GizmoManager::getTranslateGizmo(),mCurrentNode->getPosition());

                 GizmoManager::UpdateAxisSize(GizmoManager::getTranslateGizmo(),mCurrentNode,"",0);

                 if(MainWindow::getInstance()->ui->actionGlobal->isChecked())
                     GizmoManager::ConvertGizmo(false,true,mCurrentNode);
                 if(MainWindow::getInstance()->ui->actionLocal->isChecked())
                     GizmoManager::ConvertGizmo(true,false,mCurrentNode);

            }
            if( MainWindow::getInstance()->ui->actionRotate->isChecked())
            {
                 GizmoManager::Show(GizmoManager::getRotateGizmo());
                 GizmoManager::SetGizmoPosition(GizmoManager::getRotateGizmo(),mCurrentNode->getPosition());

                 GizmoManager::UpdateAxisSize(GizmoManager::getRotateGizmo(),mCurrentNode,"",0);
            }
            if( MainWindow::getInstance()->ui->actionScale->isChecked())
            {
                 GizmoManager::Show(GizmoManager::getScaleGizmo());
                 GizmoManager::SetGizmoPosition(GizmoManager::getScaleGizmo(),mCurrentNode->getPosition());

                 GizmoManager::UpdateAxisSize(GizmoManager::getScaleGizmo(),mCurrentNode,"",0);
                 GizmoManager::ConvertGizmo(false,true,mCurrentNode);
            }



        }       
       else
       {
            GizmoManager::Hide(GizmoManager::getTranslateGizmo());
            GizmoManager::Hide(GizmoManager::getRotateGizmo());
            GizmoManager::Hide(GizmoManager::getScaleGizmo());           
       }


    }
}


void OgreWidget::mouseMoveEvent (QMouseEvent * event)
{
    static float currentX;
    static float currentY;

    if(event->buttons() == Qt::LeftButton && mCurrentEntity && mCurrentNode &&  !altClick)
    {
        if( MainWindow::getInstance()->ui->actionGlobal->isChecked())
        {

             GizmoManager::ManipulationWithGizmo(mCurrentEntity->getName(),mCurrentNode,event->x(),event->y(),false,true);

        }
        if( MainWindow::getInstance()->ui->actionLocal->isChecked())
        {
             GizmoManager::ManipulationWithGizmo(mCurrentEntity->getName(),mCurrentNode,event->x(),event->y(),true,false);
        }

        MainWindow::getInstance()->UpdateComponents(mCurrentNode,mSceneMgr->getEntity(mCurrentNode->getName()));             
        return;
    }

    if( (mCurrentEntity = RayManager::raycastEntityOnScene(event->x(), event->y(), AXIS_MASK_XYZ )) != 0 &&  !altClick )
    {
        GizmoManager::SetLightOn(GizmoManager::getTranslateGizmo(),mCurrentEntity->getName());
        GizmoManager::SetLightOn(GizmoManager::getRotateGizmo(),mCurrentEntity->getName());
        GizmoManager::SetLightOn(GizmoManager::getScaleGizmo(),mCurrentEntity->getName());        
    }
    else if( (mCurrentEntity = RayManager::raycastEntityOnScene(event->x() ,   event->y(), AXIS_CAMERA )) != 0 &&  !altClick )
    {
        GizmoManager::SetLightOn(GizmoManager::getCameraGizmo(),mCurrentEntity->getName());
    }
    else
    {
         GizmoManager::SetLightOff(GizmoManager::getRotateGizmo());
         GizmoManager::SetLightOff(GizmoManager::getTranslateGizmo());
         GizmoManager::SetLightOff(GizmoManager::getScaleGizmo());
         GizmoManager::SetLightOff(GizmoManager::getCameraGizmo());
    }

    if(event->buttons() == Qt::RightButton)
    {
        CameraLooking(event->x(),event->y(),currentX,currentY);
    }

    if(event->buttons() == Qt::LeftButton &&  altClick )
    {      
       SphereCameraRotating(event->x(),event->y(),currentX,currentY);
    }



    currentX = event->x();
    currentY = event->y();

}


void OgreWidget::keyPressEvent( QKeyEvent * event )
{
    float cameraSpeed=10;
    switch(event->key())
    {
        case Qt::Key_Up:
       if (GizmoManager::cameraGizmoisClicked  )
            mCamera->moveRelative(Ogre::Vector3(0,cameraSpeed,0));
       else
            GizmoManager::cameraNode->setPosition((GizmoManager::cameraNode->getPosition() + Ogre::Vector3(mCamera->getRealDirection().x*cameraSpeed, 0,mCamera->getRealDirection().z*cameraSpeed )) );

       break;

        case Qt::Key_Down:
        if (GizmoManager::cameraGizmoisClicked  )
             mCamera->moveRelative(Ogre::Vector3(0,-cameraSpeed,0));
        else
             GizmoManager::cameraNode->setPosition((GizmoManager::cameraNode->getPosition() + Ogre::Vector3(mCamera->getRealDirection().x*-cameraSpeed, 0,mCamera->getRealDirection().z*-cameraSpeed )));
                 break;
        case Qt::Key_Left:
        if (GizmoManager::cameraGizmoisClicked  )
             mCamera->moveRelative(Ogre::Vector3(-cameraSpeed,0,0));
        else
              GizmoManager::cameraNode->translate(mCamera->getRealOrientation() * Ogre::Vector3( -cameraSpeed, 0, 0 ));
                 break;
        case Qt::Key_Right:
        if (GizmoManager::cameraGizmoisClicked  )
             mCamera->moveRelative(Ogre::Vector3(cameraSpeed,0,0));
        else
            GizmoManager::cameraNode->translate(mCamera->getRealOrientation() * Ogre::Vector3( cameraSpeed, 0, 0 ));
                 break;
        case Qt::Key_Alt:
        altClick=true;

            break;
    }

    GizmoManager::getCameraGizmo()->NodeCameraGizmoSupport->setPosition(mCamera->getPosition());

    if(mCurrentNode)
    {

          GizmoManager::UpdateAxisSize(GizmoManager::getTranslateGizmo(),mCurrentNode,"",0);
          GizmoManager::UpdateAxisSize(GizmoManager::getRotateGizmo(),mCurrentNode,"",0);
          GizmoManager::UpdateAxisSize(GizmoManager::getScaleGizmo(),mCurrentNode,"",0);
    }

}

void OgreWidget::keyReleaseEvent ( QKeyEvent * event )
{
    switch(event->key())
    {
    case Qt::Key_Alt:
    altClick=false;
    if(mCurrentNode)
    {
        if(MainWindow::getInstance()->ui->actionGlobal->isChecked())
            GizmoManager::ConvertGizmo(false,true,mCurrentNode);
        if(MainWindow::getInstance()->ui->actionLocal->isChecked())
            GizmoManager::ConvertGizmo(true,false,mCurrentNode);
    }

        break;
    }
}


void OgreWidget::wheelEvent( QWheelEvent * event )
{

    mOgreWindow->getViewport(0)->getCamera()->moveRelative(Ogre::Vector3(0.0f,0.0f,event->delta() * -0.1f));
    float WindowWidth  = this->width();
    float WindowHeight = this->height();

   Ogre::Ray mouseRay = mCamera->getCameraToViewportRay((WindowWidth-60)/WindowWidth,(WindowHeight-WindowHeight+60)/WindowHeight);
   GizmoManager::getCameraGizmo()->setPosition(Ogre::Vector3(mouseRay.getPoint(mCamera->getNearClipDistance()).x,mouseRay.getPoint(mCamera->getNearClipDistance()).y,mouseRay.getPoint(mCamera->getNearClipDistance()).z));

   if(mCurrentNode)
    {

        GizmoManager::UpdateAxisSize(GizmoManager::getTranslateGizmo(),mCurrentNode,"",0);
        GizmoManager::UpdateAxisSize(GizmoManager::getRotateGizmo(),mCurrentNode,"",0);
        GizmoManager::UpdateAxisSize(GizmoManager::getScaleGizmo(),mCurrentNode,"",0);

    }  
}

void OgreWidget::CameraLooking(float x, float y, float currentX, float currentY)
{
    float deltaX=currentX-x;
    float deltaY=currentY-y;

    if(x<currentX)
    {
           mCamera->yaw(Ogre::Radian(deltaX) * 0.006f);
           GizmoManager::getCameraGizmo()->NodeCameraGizmoSupport->rotate( Ogre::Vector3::UNIT_Y,Ogre::Radian(deltaX) * 0.006f, Ogre::Node::TS_PARENT);
           GizmoManager::getCameraGizmo()->Rotate( Ogre::Vector3::UNIT_Y,Ogre::Radian(-deltaX) * 0.006f, Ogre::Node::TS_LOCAL);
    }
    else
    {
          mCamera->yaw(Ogre::Radian(deltaX) * 0.006f);
          GizmoManager::getCameraGizmo()->NodeCameraGizmoSupport->rotate( Ogre::Vector3::UNIT_Y,Ogre::Radian(deltaX) * 0.006f, Ogre::Node::TS_PARENT);
          GizmoManager::getCameraGizmo()->Rotate( Ogre::Vector3::UNIT_Y,Ogre::Radian(-deltaX) * 0.006f, Ogre::Node::TS_LOCAL);
    }

    if(y<currentY)
    {
          mCamera->pitch(Ogre::Radian(deltaY) * 0.006f);
          GizmoManager::getCameraGizmo()->NodeCameraGizmoSupport->rotate( mCamera->getRealOrientation()*Ogre::Vector3(1,0,0),Ogre::Radian(deltaY) * 0.006f, Ogre::Node::TS_PARENT);
          GizmoManager::getCameraGizmo()->Rotate( mCamera->getRealOrientation()*Ogre::Vector3(1,0,0),Ogre::Radian(-deltaY) * 0.006f, Ogre::Node::TS_PARENT);

    }
    else
    {
           mCamera->pitch(Ogre::Radian(deltaY) * 0.006f);
           GizmoManager::getCameraGizmo()->NodeCameraGizmoSupport->rotate( mCamera->getRealOrientation()*Ogre::Vector3(1,0,0),Ogre::Radian(deltaY) * 0.006f, Ogre::Node::TS_PARENT);
           GizmoManager::getCameraGizmo()->Rotate( mCamera->getRealOrientation()*Ogre::Vector3(1,0,0),Ogre::Radian(-deltaY) * 0.006f, Ogre::Node::TS_PARENT);
    }
    float WindowWidth  = this->width();
    float WindowHeight = this->height();
    Ogre::Ray mouseRay = mCamera->getCameraToViewportRay((WindowWidth-60)/WindowWidth,(WindowHeight-WindowHeight+60)/WindowHeight);
    GizmoManager::getCameraGizmo()->setPosition(Ogre::Vector3(mouseRay.getPoint(mCamera->getNearClipDistance()).x,mouseRay.getPoint(mCamera->getNearClipDistance()).y,mouseRay.getPoint(mCamera->getNearClipDistance()).z));

}
void OgreWidget::SphereCameraRotating(float x, float y, float currentX, float currentY)
{
    Ogre::Radian theta;
    Ogre::Radian phi;
    float deltaX=currentX-x;
    float deltaY=currentY-y;
    if(x<currentX)
    {
            theta = Ogre::Radian(static_cast<float>(deltaX) / 350.0f);
            GizmoManager::cameraNode->rotate( Ogre::Vector3::UNIT_Y , theta, Ogre::Node::TS_PARENT);
            GizmoManager::planeNode->rotate(Ogre::Vector3::UNIT_Y , theta,Ogre::Node::TS_LOCAL);
            GizmoManager::getCameraGizmo()->Rotate(Ogre::Vector3::UNIT_Y,-theta, Ogre::Node::TS_LOCAL);
    }
    else
    {
            theta = Ogre::Radian(static_cast<float>(-deltaX) / 350.0f);
            GizmoManager::cameraNode->rotate( Ogre::Vector3::UNIT_Y, -theta, Ogre::Node::TS_PARENT);
            GizmoManager::planeNode->rotate(Ogre::Vector3::UNIT_Y, -theta,Ogre::Node::TS_LOCAL);
            GizmoManager::getCameraGizmo()->Rotate(Ogre::Vector3::UNIT_Y,theta, Ogre::Node::TS_LOCAL);
    }

    if(y<currentY)
    {
            phi = Ogre::Radian(static_cast<float>(deltaY) / 50.0f);
            GizmoManager::cameraNode->rotate( Ogre::Vector3::UNIT_Z, phi, Ogre::Node::TS_LOCAL);
            GizmoManager::getCameraGizmo()->Rotate( mCamera->getRealOrientation()*Ogre::Vector3(1,0,0),-phi, Ogre::Node::TS_LOCAL);
    }
    else
    {
            phi = Ogre::Radian(static_cast<float>(deltaY) / 50.0f);
            GizmoManager::cameraNode->rotate( Ogre::Vector3::UNIT_Z, phi, Ogre::Node::TS_LOCAL);
            GizmoManager::getCameraGizmo()->Rotate( mCamera->getRealOrientation()*Ogre::Vector3(1,0,0),-phi, Ogre::Node::TS_LOCAL);
    }   

}




Ogre::SceneManager *OgreWidget::getSceneManager()
{
    return mSceneMgr;
}

void OgreWidget::setCurrentNode(Ogre::SceneNode* node)
{
    mCurrentNode = node;
}

Ogre::SceneNode* OgreWidget::getCurrentNode()
{
    return mCurrentNode;
}

Ogre::Viewport * OgreWidget::getViewPort()
{
    return mViewport;
}

Ogre::Camera * OgreWidget::getCamera()
{
    return mCamera;
}

Ogre::RaySceneQuery * OgreWidget::getRaySceneQuery()
{
    return mRaySceneQuery;
}
Ogre::RenderWindow* OgreWidget::getRenderWidnow()
{
    return mOgreWindow;
}

void OgreWidget::dropEvent(QDropEvent *event)
{

}

void OgreWidget::dragEnterEvent(QDragEnterEvent *event)
{
    counter++;
    QString str = event->mimeData()->text();

    GameObject *go = new GameObject("object" + QString::number(counter).toStdString());
    go->AddComponent(new MeshRenderer(go->name, str.toStdString(), "Robot"));
}
