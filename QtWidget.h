#ifndef __OGREWIDGET_H__
#define __OGREWIDGET_H__
class TranslateGizmo;
class RayManager;

#include <QtOpenGL/QGLWidget>
#include <QDir>
#include "Handles/raymanager.h"
#include "Handles/gizmomanager.h"
#include "ui_mainwindow.h"

class OgreWidget : public QGLWidget
{

 Q_OBJECT

 public:


  OgreWidget( QWidget *parent=0 );
  virtual ~OgreWidget();

private:

  virtual void initializeGL();
  virtual void resizeGL( int, int );
  virtual void paintGL();
  void init( std::string, std::string, std::string );
  void initResourses();
  virtual Ogre::RenderSystem* chooseRenderer( Ogre::RenderSystemList* );
  // Events
  virtual  void mousePressEvent ( QMouseEvent * event );
  virtual  void mouseMoveEvent ( QMouseEvent * event );
  virtual  void keyPressEvent ( QKeyEvent * event );
  virtual  void wheelEvent ( QWheelEvent * event );
  virtual  void keyReleaseEvent ( QKeyEvent * event );  
  void dropEvent(QDropEvent *event);
  void dragEnterEvent(QDragEnterEvent *event);
  
  void CreateGizmo();
  void CameraLooking(float,float,float,float);
  void SphereCameraRotating(float,float,float,float);
  
  


  Ogre::Root    *mOgreRoot;
  Ogre::RenderWindow    *mOgreWindow;
  Ogre::Camera  *mCamera;
  Ogre::Viewport    *mViewport;
  Ogre::SceneManager    *mSceneMgr;
  Ogre::SceneNode   *mCurrentNode;
  Ogre::Entity   *mCurrentEntity;
  Ogre::RaySceneQuery   *mRaySceneQuery;
  
  int counter;

  bool altClick;

public:

  Ogre::SceneManager *getSceneManager();
  Ogre::Viewport *getViewPort();
  void setCurrentNode(Ogre::SceneNode*);
  Ogre::SceneNode* getCurrentNode();
  Ogre::Camera* getCamera();
  Ogre::RenderWindow* getRenderWidnow();
  Ogre::RaySceneQuery* getRaySceneQuery();  
  QTimer*  timer;


  enum QueryFlags
  {
         AXIS_MASK_X = 1 <<0,
         AXIS_MASK_Y = 1<<1 ,
         AXIS_MASK_Z = 1<<2 ,
         AXIS_MASK_XYZ = AXIS_MASK_X | AXIS_MASK_Y | AXIS_MASK_Z,
         AXIS_ROTATION =1<<6 ,
         OTHER_MASK = 1<<7 ,
         PLANE_XY_MASK = 1<<8,
         PLANE_XZ_MASK = 1<<9,
         PLANE_Z_MASK = 1<<10,
         NONE_MASK = 1<<11,
         AXIS_MASK_SCALE = 1<<12,
  };



// Slots
 public slots:
   void OnRenderTimer();

  
 };

#endif


