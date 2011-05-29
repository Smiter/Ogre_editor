#ifndef ROTATEGIZMO_H
#define ROTATEGIZMO_H

#include "Gizmos/IGizmo.h"

class RotateGizmo : public IGizmo
{
public:
    RotateGizmo();
     void draw(bool,bool,bool,bool=false);
     void show();
     void hide();
     void scale(float,float,float);
     Ogre::Vector3 getScale();
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
