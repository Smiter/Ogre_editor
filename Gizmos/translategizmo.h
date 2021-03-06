#ifndef TRANSLATEGIZMO_H
#define TRANSLATEGIZMO_H

#include "Gizmos/IGizmo.h"

class TranslateGizmo : public IGizmo
{
public:
    TranslateGizmo();
    void draw(bool,bool,bool,bool=false);
    void show();
    void hide();
    void scale(float,float,float);
    Ogre::Vector3 getScale();
    void setPosition(Ogre::Vector3);
    void Translate(float,float,float,Ogre::Node::TransformSpace = Ogre::Node::TS_WORLD);
    void setOrientation(Ogre::Quaternion);

private:

    Ogre::SceneNode* MainAxisNode;
    Ogre::ManualObject* lineX;
    Ogre::SceneNode* NodelineX;
    Ogre::ManualObject* lineY;
    Ogre::SceneNode* NodelineY;
    Ogre::ManualObject* lineZ;
    Ogre::SceneNode* NodelineZ;
    Ogre::ManualObject* lineXCone;
    Ogre::SceneNode* NodelineXCone;
    Ogre::ManualObject* lineYCone;
    Ogre::SceneNode* NodelineYCone;
    Ogre::ManualObject* lineZCone;
    Ogre::SceneNode* NodelineZCone;
    Ogre::ManualObject* Quadr;
    Ogre::SceneNode* NodeQuadr;





};

#endif // TRANSLATEGIZMO_H
