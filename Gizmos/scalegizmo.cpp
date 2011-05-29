#include "Gizmos/scalegizmo.h"

#include "mainwindow.h"

ScaleGizmo::ScaleGizmo()
{    
    MainScaleNode = MainWindow::getInstance()->ogreWindow->getSceneManager()->getRootSceneNode()->createChildSceneNode("MainScaleNode");
    lineXScale =  MainWindow::getInstance()->ogreWindow->getSceneManager()->createManualObject("lineXscale");
    NodelineXScale = MainScaleNode->createChildSceneNode("NodelineXscale");
    lineYScale =  MainWindow::getInstance()->ogreWindow->getSceneManager()->createManualObject("lineYscale");
    NodelineYScale = MainScaleNode->createChildSceneNode("NodelineYscale");
    lineZScale =  MainWindow::getInstance()->ogreWindow->getSceneManager()->createManualObject("lineZscale");
    NodelineZScale = MainScaleNode->createChildSceneNode("NodelineZscale");

    NodescaleXQuadr = MainScaleNode->createChildSceneNode("NodescaleXQuadr");
    NodescaleYQuadr = MainScaleNode->createChildSceneNode("NodescaleYQuadr");
    NodescaleZQuadr = MainScaleNode->createChildSceneNode("NodescaleZQuadr");

    ScaleXent = MainWindow::getInstance()->ogreWindow->getSceneManager()->createEntity("cubX",Ogre::SceneManager::PT_CUBE);
    NodescaleXQuadr->attachObject( ScaleXent );
    ScaleXent->setCastShadows(false);
    ScaleYent = MainWindow::getInstance()->ogreWindow->getSceneManager()->createEntity("cubY",Ogre::SceneManager::PT_CUBE);
    NodescaleYQuadr->attachObject( ScaleYent );
    ScaleYent->setCastShadows(false);
    ScaleZent = MainWindow::getInstance()->ogreWindow->getSceneManager()->createEntity("cubZ",Ogre::SceneManager::PT_CUBE);
    NodescaleZQuadr->attachObject( ScaleZent );
    ScaleZent->setCastShadows(false);

    NodelineXScale->attachObject(lineXScale);
    NodelineYScale->attachObject(lineYScale);
    NodelineZScale->attachObject(lineZScale);


    lineXScale->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);
    lineYScale->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);
    lineZScale->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);

    ScaleXent->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);
    ScaleYent->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);
    ScaleZent->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);

    lineXScale->setQueryFlags(OgreWidget::AXIS_MASK_XYZ);
    lineYScale->setQueryFlags(OgreWidget::AXIS_MASK_XYZ);
    lineZScale->setQueryFlags(OgreWidget::AXIS_MASK_XYZ);
    ScaleXent->setQueryFlags(OgreWidget::AXIS_MASK_XYZ);
    ScaleYent->setQueryFlags(OgreWidget::AXIS_MASK_XYZ);
    ScaleZent->setQueryFlags(OgreWidget::AXIS_MASK_XYZ);
    isVisible=true;
    boundsize = 70;
    draw(false,false,false,false);
    hide();
}

void ScaleGizmo::draw(bool lightedX,bool lightedY,bool lightedZ ,bool lightedQuadr)
{
    if(isVisible)
    {


    float bounds = boundsize;
    lineXScale->clear();
    if (lightedX)
    {
            lineXScale->begin("LightedMaterial", Ogre::RenderOperation::OT_LINE_LIST);
            ScaleXent->setMaterialName("LightedMaterial");
    }
    else
    {
            lineXScale->begin("Gizmo_Translate_X", Ogre::RenderOperation::OT_LINE_LIST);
            ScaleXent->setMaterialName("Gizmo_Translate_X");
    }

    lineXScale->position(0, 0, 0);
    lineXScale->position(bounds, 0, 0);
    lineXScale->end();

    NodescaleXQuadr->setPosition(bounds, 0, 0);
    NodescaleXQuadr->setScale(bounds*0.001, bounds*0.001, bounds*0.001);

    lineXScale->setBoundingBox(Ogre::AxisAlignedBox( Ogre::Vector3( 0 , -0.1*(bounds/2), -0.2*(bounds/2) ), Ogre::Vector3(  bounds, 0.1*(bounds/2), 0.2*(bounds/2) )));
    NodelineXScale->_updateBounds();

    lineYScale->clear();

    if (lightedY)
    {
            lineYScale->begin("LightedMaterial", Ogre::RenderOperation::OT_LINE_LIST);
            ScaleYent->setMaterialName("LightedMaterial");
    }
    else
    {
            lineYScale->begin("Gizmo_Translate_Y", Ogre::RenderOperation::OT_LINE_LIST);
            ScaleYent->setMaterialName("Gizmo_Translate_Y");
    }

    lineYScale->position(0, 0, 0);
    lineYScale->position(0, bounds, 0);
    lineYScale->end();
    NodescaleYQuadr->setPosition(0, bounds, 0);
    NodescaleYQuadr->setScale(bounds*0.001, bounds*0.001, bounds*0.001);

    lineYScale->setBoundingBox(Ogre::AxisAlignedBox( Ogre::Vector3( -0.1*(bounds/2) , 0, -0.2*(bounds/2) ), Ogre::Vector3(  0.1*(bounds/2), bounds, 0.2*(bounds/2) )));
    NodelineYScale->_updateBounds();

    lineZScale->clear();
    if (lightedZ)
    {
            lineZScale->begin("LightedMaterial", Ogre::RenderOperation::OT_LINE_LIST);
            ScaleZent->setMaterialName("LightedMaterial");
    }
    else
    {
            lineZScale->begin("Gizmo_Translate_Z", Ogre::RenderOperation::OT_LINE_LIST);
            ScaleZent->setMaterialName("Gizmo_Translate_Z");
    }

    lineZScale->position(0, 0, 0);
    lineZScale->position(0, 0, bounds);
    lineZScale->end();

    NodescaleZQuadr->setPosition(0, 0, bounds);
    NodescaleZQuadr->setScale(bounds*0.001, bounds*0.001, bounds*0.001);

    lineZScale->setBoundingBox(Ogre::AxisAlignedBox( Ogre::Vector3( -0.2*(bounds/2) , -0.1*(bounds/2), 0 ), Ogre::Vector3(  0.2*(bounds/2), 0.1*(bounds/2), bounds )));
    NodelineZScale->_updateBounds();

    }

}

void ScaleGizmo::show()
{
    MainScaleNode->setVisible(true);
    isVisible=true;
}

void ScaleGizmo::hide()
{
    MainScaleNode->setVisible(false);
    MainScaleNode->setPosition(10000,10000,10000);
    isVisible=false;
}


void ScaleGizmo::setPosition(Ogre::Vector3 position)
{
   MainScaleNode->setPosition(position);
}

void ScaleGizmo::setOrientation(Ogre::Quaternion orientation)
{
   MainScaleNode->setOrientation(orientation);
}


void  ScaleGizmo::scale(float x, float y, float z)
{
    MainScaleNode->setScale(x,y,z);
}

Ogre::Vector3 ScaleGizmo::getScale()
{
    return MainScaleNode->getScale();
}
