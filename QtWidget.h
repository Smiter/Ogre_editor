#ifndef __OGREWIDGET_H__
#define __OGREWIDGET_H__

#include <QtOpenGL/QGLWidget>

class OgreWidget : public QGLWidget
{
  //Q_OBJECT

 public:
  OgreWidget( QWidget *parent=0 ): QGLWidget( parent ), mOgreWindow(NULL)
    {
      init( "plugins.cfg", "ogre.cfg", "ogre.log" );
    }

  virtual ~OgreWidget()
    {
      mOgreRoot->shutdown();
      delete mOgreRoot;
      destroy();
    }

 protected:
  virtual void initializeGL();
  virtual void resizeGL( int, int );
  virtual void paintGL();

  QSize sizeHint() const  //оверрайд вирт функции для layout-ов. Минимальный размер который принимает окно при ресайзе.
  {
     return QSize(500, 500);
  }


  void init( std::string, std::string, std::string );
  void initResourses();

  virtual Ogre::RenderSystem* chooseRenderer( Ogre::RenderSystemList* );

  Ogre::Root *mOgreRoot;
  Ogre::RenderWindow *mOgreWindow;
  Ogre::Camera *mCamera;
  Ogre::Viewport *mViewport;
  Ogre::SceneManager *mSceneMgr;
};
////////////////////////
//HUI!!!!!!!!!!!!!!!!!!!!!!

// Sam takoi, pes :(
#endif



