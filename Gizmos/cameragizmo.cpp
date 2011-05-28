#include "Gizmos/cameragizmo.h"

#include "mainwindow.h"

CameraGizmo::CameraGizmo()
{
     firstDrawGizmo=false;

     NodeCameraGizmoSupport = GizmoManager::cameraNode->createChildSceneNode("NodeCameraGizmoSupport");
     CamGizmo= NodeCameraGizmoSupport->createChildSceneNode("CameraGizmo");
     CameraGizmoCube = MainWindow::getInstance()->ogreWindow->getSceneManager()->createEntity("ÑameraGizmoCube",Ogre::SceneManager::PT_CUBE);
     NodeCameraGizmo = CamGizmo->createChildSceneNode("NodeCameraGizmoCube");
     NodeCameraGizmo->attachObject( CameraGizmoCube );
     NodeCameraGizmo->setScale(0.0003,0.0003,0.0003);
     NodeCameraGizmoSupport->setPosition(MainWindow::getInstance()->ogreWindow->getCamera()->getPosition());
     CameraGizmoConusZ = MainWindow::getInstance()->ogreWindow->getSceneManager()->createManualObject("CameraGizmoConusZ");
     NodeCameraGizmoConusZ = CamGizmo->createChildSceneNode("NodeCameraGizmoConusZ");
     NodeCameraGizmoConusZ->attachObject( CameraGizmoConusZ );
     CameraGizmoConusZ->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);

     CameraGizmoConusX = MainWindow::getInstance()->ogreWindow->getSceneManager()->createManualObject("CameraGizmoConusX");
     NodeCameraGizmoConusX = CamGizmo->createChildSceneNode("NodeCameraGizmoConusX");
     NodeCameraGizmoConusX->attachObject( CameraGizmoConusX );
     CameraGizmoConusX->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);

     CameraGizmoConusY = MainWindow::getInstance()->ogreWindow->getSceneManager()->createManualObject("CameraGizmoConusY");
     NodeCameraGizmoConusY = CamGizmo->createChildSceneNode("NodeCameraGizmoConusY");
     NodeCameraGizmoConusY->attachObject( CameraGizmoConusY );     
     CameraGizmoConusY->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);

     CameraGizmoCube->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);

     CameraGizmoConusX->setQueryFlags(OgreWidget::AXIS_CAMERA);
     CameraGizmoConusY->setQueryFlags(OgreWidget::AXIS_CAMERA);
     CameraGizmoConusZ->setQueryFlags(OgreWidget::AXIS_CAMERA);
     CameraGizmoCube->setQueryFlags(OgreWidget::AXIS_CAMERA);
     CameraGizmoCube->setMaterialName("Gizmo_Translatesda");
     draw(false,false,false,false);
}


