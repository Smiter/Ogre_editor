#include "rotategizmo.h"

RotateGizmo::RotateGizmo(OgreWidget * widget)
{
    ogreWidget = widget;
    MainRotateNode = widget->getSceneManager()->getRootSceneNode()->createChildSceneNode("MainRotateNode");
    CircleY=  widget->getSceneManager()->createManualObject("CircleY");
    NodeCircleY = MainRotateNode->createChildSceneNode("NodeCircleY");
    CircleX=  widget->getSceneManager()->createManualObject("CircleX");
    NodeCircleX = MainRotateNode->createChildSceneNode("NodeCircleX");
    CircleZ=  widget->getSceneManager()->createManualObject("CircleZ");
    NodeCircleZ = MainRotateNode->createChildSceneNode("NodeCircleZ");
    NodeCircleX->attachObject(CircleX);
    NodeCircleY->attachObject(CircleY);
    NodeCircleZ->attachObject(CircleZ);
    CircleX->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);
    CircleY->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);
    CircleZ->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);
    CircleX->setQueryFlags(widget->AXIS_MASK_XYZ);
    CircleY->setQueryFlags(widget->AXIS_MASK_XYZ);
    CircleZ->setQueryFlags(widget->AXIS_MASK_XYZ);
    isVisible=true;
    boundsize = 70;
    draw(false,false,false,false);
    hide();
}

void RotateGizmo::draw(bool lightedX,bool lightedY,bool lightedZ ,bool lightedQuadr)
{
    if(isVisible)
    {


    float bounds = boundsize;
    CircleX->clear();
    if (lightedX)
            CircleX->begin("LightedMaterial", Ogre::RenderOperation::OT_LINE_STRIP);
    else
            CircleX->begin("Gizmo_Translate_X", Ogre::RenderOperation::OT_LINE_STRIP);
    float const radius = bounds;
    float const accuracy = 35;
    unsigned point_index = 0;
    for(float theta = 0; theta <= 2 * Ogre::Math::PI; theta += Ogre::Math::PI / accuracy) {
            CircleX->position(radius * cos(theta), radius * sin(theta) , 0 );
            CircleX->index(point_index++);
    }
    CircleX->index(0);
    CircleX->end();

    CircleX->setBoundingBox(Ogre::AxisAlignedBox( Ogre::Vector3( -radius , -radius, -0.2 ), Ogre::Vector3( radius , radius, 0.2 )));
    NodeCircleX->_updateBounds();

    CircleY->clear();
    if (lightedY)
            CircleY->begin("LightedMaterial", Ogre::RenderOperation::OT_LINE_STRIP);
    else
            CircleY->begin("Gizmo_Translate_Y", Ogre::RenderOperation::OT_LINE_STRIP);

    point_index = 0;
    for(float theta = 0; theta <= 2 * Ogre::Math::PI; theta += Ogre::Math::PI / accuracy) {
            CircleY->position(radius * cos(theta), 0, radius * sin(theta));
            CircleY->index(point_index++);
    }
    CircleY->index(0);
    CircleY->end();

    CircleY->setBoundingBox(Ogre::AxisAlignedBox( Ogre::Vector3( -bounds , -0.2, -bounds ), Ogre::Vector3( bounds , 0.2, bounds )));
    NodeCircleY->_updateBounds();

    CircleZ->clear();
    if (lightedZ)
            CircleZ->begin("LightedMaterial", Ogre::RenderOperation::OT_LINE_STRIP);
    else
            CircleZ->begin("Gizmo_Translate_Z", Ogre::RenderOperation::OT_LINE_STRIP);

    point_index = 0;
    for(float theta = 0; theta <= 2 * Ogre::Math::PI; theta += Ogre::Math::PI / accuracy) {
            CircleZ->position(0, radius * sin(theta) ,radius * cos(theta) );
            CircleZ->index(point_index++);
    }
    CircleZ->index(0);
    CircleZ->end();

    CircleZ->setBoundingBox(Ogre::AxisAlignedBox( Ogre::Vector3( -0.2 , -bounds, -bounds ), Ogre::Vector3( 0.2 , bounds, bounds )));
    NodeCircleZ->_updateBounds();

    }

}

void RotateGizmo::show()
{
    MainRotateNode->setVisible(true);
    isVisible=true;
}

void RotateGizmo::hide()
{
    MainRotateNode->setVisible(false);
    MainRotateNode->setPosition(10000,10000,10000);
    isVisible=false;
}


void RotateGizmo::setPosition(Ogre::Vector3 position)
{
   MainRotateNode->setPosition(position);
}
