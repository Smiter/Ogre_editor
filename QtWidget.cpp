#include "QtWidget.h"

void OgreWidget::init( std::string plugins_file,  std::string ogre_cfg_file, std::string ogre_log )
{
  mOgreRoot = new Ogre::Root( plugins_file, ogre_cfg_file, ogre_log );

  Ogre::RenderSystemList renderers = mOgreRoot->getAvailableRenderers();
  assert( !renderers.empty() );
  Ogre::RenderSystem *renderSystem = chooseRenderer(& renderers );
  assert( renderSystem );
  mOgreRoot->setRenderSystem( renderSystem );
  QString dimensions = QString( "%1x%2" ).arg(this->width()).arg(this->height());
  renderSystem->setConfigOption( "Video Mode", dimensions.toStdString() );
  mOgreRoot->getRenderSystem()->setConfigOption( "Full Screen", "No" );
  mOgreRoot->saveConfig();
  mOgreRoot->initialise(false);

  initResourses();
}

void OgreWidget::initializeGL()
{
  // Get the parameters of the window QT created
  Ogre::String winHandle = Ogre::StringConverter::toString((unsigned int)(winId()));
  Ogre::NameValuePairList params;
  params["externalWindowHandle"] = winHandle;

  mOgreWindow = mOgreRoot->createRenderWindow( "QOgreWidget_RenderWindow",   this->width(),   this->height(), false,  &params );
  mOgreWindow->setActive(true);
  WId ogreWinId = 0x0;
  mOgreWindow->getCustomAttribute( "WINDOW", &ogreWinId );
  setAttribute( Qt::WA_PaintOnScreen, true );
  setAttribute( Qt::WA_NoBackground );

  //== Ogre Initialization ==//
  Ogre::SceneType scene_manager_type = Ogre::ST_GENERIC;
  mSceneMgr = mOgreRoot->createSceneManager( scene_manager_type );
  mCamera = mSceneMgr->createCamera( "QOgreWidget_Cam" );
  mCamera->setNearClipDistance(0.1f);
  mCamera->setFarClipDistance(1000.0f);
  mCamera->setPosition(Ogre::Vector3(-201.0f, 200.0f, 0.0f));
  mCamera->setOrientation(Ogre::Quaternion(1,-0.27,-0.95,-0.27));
  mCamera->setAutoAspectRatio(true);

  Ogre::Viewport *mViewport = mOgreWindow->addViewport( mCamera );
  mViewport->setBackgroundColour( Ogre::ColourValue( 0.2,0.2,0.2 ) );
  Ogre::Entity * myEntity =mSceneMgr->createEntity("vasea" , "robot.mesh");
  Ogre::SceneNode * mynode = mSceneMgr->getRootSceneNode()->createChildSceneNode("vasea");
  mynode->attachObject( myEntity );
  myEntity->setMaterialName("RobotMaterial");
  mynode->setPosition(200,0,100);
  mynode->scale(1.1, 1.1, 1.1);
}

void OgreWidget::paintGL()
{
  assert( mOgreWindow );
  mOgreRoot->renderOneFrame();
}

void OgreWidget::resizeGL( int width, int height )
{
  assert( mOgreWindow );
  mOgreWindow->windowMovedOrResized();
}

Ogre::RenderSystem* OgreWidget::chooseRenderer( Ogre::RenderSystemList *renderers )
{
  return *renderers->begin();
}

void OgreWidget::initResourses()
{
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation("d:/Qtcreator/projects/OGRE_EDITOR/media/materials/textures", std::string("FileSystem"), "MyGroup", false);
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation("d:/Qtcreator/projects/OGRE_EDITOR/media/models",std::string("FileSystem"), "MyGroup", false);
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation("d:/Qtcreator/projects/OGRE_EDITOR/media/materials",std::string("FileSystem"), "MyGroup", false);
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation("d:/Qtcreator/projects/OGRE_EDITOR/media/myGUI",std::string("FileSystem"), "MyGroup", false);
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation("d:/Qtcreator/projects/OGRE_EDITOR/media/scenes",std::string("FileSystem"), "MyGroup", false);
  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}
