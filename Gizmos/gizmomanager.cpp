#include "gizmomanager.h"

TranslateGizmo * GizmoManager::translateGizmo = 0;
RotateGizmo * GizmoManager::rotateGizmo = 0;
ScaleGizmo * GizmoManager::scaleGizmo = 0;
CameraGizmo * GizmoManager::cameraGizmo = 0;
Ogre::SceneNode * GizmoManager::planeNode = 0;
Ogre::SceneNode * GizmoManager::cameraNode = 0;
Ogre::Vector3 GizmoManager::startMousePosition = Ogre::Vector3::ZERO;

bool GizmoManager::cameraGizmoisClicked=false;



void GizmoManager::CreateGizmo()
{
     createMaterials();

     translateGizmo = new TranslateGizmo();
     rotateGizmo = new RotateGizmo();
     scaleGizmo = new ScaleGizmo();


     cameraNode = MainWindow::getInstance()->ogreWindow->getSceneManager()->getRootSceneNode()->createChildSceneNode( "Camera Scene Node" );
     cameraNode->attachObject(MainWindow::getInstance()->ogreWindow->getCamera());

     cameraGizmo = new CameraGizmo();

     Ogre::MeshManager::getSingletonPtr()->createPlane("xz_plane", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,Ogre::Plane(Ogre::Vector3::UNIT_Y, 0),8000.0f,8000.0f, 1,1,true,1,10,10,Ogre::Vector3::UNIT_Z);
     Ogre::Entity * xz_plane = MainWindow::getInstance()->ogreWindow->getSceneManager()->createEntity("xz_plane", "xz_plane");
     xz_plane->setMaterialName("Template/texture_map");
     xz_plane->setCastShadows(false);
     xz_plane->setQueryFlags(OgreWidget::PLANE_XZ_MASK);
     Ogre::MeshManager::getSingletonPtr()->createPlane("yz_plane", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,Ogre::Plane(Ogre::Vector3::UNIT_X, 0), 8000.0f, 8000.0f, 1, 1, true,1,10,10,Ogre::Vector3::UNIT_Y);
     Ogre::Entity * yz_plane = MainWindow::getInstance()->ogreWindow->getSceneManager()->createEntity("yz_plane", "yz_plane");
     yz_plane->setMaterialName("Template/texture_map");
     yz_plane->setCastShadows(false);
     yz_plane->setQueryFlags(OgreWidget::PLANE_XY_MASK);
     planeNode = MainWindow::getInstance()->ogreWindow->getSceneManager()->getRootSceneNode()->createChildSceneNode("planeNode");
     planeNode->attachObject(xz_plane);
     planeNode->attachObject(yz_plane);
     planeNode->setVisible(false);

}

void GizmoManager::SetLightOff(IGizmo* gizmo)
{    
   gizmo->draw(false,false,false,false);
}

void GizmoManager::SetLightOn(IGizmo* gizmo ,Ogre::String gizmoName)
{
  if(gizmoName == "lineX" || gizmoName =="lineXCone"     || gizmoName =="CircleX" || gizmoName =="lineXscale" || gizmoName =="cubX" || gizmoName =="CameraGizmoConusX")
  {
        gizmo->draw(true,false,false);
  }
  else if(gizmoName == "lineY" || gizmoName =="lineYCone" || gizmoName =="CircleY" || gizmoName =="lineYscale" || gizmoName =="cubY" || gizmoName =="CameraGizmoConusY" )
  {
        gizmo->draw(false,true,false);
  }
  else if(gizmoName == "lineZ" || gizmoName =="lineZCone" || gizmoName =="CircleZ" || gizmoName =="lineZscale" || gizmoName =="cubZ" || gizmoName =="CameraGizmoConusZ")
  {
        gizmo->draw(false,false,true);
  }
  else if(gizmoName == "Quadr" || gizmoName == "ÑameraGizmoCube")
  {
        gizmo->draw(false,false,false,true);
  }
}
void GizmoManager::SetGizmoPosition(IGizmo* gizmo ,Ogre::Vector3 position)
{
    gizmo->setPosition(position);
    planeNode->setPosition(position);
}

