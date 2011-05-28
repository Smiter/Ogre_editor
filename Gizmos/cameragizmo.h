#ifndef CAMERAGIZMO_H
#define CAMERAGIZMO_H

#include "Gizmos/IGizmo.h"

class CameraGizmo : public IGizmo
{
public:
    CameraGizmo();
    void draw(bool,bool,bool,bool);
    void show();
    void hide();
    void scale(float,float,float);
    Ogre::Vector3 getScale();
    void setPosition(Ogre::Vector3);
    void setOrientation(float,float,float,float);
    void Rotate(Ogre::Vector3,Ogre::Degree,Ogre::Node::TransformSpace);

    Ogre::SceneNode* NodeCameraGizmoSupport;   //нод в камерной позиции. парент камеры гизмо. нужен для ротейта.
private:


    Ogre::SceneNode* NodeCameraGizmo; //нод к которому приатачен куб и конусы.

    Ogre::SceneNode* NodeCameraGizmoConusZ;
    Ogre::SceneNode* NodeCameraGizmoConusY;
    Ogre::SceneNode* NodeCameraGizmoConusX;
    Ogre::Entity * CameraGizmoCube;
    Ogre::SceneNode* CamGizmo;  // парент для NodeCameraGimo
    Ogre::ManualObject* CameraGizmoConusZ;
    Ogre::ManualObject* CameraGizmoConusX;
    Ogre::ManualObject* CameraGizmoConusY;
    bool firstDrawGizmo;

};

#endif // CAMERAGIZMO_H
