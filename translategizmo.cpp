#include "translategizmo.h"

TranslateGizmo::TranslateGizmo(OgreWidget * widget)
{
    ogreWidget = widget;
    MainAxisNode = ogreWidget->getSceneManager()->getRootSceneNode()->createChildSceneNode("MainAxisNode");
    lineX =  ogreWidget->getSceneManager()->createManualObject("lineX");
    NodelineX = MainAxisNode->createChildSceneNode("NodelineX");
    lineY =  ogreWidget->getSceneManager()->createManualObject("lineY");
    NodelineY = MainAxisNode->createChildSceneNode("NodelineY");
    lineZ =  ogreWidget->getSceneManager()->createManualObject("lineZ");
    NodelineZ = MainAxisNode->createChildSceneNode("NodelineZ");
    lineXCone=  ogreWidget->getSceneManager()->createManualObject("lineXCone");
    NodelineXCone = MainAxisNode->createChildSceneNode("NodelineXCone");
    lineYCone=  ogreWidget->getSceneManager()->createManualObject("lineYCone");
    NodelineYCone = MainAxisNode->createChildSceneNode("NodelineYCone");
    lineZCone=  ogreWidget->getSceneManager()->createManualObject("lineZCone");
    NodelineZCone = MainAxisNode->createChildSceneNode("NodelineZCone");
    Quadr=  ogreWidget->getSceneManager()->createManualObject("Quadr");
    NodeQuadr = MainAxisNode->createChildSceneNode("NodeQuadr");
    NodelineX->attachObject(lineX);
    NodelineY->attachObject(lineY);
    NodelineZ->attachObject(lineZ);
    NodeQuadr->attachObject(Quadr);
    NodelineXCone->attachObject(lineXCone);
    NodelineYCone->attachObject(lineYCone);
    NodelineZCone->attachObject(lineZCone);
    lineX->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);
    lineY->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);
    lineZ->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);
    lineXCone->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);
    lineYCone->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);
    lineZCone->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);
    Quadr->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);

    lineX->setQueryFlags(widget->AXIS_MASK_XYZ);
    lineY->setQueryFlags(widget->AXIS_MASK_XYZ);
    lineZ->setQueryFlags(widget->AXIS_MASK_XYZ);
    lineXCone->setQueryFlags(widget->AXIS_MASK_XYZ);
    lineYCone->setQueryFlags(widget->AXIS_MASK_XYZ);
    lineZCone->setQueryFlags(widget->AXIS_MASK_XYZ);
    Quadr->setQueryFlags(widget->AXIS_MASK_XYZ);
    isVisible=true;
    boundsize = 70;
    draw(false,false,false,false);
    hide();

}