void GizmoManager::Show(IGizmo* gizmo)
{
    gizmo->show();
}
void GizmoManager::Hide(IGizmo* gizmo)
{
    gizmo->hide();
}

void GizmoManager::ManipulationWithGizmo(Ogre::String gizmoName, OgreWidget* widget,Ogre::SceneNode* currentNode,float x,float y,bool localGizmo, bool globalGizmo)
{
   Ogre::Vector3 intersection;

    if(gizmoName == "lineX" || gizmoName =="lineXCone" )
    {
        if(globalGizmo)
        {
            intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, OgreWidget::PLANE_XZ_MASK,false );
            Ogre::Vector3 deltaPos =intersection - startMousePosition;
            translateGizmo->Translate(deltaPos.x,0,0);
            planeNode->translate(deltaPos.x,0,0);
            currentNode->translate(deltaPos.x,0,0);
            UpdateAxisSize(translateGizmo,currentNode,gizmoName,0);
        }
        if(localGizmo)
        {
            intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y,OgreWidget::PLANE_XZ_MASK,false,true,false,planeNode );
            Ogre::Vector3 deltaPos =intersection - startMousePosition;
            if(abs(deltaPos.x) <50)
            {
               translateGizmo->Translate(deltaPos.x,0,0,Ogre::Node::TS_LOCAL);
               currentNode->translate(deltaPos.x,0,0,Ogre::Node::TS_LOCAL);
               UpdateAxisSize(translateGizmo,currentNode,gizmoName,0);
            }
        }

    }
    if(gizmoName == "lineY" || gizmoName =="lineYCone" )
    {
        if(globalGizmo)
        {
            intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, OgreWidget::PLANE_XY_MASK,false );
            Ogre::Vector3 deltaPos =intersection - startMousePosition;
            translateGizmo->Translate(0,deltaPos.y,0);
            planeNode->translate(0,deltaPos.y,0);
            currentNode->translate(0,deltaPos.y,0);
            UpdateAxisSize(translateGizmo,currentNode,gizmoName,0);
        }
        if(localGizmo)
        {
            intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, OgreWidget::PLANE_XY_MASK,false,true,false,planeNode );
            Ogre::Vector3 deltaPos =intersection - startMousePosition;
            if(abs(deltaPos.y) <50)
            {
               translateGizmo->Translate(0,deltaPos.y,0,Ogre::Node::TS_LOCAL);
               currentNode->translate(0,deltaPos.y,0,Ogre::Node::TS_LOCAL);
               UpdateAxisSize(translateGizmo,currentNode,gizmoName,0);
            }
        }

    }
    if(gizmoName == "lineZ" || gizmoName =="lineZCone" )
    {
        if(globalGizmo)
        {
            intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, OgreWidget::PLANE_XZ_MASK,false );
            Ogre::Vector3 deltaPos =intersection - startMousePosition;
            translateGizmo->Translate(0,0,deltaPos.z);
            planeNode->translate(0,0,deltaPos.z);
            currentNode->translate(0,0,deltaPos.z);
            UpdateAxisSize(translateGizmo,currentNode,gizmoName,0);
        }
        if(localGizmo)
        {
            intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, OgreWidget::PLANE_XZ_MASK,false,true,false,planeNode );
            Ogre::Vector3 deltaPos =intersection - startMousePosition;           
            if(abs(deltaPos.z) <50)
            {
               translateGizmo->Translate(0,0,deltaPos.z,Ogre::Node::TS_LOCAL);
               currentNode->translate(0,0,deltaPos.z,Ogre::Node::TS_LOCAL);
               UpdateAxisSize(translateGizmo,currentNode,gizmoName,0);
            }
        }

    }
    if(gizmoName == "Quadr" )
    {
        intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, OgreWidget::PLANE_XZ_MASK,false );
        Ogre::Vector3 deltaPos =intersection - startMousePosition;
        translateGizmo->Translate(deltaPos.x,0,deltaPos.z);
        planeNode->translate(deltaPos.x,0,deltaPos.z);
        currentNode->translate(deltaPos.x,0,deltaPos.z);
        UpdateAxisSize(translateGizmo,currentNode,gizmoName,0);
    }
    if(gizmoName == "CircleX" )
    {
        intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, OgreWidget::PLANE_XZ_MASK,false );
        Ogre::Vector3 deltaPos =intersection - startMousePosition;
        if(abs(deltaPos.x) <4)
           currentNode->rotate(Ogre::Vector3::UNIT_Z , Ogre::Radian(-deltaPos.x*0.1),Ogre::Node::TS_WORLD);
    }
    if(gizmoName == "CircleY" )
    {
        intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, OgreWidget::PLANE_XY_MASK,false );
        Ogre::Vector3 deltaPos =intersection - startMousePosition;
        if(abs(deltaPos.z) <4)
           {
              currentNode->rotate(Ogre::Vector3::UNIT_Y , Ogre::Radian(deltaPos.z*0.1),Ogre::Node::TS_WORLD);
           }
    }
    if(gizmoName == "CircleZ" )
    {
        intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, OgreWidget::PLANE_XZ_MASK,false );
        Ogre::Vector3 deltaPos =intersection - startMousePosition;
        if(abs(deltaPos.z) <4)
           currentNode->rotate(Ogre::Vector3::UNIT_X , Ogre::Radian(deltaPos.z*0.1),Ogre::Node::TS_WORLD);
    }
    if(gizmoName == "lineXscale" || gizmoName =="cubX")
    {     
        intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y,OgreWidget::PLANE_XZ_MASK,false,true,false,planeNode );
        Ogre::Vector3 deltaPos =intersection - startMousePosition;
        if(abs(deltaPos.x) <15)
        {
           currentNode->setScale(currentNode->getScale().x + deltaPos.x*0.1,currentNode->getScale().y,currentNode->getScale().z);
        }

    }
    if(gizmoName == "lineYscale" || gizmoName =="cubY" )
    {      
        intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, OgreWidget::PLANE_XY_MASK,false,true,false,planeNode );
        Ogre::Vector3 deltaPos =intersection - startMousePosition;
        if(abs(deltaPos.y) <15)
        {
           currentNode->setScale(currentNode->getScale().x,currentNode->getScale().y + deltaPos.y*0.1,currentNode->getScale().z);
        }
    }
    if(gizmoName == "lineZscale" || gizmoName =="cubZ")
    {       

        intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, OgreWidget::PLANE_XZ_MASK,false,true,false,planeNode );
        Ogre::Vector3 deltaPos =intersection - startMousePosition;
         qDebug()<<abs(deltaPos.z);
        if(abs(deltaPos.z) <15)
        {
          currentNode->setScale(currentNode->getScale().x,currentNode->getScale().y,currentNode->getScale().z + deltaPos.z*0.1);
        }
    }
    startMousePosition = intersection;
}