void CameraGizmo::draw(bool lightedX, bool lightedY, bool lightedZ,bool lightedQuadr)
{
    CameraGizmoConusX->clear();
    CameraGizmoConusY->clear();
    CameraGizmoConusZ->clear();
    float radius = 0.18;
    float step = float( Ogre::Math::PI/5 );
    Ogre::Vector3 a;
    const float size =radius * 0.08;
    const float len = radius;

    if (lightedZ)
            CameraGizmoConusZ->begin("LightedMaterialForCameraGizmo", Ogre::RenderOperation::OT_TRIANGLE_FAN);
    else
            CameraGizmoConusZ->begin("CameraGizmoMaterialZ", Ogre::RenderOperation::OT_TRIANGLE_FAN);

    CameraGizmoConusZ->position(0,0,radius );

    for ( float i = 0; i < Ogre::Math::PI * 2; i += step )
    {
            a = Ogre::Vector3(size * sin ( i ),  size * cos ( i ), len );
            CameraGizmoConusZ->position( a );
    }
    CameraGizmoConusZ->end();

    if (lightedZ)
            CameraGizmoConusZ->begin("LightedMaterialForCameraGizmo", Ogre::RenderOperation::OT_TRIANGLE_FAN);
    else
            CameraGizmoConusZ->begin("CameraGizmoMaterialZ", Ogre::RenderOperation::OT_TRIANGLE_FAN);

    CameraGizmoConusZ->position( 0,0,radius-radius/3 );

    for ( float i = Ogre::Math::PI * 2; i >-1; i -= step )
    {
            a = Ogre::Vector3( size * sin ( i ) , size * cos ( i ), len );
            CameraGizmoConusZ->position( a );
    }
    CameraGizmoConusZ->end();



    if (lightedX)
            CameraGizmoConusX->begin("LightedMaterialForCameraGizmo", Ogre::RenderOperation::OT_TRIANGLE_FAN);
    else
            CameraGizmoConusX->begin("CameraGizmoMaterialX", Ogre::RenderOperation::OT_TRIANGLE_FAN);

    CameraGizmoConusX->position( radius,0,0 );

    for ( float i = 0; i < Ogre::Math::PI * 2; i += step )
    {
            a = Ogre::Vector3( len, size * sin ( i ), size * cos ( i ) );
            CameraGizmoConusX->position( a );
    }
    CameraGizmoConusX->end();

    if (lightedX)
            CameraGizmoConusX->begin("LightedMaterialForCameraGizmo", Ogre::RenderOperation::OT_TRIANGLE_FAN);
    else
            CameraGizmoConusX->begin("CameraGizmoMaterialX", Ogre::RenderOperation::OT_TRIANGLE_FAN);

    CameraGizmoConusX->position( radius-radius/3,0,0 );

    for ( float i = Ogre::Math::PI * 2; i >-1; i -= step )
    {
            a = Ogre::Vector3( radius, size * sin ( i ), size * cos ( i ) );
            CameraGizmoConusX->position( a );
    }
    CameraGizmoConusX->end();


    if (lightedY)
            CameraGizmoConusY->begin("LightedMaterialForCameraGizmo", Ogre::RenderOperation::OT_TRIANGLE_FAN);
    else
            CameraGizmoConusY->begin("CameraGizmoMaterialY", Ogre::RenderOperation::OT_TRIANGLE_FAN);

    CameraGizmoConusY->position( 0,radius,0 );

    for ( float i = 0; i < Ogre::Math::PI * 2; i += step )
    {
            a = Ogre::Vector3(size * sin ( i ), len,  size * cos ( i ) );
            CameraGizmoConusY->position( a );
    }
    CameraGizmoConusY->end();

    if (lightedY)
            CameraGizmoConusY->begin("LightedMaterialForCameraGizmo", Ogre::RenderOperation::OT_TRIANGLE_FAN);
    else
            CameraGizmoConusY->begin("CameraGizmoMaterialY", Ogre::RenderOperation::OT_TRIANGLE_FAN);

    CameraGizmoConusY->position( 0,radius-radius/3,0 );


    for ( float i = Ogre::Math::PI * 2; i >-1; i -= step )
    {
            a = Ogre::Vector3( size * sin ( i ), len , size * cos ( i ) );
            CameraGizmoConusY->position( a );
    }
    CameraGizmoConusY->end();
    if (lightedQuadr)
            CameraGizmoCube->setMaterialName("LightedMaterialForCameraGizmo");
    else
            CameraGizmoCube->setMaterialName("CameraGizmoCube");

}

void CameraGizmo::show()
{
    NodeCameraGizmo->setVisible(true);
}
void CameraGizmo::hide()
{
    NodeCameraGizmo->setVisible(false);
}
void CameraGizmo::setPosition(Ogre::Vector3 position)
{
    CamGizmo->_setDerivedPosition(position);
    if(!firstDrawGizmo)
    {
        NodeCameraGizmoConusZ->_setDerivedPosition(Ogre::Vector3(position.x,position.y,position.z-0.1));
        NodeCameraGizmoConusX->_setDerivedPosition(Ogre::Vector3(position.x-0.1,position.y,position.z));
        NodeCameraGizmoConusY->_setDerivedPosition(Ogre::Vector3(position.x,position.y-0.1,position.z));      
        firstDrawGizmo=true;
    }

}
void  CameraGizmo::setOrientation(float w, float x, float y,float z)
{
    CamGizmo->setOrientation(w,x,y,z);
}
void CameraGizmo::Rotate(Ogre::Vector3 axis,Ogre::Degree degree ,Ogre::Node::TransformSpace space)
{
    CamGizmo->rotate(axis,degree,space);   
}

void  CameraGizmo::scale(float x, float y, float z)
{
    NodeCameraGizmoSupport->setScale(x,y,z);
}
Ogre::Vector3 CameraGizmo::getScale()
{
    return NodeCameraGizmoSupport->getScale();
}

