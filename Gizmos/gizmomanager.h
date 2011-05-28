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
#include "cameragizmo.h"
#include "mainwindow.h"
class GizmoManager
{
public:
   GizmoManager( );
  static void CreateGizmo();

  static void SetLightOff(IGizmo*);
  static void SetLightOn(IGizmo*,Ogre::String);
  static void SetGizmoPosition(IGizmo*,Ogre::Vector3);
  static void Show(IGizmo*);
  static void Hide(IGizmo*);
  static void ManipulationWithGizmo(Ogre::String, OgreWidget*,Ogre::SceneNode*,float,float,bool,bool);
  static TranslateGizmo * getTranslateGizmo();
  static RotateGizmo * getRotateGizmo();
  static ScaleGizmo * getScaleGizmo();  
  static CameraGizmo * getCameraGizmo();
  static void SetStartPoint(Ogre::Vector3);
  static Ogre::SceneNode * planeNode;
  static void UpdateAxisSize(IGizmo*,Ogre::SceneNode*,Ogre::String,float size);
  static void ConvertGizmo(bool,bool,Ogre::SceneNode*);
  static Ogre::SceneNode * cameraNode;
  static void ClickOnCameraGizmo(Ogre::String);
  static bool cameraGizmoisClicked;
  static void ActionsAfterResizeWindow(float,float);
private:
  static TranslateGizmo * translateGizmo;
  static RotateGizmo * rotateGizmo;
  static ScaleGizmo * scaleGizmo; 
  static CameraGizmo * cameraGizmo;
  static Ogre::Vector3 startMousePosition;
  static void createMaterials();

};

#endif // GIZMOMANAGER_H