void GizmoManager::UpdateAxisSize(IGizmo* gizmo,Ogre::SceneNode* currentNode,Ogre::String gizmoName,float size)
{
    gizmo->scale(gizmo->getScale().x + size*1.02,gizmo->getScale().y + size*1.02 ,gizmo->getScale().z + size*1.02 );

    Ogre::Radian rad = MainWindow::getInstance()->ogreWindow->getCamera()->getFOVy( ) / 2;
    Ogre::Vector3 delta = MainWindow::getInstance()->ogreWindow->getCamera()->getRealPosition( ) - currentNode->getPosition( );
    float boundsize = delta.length( ) * Ogre::Math::Sin( rad )/3 ;

    gizmo->setBoundSize(boundsize);
    if(gizmoName == "lineX" || gizmoName =="lineXCone" )
         gizmo->draw(true,false,false,false);
    else if(gizmoName == "lineY" || gizmoName =="lineYCone" )
         gizmo->draw(false,true,false,false);
    else if(gizmoName == "lineZ" || gizmoName =="lineZCone" )
         gizmo->draw(false,false,true,false);
    else if(gizmoName == "Quadr" )
         gizmo->draw(false,false,false,true);
    else
        gizmo->draw(false,false,false,false);

}

void GizmoManager::ConvertGizmo(bool local,bool global,Ogre::SceneNode* currentNode)
{
    Ogre::Quaternion _gizmoOrient = Ogre::Quaternion(1,0,0,0);
    if (global)
    {
            translateGizmo->setOrientation(_gizmoOrient);
            planeNode->setOrientation(_gizmoOrient);
            _gizmoOrient = currentNode->getOrientation();
            scaleGizmo->setOrientation(_gizmoOrient);
    }
    if (local)
    {
            _gizmoOrient = currentNode->getOrientation();
            translateGizmo->setOrientation(_gizmoOrient);
            scaleGizmo->setOrientation(_gizmoOrient);
            planeNode->setOrientation(_gizmoOrient);
    }
}
void GizmoManager::ClickOnCameraGizmo(Ogre::String gizmoName)
{
   if (gizmoName == "CameraGizmoConusX")
   {
       cameraNode->setOrientation(cameraNode->getOrientation().w,0, 0, 0);
       cameraNode->rotate( Ogre::Vector3::UNIT_Y , Ogre::Degree(180), Ogre::Node::TS_PARENT);
       cameraNode->rotate( Ogre::Vector3::UNIT_Z,	Ogre::Degree(32), Ogre::Node::TS_LOCAL);
       cameraGizmo->setOrientation(MainWindow::getInstance()->ogreWindow->getCamera()->getOrientation().w,0,0,0);
       cameraGizmo->Rotate( Ogre::Vector3::UNIT_Y , Ogre::Degree(165), Ogre::Node::TS_PARENT);
       cameraGizmo->Rotate( Ogre::Vector3::UNIT_X , Ogre::Degree(10), Ogre::Node::TS_LOCAL);
       cameraGizmo->Rotate( Ogre::Vector3::UNIT_Z , Ogre::Degree(25), Ogre::Node::TS_LOCAL);
       planeNode->setOrientation(cameraNode->getOrientation().w,0, 0, 0);
       planeNode->rotate( Ogre::Vector3::UNIT_Y , Ogre::Degree(180), Ogre::Node::TS_PARENT);
       planeNode->rotate( Ogre::Vector3::UNIT_Z,	Ogre::Degree(32), Ogre::Node::TS_LOCAL);     

   }
   if (gizmoName == "CameraGizmoConusY")
   {
       cameraNode->setOrientation(cameraNode->getOrientation().w,0, 0, 0);
       cameraNode->rotate( Ogre::Vector3::UNIT_Z,	Ogre::Degree(-55), Ogre::Node::TS_LOCAL);
       cameraNode->rotate( Ogre::Vector3::UNIT_Y , Ogre::Degree(-90), Ogre::Node::TS_PARENT);
       cameraGizmo->setOrientation(MainWindow::getInstance()->ogreWindow->getCamera()->getOrientation().w,0, 0, 0);
       cameraGizmo->Rotate( Ogre::Vector3::UNIT_Y , Ogre::Degree(-15), Ogre::Node::TS_LOCAL);
       cameraGizmo->Rotate( Ogre::Vector3::UNIT_X , Ogre::Degree(-10), Ogre::Node::TS_LOCAL);
       cameraGizmo->Rotate( Ogre::Vector3::UNIT_Z , Ogre::Degree(65), Ogre::Node::TS_LOCAL);
       cameraGizmo->Rotate( Ogre::Vector3::UNIT_Y , Ogre::Degree(90), Ogre::Node::TS_LOCAL);
       planeNode->setOrientation(cameraNode->getOrientation().w,0, 0, 0);
       planeNode->rotate( Ogre::Vector3::UNIT_Z,	Ogre::Degree(-55), Ogre::Node::TS_LOCAL);
       planeNode->rotate( Ogre::Vector3::UNIT_Y , Ogre::Degree(-90), Ogre::Node::TS_PARENT);
   }
   if (gizmoName == "CameraGizmoConusZ")
   {


       cameraNode->setOrientation(cameraNode->getOrientation().w,0, 0, 0);
       cameraNode->rotate( Ogre::Vector3::UNIT_Y , Ogre::Degree(90), Ogre::Node::TS_PARENT);
       cameraNode->rotate( Ogre::Vector3::UNIT_Z,	Ogre::Degree(35), Ogre::Node::TS_LOCAL);
       cameraGizmo->setOrientation(MainWindow::getInstance()->ogreWindow->getCamera()->getOrientation().w,0, 0, 0);
       cameraGizmo->Rotate( Ogre::Vector3::UNIT_Y , Ogre::Degree(165), Ogre::Node::TS_PARENT);
       cameraGizmo->Rotate( Ogre::Vector3::UNIT_X , Ogre::Degree(10), Ogre::Node::TS_LOCAL);
       cameraGizmo->Rotate( Ogre::Vector3::UNIT_Z , Ogre::Degree(25), Ogre::Node::TS_LOCAL);
       cameraGizmo->Rotate( Ogre::Vector3::UNIT_Y , Ogre::Degree(90), Ogre::Node::TS_LOCAL);
       planeNode->setOrientation(cameraNode->getOrientation().w,0, 0, 0);
       planeNode->rotate( Ogre::Vector3::UNIT_Y , Ogre::Degree(90), Ogre::Node::TS_LOCAL);
       planeNode->rotate( Ogre::Vector3::UNIT_Z,	Ogre::Degree(35), Ogre::Node::TS_LOCAL);

   }
   cameraGizmoisClicked = true;
   if (gizmoName == "ÑameraGizmoCube")
   {
       cameraNode->setOrientation(cameraNode->getOrientation().w,0, 0, 0);
       cameraNode->rotate( Ogre::Vector3::UNIT_Y , Ogre::Degree(-45), Ogre::Node::TS_PARENT);
       cameraGizmo->setOrientation(MainWindow::getInstance()->ogreWindow->getCamera()->getOrientation().w,0, 0, 0);
       cameraGizmo->Rotate( Ogre::Vector3::UNIT_Y , Ogre::Degree(30), Ogre::Node::TS_PARENT);
       cameraGizmo->Rotate( Ogre::Vector3::UNIT_X , Ogre::Degree(-10), Ogre::Node::TS_LOCAL);

       planeNode->setOrientation(cameraNode->getOrientation().w,0, 0, 0);
       planeNode->rotate( Ogre::Vector3::UNIT_Y , Ogre::Degree(-45), Ogre::Node::TS_LOCAL);
       cameraGizmoisClicked=false;
   }
}

