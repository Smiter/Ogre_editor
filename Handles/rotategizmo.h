#ifndef ROTATEGIZMO_H
#define ROTATEGIZMO_H

#include "IGizmo.h"

class RotateGizmo : public IGizmo
{
public:
    RotateGizmo();
     void draw(bool,bool,bool,bool=false);
     void show();
     void hide();
     void setPosition(Ogre::Vector3);

 private:
    Ogre::SceneNode* MainRotateNode;
    Ogre::ManualObject* CircleX;
    Ogre::SceneNode* NodeCircleX;
    Ogre::ManualObject* CircleY;
    Ogre::SceneNode* NodeCircleY;
    Ogre::ManualObject* CircleZ;
    Ogre::SceneNode* NodeCircleZ;
};

#endif // B_H
