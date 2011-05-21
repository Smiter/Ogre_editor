#ifndef GIZMOMANAGER_H
#define GIZMOMANAGER_H
#include "IGizmo.h"
#include "translategizmo.h"
class RotateGizmo;
class ScaleGizmo;
class CameraGizmo;
#include "QtWidget.h"
#include "rotategizmo.h"
#include "scalegizmo.h"

class GizmoManager
{
public:
   GizmoManager( );
  static void CreateGizmo(OgreWidget * widget);

  static void SetLightOff(IGizmo*);
  static void SetLightOn(IGizmo*,Ogre::String);
  static void SetGizmoPosition(IGizmo*,Ogre::Vector3);
  static void Show(IGizmo*);
  static void Hide(IGizmo*);
  static void ManipulationWithGizmo(Ogre::String, OgreWidget*,Ogre::SceneNode*,float,float,bool,bool);
  static TranslateGizmo * getTranslateGizmo();
  static RotateGizmo * getRotateGizmo();
  static ScaleGizmo * getScaleGizmo();  
  static void SetStartPoint(Ogre::Vector3);
  static Ogre::SceneNode * planeNode;
  static void UpdateAxisSize(OgreWidget *,IGizmo*,Ogre::SceneNode*,Ogre::String="");
  static void ConvertGizmo(bool,bool,Ogre::SceneNode*);
  static Ogre::SceneNode * cameraNode;
private:
  static TranslateGizmo * translateGizmo;
  static RotateGizmo * rotateGizmo;
  static ScaleGizmo * scaleGizmo; 
  static Ogre::Vector3 startMousePosition;

};

#endif // GIZMOMANAGER_H
