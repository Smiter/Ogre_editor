#ifndef __OGREWIDGET_H__
#define __OGREWIDGET_H__

#include <QtOpenGL/QGLWidget>
#include <QDir>

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
  virtual  void mousePressEvent ( QMouseEvent * event );
  void GetMeshInformation(const Ogre::MeshPtr , size_t &, Ogre::Vector3 *&, size_t &, unsigned long *&, const Ogre::Vector3 &, const Ogre::Quaternion &, const Ogre::Vector3 &);
  Ogre::SceneNode   *raycastOnScene(float,float);

  Ogre::Root    *mOgreRoot;
  Ogre::RenderWindow    *mOgreWindow;
  Ogre::Camera  *mCamera;
  Ogre::Viewport    *mViewport;
  Ogre::SceneManager    *mSceneMgr;

  Ogre::SceneNode   *mCurrentNode;


  Ogre::RaySceneQuery   *mRaySceneQuery;  
  QTimer*  timer;


public:

  Ogre::SceneManager *getSceneManager();
  void setCurrentNode(Ogre::SceneNode*);
  Ogre::SceneNode* getCurrentNode();

  // Temporary
  int counter;


// Events
  void dropEvent(QDropEvent *event);
  void dragEnterEvent(QDragEnterEvent *event);

// Slots
 public slots:
   void OnRenderTimer();

  
 };

#endif