void TranslateGizmo::draw(bool lightedX,bool lightedY,bool lightedZ ,bool lightedQuadr)
{    
    if(isVisible)
    {


    float bounds = boundsize;
    lineX->clear();
    lineXCone->clear();

    if (lightedX)
            lineX->begin("LightedMaterial", Ogre::RenderOperation::OT_LINE_LIST);
    else
            lineX->begin("Gizmo_Translate_X", Ogre::RenderOperation::OT_LINE_LIST);

    lineX->position(0, 0, 0);
    lineX->position(bounds, 0, 0);
    lineX->end();

    lineX->setBoundingBox(Ogre::AxisAlignedBox( Ogre::Vector3( 0 , -0.1*(bounds/2), -0.2*(bounds/2) ), Ogre::Vector3(  bounds, 0.1*(bounds/2), 0.2*(bounds/2) )));
    NodelineX->_updateBounds();

    float step = float( Ogre::Math::PI/5 );
    Ogre::Vector3 a;
    const float size =bounds * 0.08;
    const float len = bounds;

    if (lightedX)
            lineXCone->begin("LightedMaterial", Ogre::RenderOperation::OT_TRIANGLE_FAN);
    else
            lineXCone->begin("Gizmo_Translate_X", Ogre::RenderOperation::OT_TRIANGLE_FAN);

    lineXCone->position( bounds,0,0 );

    for ( float i = 0; i < Ogre::Math::PI * 2; i += step )
    {
            a = Ogre::Vector3( len, size * sin ( i ), size * cos ( i ) );
            lineXCone->position( a );
    }
    lineXCone->end();

    if (lightedX)
            lineXCone->begin("LightedMaterial", Ogre::RenderOperation::OT_TRIANGLE_FAN);
    else
            lineXCone->begin("Gizmo_Translate_X", Ogre::RenderOperation::OT_TRIANGLE_FAN);

    lineXCone->position( bounds+bounds/3,0,0 );

    for ( float i = Ogre::Math::PI * 2; i >-1; i -= step )
    {
            a = Ogre::Vector3( bounds, size * sin ( i ), size * cos ( i ) );
            lineXCone->position( a );
    }
    lineXCone->end();

    lineY->clear();
    lineYCone->clear();

    if (lightedY)
            lineY->begin("LightedMaterial", Ogre::RenderOperation::OT_LINE_LIST);
    else
            lineY->begin("Gizmo_Translate_Y", Ogre::RenderOperation::OT_LINE_LIST);

    lineY->position(0, 0, 0);
    lineY->position(0, bounds, 0);
    lineY->end();

    lineY->setBoundingBox(Ogre::AxisAlignedBox( Ogre::Vector3( -0.1*(bounds/2) , 0, -0.2*(bounds/2) ), Ogre::Vector3(  0.1*(bounds/2), bounds, 0.2*(bounds/2) )));
    NodelineY->_updateBounds();

    if (lightedY)
            lineYCone->begin("LightedMaterial", Ogre::RenderOperation::OT_TRIANGLE_FAN);
    else
            lineYCone->begin("Gizmo_Translate_Y", Ogre::RenderOperation::OT_TRIANGLE_FAN);

    lineYCone->position( 0,bounds,0 );

    for ( float i = 0; i < Ogre::Math::PI * 2; i += step )
    {
            a = Ogre::Vector3(size * sin ( i ), len,  size * cos ( i ) );
            lineYCone->position( a );
    }
    lineYCone->end();

    if (lightedY)
            lineYCone->begin("LightedMaterial", Ogre::RenderOperation::OT_TRIANGLE_FAN);
    else
            lineYCone->begin("Gizmo_Translate_Y", Ogre::RenderOperation::OT_TRIANGLE_FAN);

    lineYCone->position( 0,bounds+bounds/3,0 );


    for ( float i = Ogre::Math::PI * 2; i >-1; i -= step )
    {
            a = Ogre::Vector3( size * sin ( i ), len , size * cos ( i ) );
            lineYCone->position( a );
    }
    lineYCone->end();


    lineZ->clear();
    lineZCone->clear();

    if (lightedZ)
            lineZ->begin("LightedMaterial", Ogre::RenderOperation::OT_LINE_LIST);
    else
            lineZ->begin("Gizmo_Translate_Z", Ogre::RenderOperation::OT_LINE_LIST);

    lineZ->position(0, 0, 0);
    lineZ->position(0, 0, bounds);
    lineZ->end();

    lineZ->setBoundingBox(Ogre::AxisAlignedBox( Ogre::Vector3( -0.2*(bounds/2) , -0.1*(bounds/2), 0 ), Ogre::Vector3(  0.2*(bounds/2), 0.1*(bounds/2), bounds )));
    NodelineZ->_updateBounds();

    if (lightedZ)
            lineZCone->begin("LightedMaterial", Ogre::RenderOperation::OT_TRIANGLE_FAN);
    else
            lineZCone->begin("Gizmo_Translate_Z", Ogre::RenderOperation::OT_TRIANGLE_FAN);

    lineZCone->position( 0,0,bounds );

    for ( float i = 0; i < Ogre::Math::PI * 2; i += step )
    {
            a = Ogre::Vector3(size * sin ( i ),  size * cos ( i ), len );
            lineZCone->position( a );
    }
    lineZCone->end();

    if (lightedZ)
            lineZCone->begin("LightedMaterial", Ogre::RenderOperation::OT_TRIANGLE_FAN);
    else
            lineZCone->begin("Gizmo_Translate_Z", Ogre::RenderOperation::OT_TRIANGLE_FAN);

    lineZCone->position( 0,0,bounds+bounds/3 );

    for ( float i = Ogre::Math::PI * 2; i >-1; i -= step )
    {
            a = Ogre::Vector3( size * sin ( i ) , size * cos ( i ), len );
            lineZCone->position( a );
    }
    lineZCone->end();

    Quadr->clear();
    if (lightedQuadr)
            Quadr->begin("LightedMaterial", Ogre::RenderOperation::OT_TRIANGLE_FAN);
    else
            Quadr->begin("Gizmo_Translate_Quadro", Ogre::RenderOperation::OT_TRIANGLE_FAN);

    Quadr->position(0,0,0);
    Quadr->position(0,0,(bounds+bounds/3)/5);
    Quadr->position((bounds+bounds/3)/5,0,(bounds+bounds/3)/5);
    Quadr->position((bounds+bounds/3)/5,0,0);
    Quadr->end();

    Quadr->setBoundingBox(Ogre::AxisAlignedBox( Ogre::Vector3( 0 , 0, 0 ), Ogre::Vector3( (bounds+bounds/3)/5 , 0.1, (bounds+bounds/3)/5 )));
    NodeQuadr->_updateBounds();

    }

}

void TranslateGizmo::show()
{
    MainAxisNode->setVisible(true);
    isVisible=true;
}

void TranslateGizmo::hide()
{
    MainAxisNode->setVisible(false);
    MainAxisNode->setPosition(10000,10000,10000);
    isVisible=false;
}

void TranslateGizmo::setOrientation(Ogre::Quaternion orientation)
{
   MainAxisNode->setOrientation(orientation);
}


void TranslateGizmo::setPosition(Ogre::Vector3 position)
{
   MainAxisNode->setPosition(position);
}

void TranslateGizmo::Translate(float x, float y, float z,Ogre::Node::TransformSpace space)
{
   MainAxisNode->translate(x,y,z,space);
}


