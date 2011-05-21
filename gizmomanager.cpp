#include "gizmomanager.h"

TranslateGizmo * GizmoManager::translateGizmo = 0;
RotateGizmo * GizmoManager::rotateGizmo = 0;
ScaleGizmo * GizmoManager::scaleGizmo = 0;
Ogre::SceneNode * GizmoManager::planeNode = 0;
Ogre::SceneNode * GizmoManager::cameraNode = 0;
Ogre::Vector3 GizmoManager::startMousePosition = Ogre::Vector3::ZERO;

void GizmoManager::CreateGizmo(OgreWidget * widget)
{
     translateGizmo = new TranslateGizmo(widget);
     rotateGizmo = new RotateGizmo(widget);
     scaleGizmo = new ScaleGizmo(widget);

     cameraNode = widget->getSceneManager()->getRootSceneNode()->createChildSceneNode( "Camera Scene Node" );
     cameraNode->attachObject(widget->getCamera());


     Ogre::MeshManager::getSingletonPtr()->createPlane("xz_plane", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,Ogre::Plane(Ogre::Vector3::UNIT_Y, 0),8000.0f,8000.0f, 1,1,true,1,10,10,Ogre::Vector3::UNIT_Z);
     Ogre::Entity * xz_plane = widget->getSceneManager()->createEntity("xz_plane", "xz_plane");
     xz_plane->setMaterialName("Template/texture_map");
     xz_plane->setCastShadows(false);
     xz_plane->setQueryFlags(widget->PLANE_XZ_MASK);
     Ogre::MeshManager::getSingletonPtr()->createPlane("yz_plane", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,Ogre::Plane(Ogre::Vector3::UNIT_X, 0), 8000.0f, 8000.0f, 1, 1, true,1,10,10,Ogre::Vector3::UNIT_Y);
     Ogre::Entity * yz_plane = widget->getSceneManager()->createEntity("yz_plane", "yz_plane");
     yz_plane->setMaterialName("Template/texture_map");
     yz_plane->setCastShadows(false);
     yz_plane->setQueryFlags(widget->PLANE_XY_MASK);
     planeNode = widget->getSceneManager()->getRootSceneNode()->createChildSceneNode("planeNode");
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
  if(gizmoName == "lineX" || gizmoName =="lineXCone"     || gizmoName =="CircleX" || gizmoName =="lineXscale" || gizmoName =="cubX" )
  {
        gizmo->draw(true,false,false);
  }
  else if(gizmoName == "lineY" || gizmoName =="lineYCone" || gizmoName =="CircleY" || gizmoName =="lineYscale" || gizmoName =="cubY" )
  {
        gizmo->draw(false,true,false);
  }
  else if(gizmoName == "lineZ" || gizmoName =="lineZCone" || gizmoName =="CircleZ" || gizmoName =="lineZscale" || gizmoName =="cubZ")
  {
        gizmo->draw(false,false,true);
  }
  else if(gizmoName == "Quadr")
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
            intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, widget->PLANE_XZ_MASK,false );
            Ogre::Vector3 deltaPos =intersection - startMousePosition;
            translateGizmo->Translate(deltaPos.x,0,0);
            planeNode->translate(deltaPos.x,0,0);
            currentNode->translate(deltaPos.x,0,0);
            UpdateAxisSize(widget,translateGizmo,currentNode,gizmoName);
        }
        if(localGizmo)
        {
            intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, widget->PLANE_XZ_MASK,false,true,false,planeNode );
            Ogre::Vector3 deltaPos =intersection - startMousePosition;
            if(abs(deltaPos.x) <50)
            {
               translateGizmo->Translate(deltaPos.x,0,0,Ogre::Node::TS_LOCAL);
               currentNode->translate(deltaPos.x,0,0,Ogre::Node::TS_LOCAL);
               UpdateAxisSize(widget,translateGizmo,currentNode,gizmoName);
            }
        }

    }
    if(gizmoName == "lineY" || gizmoName =="lineYCone" )
    {
        if(globalGizmo)
        {
            intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, widget->PLANE_XY_MASK,false );
            Ogre::Vector3 deltaPos =intersection - startMousePosition;
            translateGizmo->Translate(0,deltaPos.y,0);
            planeNode->translate(0,deltaPos.y,0);
            currentNode->translate(0,deltaPos.y,0);
            UpdateAxisSize(widget,translateGizmo,currentNode,gizmoName);
        }
        if(localGizmo)
        {
            intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, widget->PLANE_XY_MASK,false,true,false,planeNode );
            Ogre::Vector3 deltaPos =intersection - startMousePosition;
            if(abs(deltaPos.y) <50)
            {
               translateGizmo->Translate(0,deltaPos.y,0,Ogre::Node::TS_LOCAL);
               currentNode->translate(0,deltaPos.y,0,Ogre::Node::TS_LOCAL);
               UpdateAxisSize(widget,translateGizmo,currentNode,gizmoName);
            }
        }

    }
    if(gizmoName == "lineZ" || gizmoName =="lineZCone" )
    {
        if(globalGizmo)
        {
            intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, widget->PLANE_XZ_MASK,false );
            Ogre::Vector3 deltaPos =intersection - startMousePosition;
            translateGizmo->Translate(0,0,deltaPos.z);
            planeNode->translate(0,0,deltaPos.z);
            currentNode->translate(0,0,deltaPos.z);
            UpdateAxisSize(widget,translateGizmo,currentNode,gizmoName);
        }
        if(localGizmo)
        {
            intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, widget->PLANE_XZ_MASK,false,true,false,planeNode );
            Ogre::Vector3 deltaPos =intersection - startMousePosition;
            qDebug()<<intersection.x<<" "<<intersection.y<<" "<<intersection.z<<" \n";
            if(abs(deltaPos.z) <50)
            {
               translateGizmo->Translate(0,0,deltaPos.z,Ogre::Node::TS_LOCAL);
               currentNode->translate(0,0,deltaPos.z,Ogre::Node::TS_LOCAL);
               UpdateAxisSize(widget,translateGizmo,currentNode,gizmoName);
            }
        }

    }
    if(gizmoName == "Quadr" )
    {
        intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, widget->PLANE_XZ_MASK,false );
        Ogre::Vector3 deltaPos =intersection - startMousePosition;
        translateGizmo->Translate(deltaPos.x,0,deltaPos.z);
        planeNode->translate(deltaPos.x,0,deltaPos.z);
        currentNode->translate(deltaPos.x,0,deltaPos.z);
        UpdateAxisSize(widget,translateGizmo,currentNode,gizmoName);
    }
    if(gizmoName == "CircleX" )
    {
        intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, widget->PLANE_XZ_MASK,false );
        Ogre::Vector3 deltaPos =intersection - startMousePosition;
        if(abs(deltaPos.x) <4)
           currentNode->rotate(Ogre::Vector3::UNIT_Z , Ogre::Radian(-deltaPos.x*0.1),Ogre::Node::TS_WORLD);
    }
    if(gizmoName == "CircleY" )
    {
        intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, widget->PLANE_XY_MASK,false );
        Ogre::Vector3 deltaPos =intersection - startMousePosition;
        if(abs(deltaPos.z) <4)
           {
              currentNode->rotate(Ogre::Vector3::UNIT_Y , Ogre::Radian(deltaPos.z*0.1),Ogre::Node::TS_WORLD);
           }
    }
    if(gizmoName == "CircleZ" )
    {
        intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, widget->PLANE_XZ_MASK,false );
        Ogre::Vector3 deltaPos =intersection - startMousePosition;
        if(abs(deltaPos.z) <4)
           currentNode->rotate(Ogre::Vector3::UNIT_X , Ogre::Radian(deltaPos.z*0.1),Ogre::Node::TS_WORLD);
    }
    if(gizmoName == "lineXscale" || gizmoName =="cubX")
    {
        intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, widget->PLANE_XZ_MASK,false );
        Ogre::Vector3 deltaPos =intersection - startMousePosition;
        currentNode->setScale(currentNode->getScale().x + deltaPos.x*0.1,currentNode->getScale().y,currentNode->getScale().z);
    }
    if(gizmoName == "lineYscale" || gizmoName =="cubY" )
    {
        intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, widget->PLANE_XY_MASK,false );
        Ogre::Vector3 deltaPos =intersection - startMousePosition;
        currentNode->setScale(currentNode->getScale().x,currentNode->getScale().y + deltaPos.y*0.1,currentNode->getScale().z);
    }
    if(gizmoName == "lineZscale" || gizmoName =="cubZ")
    {
        intersection=  RayManager::raycastIntersectionOnScene(widget,  x , y, widget->PLANE_XZ_MASK,false );
        Ogre::Vector3 deltaPos =intersection - startMousePosition;
        currentNode->setScale(currentNode->getScale().x,currentNode->getScale().y,currentNode->getScale().z + deltaPos.z*0.1);
    }
    startMousePosition = intersection;
}

void GizmoManager::UpdateAxisSize(OgreWidget * widget,IGizmo* gizmo,Ogre::SceneNode* currentNode,Ogre::String gizmoName)
{
    Ogre::Radian rad = widget->getCamera()->getFOVy( ) / 2;
    Ogre::Vector3 delta = widget->getCamera()->getRealPosition( ) - currentNode->getPosition( );
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
    }
    if (local)
    {
            _gizmoOrient = currentNode->getOrientation();
            translateGizmo->setOrientation(_gizmoOrient);
            planeNode->setOrientation(_gizmoOrient);
    }
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

void GizmoManager::SetStartPoint(Ogre::Vector3 startPoint)
{
    startMousePosition = startPoint;
}