void GizmoManager::ActionsAfterResizeWindow(float width,float height)
{
    Ogre::Radian theta;
    Ogre::Radian phi;
    static float currentWidth;
    static float currentHeight;

    float deltaX=currentWidth-width;
    float deltaY=currentHeight-height;

    theta = Ogre::Radian(static_cast<float>(deltaX) / 2500.0f);
    phi = Ogre::Radian(static_cast<float>(deltaY) / 2500.0f);

    float size = (deltaY/600.f);

    cameraGizmo->NodeCameraGizmoSupport->setPosition(MainWindow::getInstance()->ogreWindow->getCamera()->getPosition());
    Ogre::Ray mouseRay = MainWindow::getInstance()->ogreWindow->getCamera()->getCameraToViewportRay((width-60)/width,(height-height+60)/height);
    cameraGizmo->setPosition(Ogre::Vector3(mouseRay.getPoint(MainWindow::getInstance()->ogreWindow->getCamera()->getNearClipDistance()).x,mouseRay.getPoint(MainWindow::getInstance()->ogreWindow->getCamera()->getNearClipDistance()).y,mouseRay.getPoint(MainWindow::getInstance()->ogreWindow->getCamera()->getNearClipDistance()).z));

   if(width<currentWidth || width>currentWidth)
   {
        cameraGizmo->Rotate(Ogre::Vector3::UNIT_Y,theta, Ogre::Node::TS_LOCAL);
        cameraGizmo->Rotate(Ogre::Vector3::UNIT_X,theta/2, Ogre::Node::TS_LOCAL);
   }

   if((height>currentHeight || height<currentHeight ))
   {
       if(MainWindow::getInstance()->isMaximized())
       {
          cameraGizmo->scale(cameraGizmo->getScale().x+size,cameraGizmo->getScale().y+size,cameraGizmo->getScale().z+size);
          cameraGizmo->Rotate(Ogre::Vector3::UNIT_Y,-phi*1.5, Ogre::Node::TS_LOCAL);
       }

       if(MainWindow::getInstance()->ogreWindow->getCurrentNode())
         {
             UpdateAxisSize(translateGizmo,MainWindow::getInstance()->ogreWindow->getCurrentNode(),"",size);
             UpdateAxisSize(rotateGizmo,MainWindow::getInstance()->ogreWindow->getCurrentNode(),"",size);
             UpdateAxisSize(scaleGizmo,MainWindow::getInstance()->ogreWindow->getCurrentNode(),"",size);
         }
   }

   currentWidth = width;
   currentHeight = height;
}

TranslateGizmo * GizmoManager::getTranslateGizmo()
{
    return translateGizmo;
}

RotateGizmo * GizmoManager::getRotateGizmo()
{
    return rotateGizmo;
}

ScaleGizmo * GizmoManager::getScaleGizmo()
{
    return scaleGizmo;
}

CameraGizmo * GizmoManager::getCameraGizmo()
{
    return cameraGizmo;
}

void GizmoManager::SetStartPoint(Ogre::Vector3 startPoint)
{
    startMousePosition = startPoint;
}

void GizmoManager::createMaterials()
{
    Ogre::MaterialPtr lineXMaterial = Ogre::MaterialManager::getSingleton().create("Gizmo_Translate_X",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    lineXMaterial->setReceiveShadows(false);
    lineXMaterial->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
    lineXMaterial->getTechnique(0)->getPass(0)->setDiffuse(1,0,0,0);
    lineXMaterial->getTechnique(0)->getPass(0)->setAmbient(1,0,0);
    lineXMaterial->getTechnique(0)->getPass(0)->setSelfIllumination(1,0,0);
    lineXMaterial->getTechnique(0)->getPass(0)->setCullingMode(Ogre::CULL_NONE);
    lineXMaterial->getTechnique(0)->getPass(0)->setFog ( true );

    Ogre::MaterialPtr lineYMaterial = Ogre::MaterialManager::getSingleton().create("Gizmo_Translate_Y",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    lineYMaterial->setReceiveShadows(false);
    lineYMaterial->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
    lineYMaterial->getTechnique(0)->getPass(0)->setDiffuse(0,1,0,0);
    lineYMaterial->getTechnique(0)->getPass(0)->setAmbient(0,1,0);
    lineYMaterial->getTechnique(0)->getPass(0)->setSelfIllumination(0,1,0);
    lineYMaterial->getTechnique(0)->getPass(0)->setCullingMode(Ogre::CULL_NONE);
    lineYMaterial->getTechnique(0)->getPass(0)->setFog ( true );

    Ogre::MaterialPtr lineZMaterial = Ogre::MaterialManager::getSingleton().create("Gizmo_Translate_Z",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    lineZMaterial->setReceiveShadows(false);
    lineZMaterial->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
    lineZMaterial->getTechnique(0)->getPass(0)->setDiffuse(0,0,1,0);
    lineZMaterial->getTechnique(0)->getPass(0)->setAmbient(0,0,1);
    lineZMaterial->getTechnique(0)->getPass(0)->setSelfIllumination(0,0,1);
    lineZMaterial->getTechnique(0)->getPass(0)->setCullingMode(Ogre::CULL_NONE);
    lineZMaterial->getTechnique(0)->getPass(0)->setFog ( true );


    Ogre::MaterialPtr LightedMaterial = Ogre::MaterialManager::getSingleton().create("LightedMaterial",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    LightedMaterial->setReceiveShadows(false);
    LightedMaterial->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
    LightedMaterial->getTechnique(0)->getPass(0)->setDiffuse(10,10,10,0);
    LightedMaterial->getTechnique(0)->getPass(0)->setAmbient(10,10,10);
    LightedMaterial->getTechnique(0)->getPass(0)->setSelfIllumination(10,10,10);
    LightedMaterial->getTechnique(0)->getPass(0)->setCullingMode(Ogre::CULL_NONE);
    LightedMaterial->getTechnique(0)->getPass(0)->setFog ( true );


    Ogre::MaterialPtr LightedMaterialForCameraGizmo = Ogre::MaterialManager::getSingleton().create("LightedMaterialForCameraGizmo",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    LightedMaterialForCameraGizmo->setReceiveShadows(false);
    LightedMaterialForCameraGizmo->getTechnique(0)->getPass(0)->setDiffuse(10,10,10,0);
    LightedMaterialForCameraGizmo->getTechnique(0)->getPass(0)->setAmbient(10,10,10);
    LightedMaterialForCameraGizmo->getTechnique(0)->getPass(0)->setSelfIllumination(10,10,10);
    LightedMaterialForCameraGizmo->getTechnique(0)->getPass(0)->setCullingMode(Ogre::CULL_NONE);
    LightedMaterialForCameraGizmo->getTechnique(0)->getPass(0)->setFog ( true );

    Ogre::MaterialPtr QuadrMaterial = Ogre::MaterialManager::getSingleton().create("QuadrMaterial",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    QuadrMaterial->setReceiveShadows(false);
    QuadrMaterial->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
    QuadrMaterial->getTechnique(0)->getPass(0)->setDiffuse(0,1,1,0.45);
    QuadrMaterial->getTechnique(0)->getPass(0)->setAmbient(0,1,1);
    QuadrMaterial->getTechnique(0)->getPass(0)->setSelfIllumination(0,1,1);
    QuadrMaterial->getTechnique(0)->getPass(0)->setCullingMode(Ogre::CULL_NONE);
    QuadrMaterial->getTechnique(0)->getPass(0)->setFog ( true );

    Ogre::MaterialPtr CameraGizmoMaterialX = Ogre::MaterialManager::getSingleton().create("CameraGizmoMaterialX",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    CameraGizmoMaterialX->setReceiveShadows(false);
    CameraGizmoMaterialX->getTechnique(0)->getPass(0)->setDiffuse(1,0,0,1);
    CameraGizmoMaterialX->getTechnique(0)->getPass(0)->setAmbient(1,0,0);
    CameraGizmoMaterialX->getTechnique(0)->getPass(0)->setSelfIllumination(1,0,0);
    CameraGizmoMaterialX->getTechnique(0)->getPass(0)->setCullingMode(Ogre::CULL_NONE);
    CameraGizmoMaterialX->getTechnique(0)->getPass(0)->setFog ( false );

    Ogre::MaterialPtr CameraGizmoMaterialY = Ogre::MaterialManager::getSingleton().create("CameraGizmoMaterialY",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    CameraGizmoMaterialY->setReceiveShadows(false);
    CameraGizmoMaterialY->getTechnique(0)->getPass(0)->setDiffuse(0,1,0,1);
    CameraGizmoMaterialY->getTechnique(0)->getPass(0)->setAmbient(0,1,0);
    CameraGizmoMaterialY->getTechnique(0)->getPass(0)->setSelfIllumination(0,1,0);
    CameraGizmoMaterialY->getTechnique(0)->getPass(0)->setCullingMode(Ogre::CULL_NONE);
    CameraGizmoMaterialY->getTechnique(0)->getPass(0)->setFog ( false );

    Ogre::MaterialPtr CameraGizmoMaterialZ = Ogre::MaterialManager::getSingleton().create("CameraGizmoMaterialZ",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    CameraGizmoMaterialZ->setReceiveShadows(false);
    CameraGizmoMaterialZ->getTechnique(0)->getPass(0)->setDiffuse(0,0,1,1);
    CameraGizmoMaterialZ->getTechnique(0)->getPass(0)->setAmbient(0,0,1);
    CameraGizmoMaterialZ->getTechnique(0)->getPass(0)->setSelfIllumination(0,0,1);
    CameraGizmoMaterialZ->getTechnique(0)->getPass(0)->setCullingMode(Ogre::CULL_NONE);
    CameraGizmoMaterialZ->getTechnique(0)->getPass(0)->setFog ( false );

    Ogre::MaterialPtr CameraGizmoCube = Ogre::MaterialManager::getSingleton().create("CameraGizmoCube",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    CameraGizmoCube->setReceiveShadows(false);
    CameraGizmoCube->getTechnique(0)->getPass(0)->setDiffuse(1,1,0,1);
    CameraGizmoCube->getTechnique(0)->getPass(0)->setAmbient(1,1,0);
    CameraGizmoCube->getTechnique(0)->getPass(0)->setSelfIllumination(1,1,0);
    CameraGizmoCube->getTechnique(0)->getPass(0)->setCullingMode(Ogre::CULL_NONE);
    CameraGizmoCube->getTechnique(0)->getPass(0)->setFog ( false );
}
