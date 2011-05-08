#include "QtWidget.h"
#include "mainwindow.h"

OgreWidget::OgreWidget( QWidget *parent ): QGLWidget( parent ), mOgreWindow(NULL)
{
  init( "plugins.cfg", "ogre.cfg", "ogre.log" );
}

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

  mRaySceneQuery = new Ogre::DefaultRaySceneQuery(mSceneMgr);

  mCurrentNode=0;

  timer = new QTimer;
  QObject::connect(timer, SIGNAL(timeout()), this,SLOT(OnRenderTimer()));
  timer->setInterval(10);
  timer->start();

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

  Ogre::String path = QDir::currentPath().toStdString();
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(path + "/media/materials/textures", std::string("FileSystem"), "MyGroup", false);
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(path + "/media/models",std::string("FileSystem"), "MyGroup", false);
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(path + "/media/materials",std::string("FileSystem"), "MyGroup", false);
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(path + "/media/myGUI",std::string("FileSystem"), "MyGroup", false);
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(path + "/media/scenes",std::string("FileSystem"), "MyGroup", false);
  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

}

OgreWidget::~OgreWidget()
{
    mOgreRoot->shutdown();
    delete mOgreRoot;
    destroy();
}
void OgreWidget::OnRenderTimer()
{
    Ogre::Root::getSingleton().renderOneFrame();
}

void OgreWidget::mousePressEvent ( QMouseEvent * event )
{
    if(event->button() == Qt::LeftButton) {


        if( (mCurrentNode = raycastOnScene(event->x() ,   event->y() )) != 0 ){

            MainWindow::getInstance()->UpdateComponents(mCurrentNode,mSceneMgr->getEntity(mCurrentNode->getName()));

            MainWindow::getInstance()->UpdateSceneNodesList(QString::fromStdString(mCurrentNode->getName()));

        }
    }
}

Ogre::SceneNode * OgreWidget::raycastOnScene(float _x, float _y)
{
    mViewport = mSceneMgr->getCurrentViewport();
    float WindowWidth=mViewport->getActualWidth();
    float WindowHeight=mViewport->getActualHeight();

            //ќбъ€вим массив из 3-х точек, в который будем записывать треугольнк, который пересек луч.
            Ogre::Vector3 Face[3];

            Ogre::Ray _ray = mCamera->getCameraToViewportRay(_x / WindowWidth , _y / WindowHeight); /// стрел€ем лучом из курсора
            Ogre::Vector3 inters = Ogre::Vector3::ZERO;
            Ogre::Entity* ent = 0;
            Ogre::Vector3 singleRes;

            if ( mRaySceneQuery != NULL ) {
                    mRaySceneQuery->clearResults( );
                  //  mRaySceneQuery->setQueryTypeMask(Ogre::SceneManager::ENTITY_TYPE_MASK);
                  //  mRaySceneQuery->setQueryMask( _mask );
                    mRaySceneQuery->setRay( _ray );
                    mRaySceneQuery->setSortByDistance(true);
                    if ( mRaySceneQuery->execute().size() <= 0 ) {
                           // if (myEnt._distance !=0)
                          //  {
                          //          myEnt._intersection=_ray.getPoint(myEnt._distance);
                           // }
                                       return 0;
                      }
            } else {
                    Ogre::LogManager::getSingleton().logMessage("...Cannot raycast without RaySceneQuery instance...");
                    return 0;
            }
            Ogre::Real closest_distance = -1.0f;
            Ogre::Vector3 closest_result;
            Ogre::RaySceneQueryResult &query_result = mRaySceneQuery->getLastResults();
            Ogre::RaySceneQueryResult::iterator itr = query_result.begin( );

            /// перебор всех объектов, в которые попал луч
            for (size_t qr_idx = 0; qr_idx < query_result.size( ); qr_idx++, itr++ ) {
                    if ((closest_distance >= 0.0f) && (closest_distance < query_result[qr_idx].distance)) {
                            break;
                    }
                    if (query_result[qr_idx].movable != NULL) {
                            ent = static_cast< Ogre::Entity * >(query_result[ qr_idx ].movable);
                            if ( ent ) {
                                    //if(ent->getName() == "GizmoT") continue;

                                  //  if (checkBounds)
                                   // {
                                   //         myEnt._entName=ent->getName();
                                   //         closest_result = _ray.getPoint((*itr).distance);
                                   //         myEnt._intersection=closest_result;
                                   //         myEnt._distance = (*itr).distance;
                                   //         return 0;
                                   // }
                                    size_t vertex_count = 0;
                                    size_t index_count = 0;
                                    Ogre::Vector3 *vertices = new Ogre::Vector3(Ogre::Vector3::ZERO);
                                    unsigned long *indices = new unsigned long(0);
                                    if ( ! ent->getMesh( ).isNull( ) ) {
                                            if ( ent->getMesh( )->getNumSubMeshes( ) > 10000 ) continue;
                                            GetMeshInformation(ent->getMesh(), vertex_count, vertices, index_count, indices,
                                                                                    ent->getParentNode()->_getDerivedPosition(),
                                                                                    ent->getParentNode()->_getDerivedOrientation(),
                                                                                    ent->getParentNode()->_getDerivedScale());
                                            bool new_closest_found = false;
                                            for (int i = 0; i < static_cast<int>(index_count); i += 3)
                                            {
                                                    std::pair<bool, Ogre::Real> hit = Ogre::Math::intersects(_ray, vertices[indices[i]],
                         vertices[indices[i+1]], vertices[indices[i+2]], true, true);

                                                    if (hit.first)
                                                    {
                                                            if ((closest_distance < 0.5f) || (hit.second < closest_distance))
                                                            {
                                                                    //---------------
                                                                    //—обственно запоминаем координаты треугольника
                                                                    Face[0] = vertices[indices[i]];
                                                                    Face[1] = vertices[indices[i+1]];
                                                                    Face[2] = vertices[indices[i+2]];
                                                                    //---------------
                                                                    closest_distance = hit.second;
                                                                    new_closest_found = true;

                                                            }
                                                    }
                                            }
                                            delete[] vertices;
                                            delete[] indices;
                                            if (new_closest_found) {
                                                    //closest_result = _ray.getPoint(closest_distance);
                                                   // myEnt._ent = ent;
                                                  //  myEnt._entName=ent->getName();
                                                  //  myEnt._intersection=closest_result;
                                                  //  myEnt._distance = closest_distance;
                                                   // myEnt._localSpace=planeNode->convertWorldToLocalPosition(closest_result);
                                            }
                                    }
                            }
                    }
            }
            if (closest_distance >= 0.0f && ent)
            {
                   // return 1;
                    //qDebug()<<QString::fromStdString(mSceneMgr->getSceneNode(ent->getName())->getName());
                    return mSceneMgr->getSceneNode(ent->getName());

            }
            return 0;
}


void OgreWidget::GetMeshInformation(const Ogre::MeshPtr mesh, size_t &vertex_count, Ogre::Vector3 *&vertices, size_t &index_count, unsigned long *&indices, const Ogre::Vector3 &position, const Ogre::Quaternion &orient, const Ogre::Vector3 &scale) {
        bool added_shared = false;
        size_t current_offset = 0;
        size_t shared_offset = 0;
        size_t next_offset = 0;
        size_t index_offset = 0;
        vertex_count = index_count = 0;
        for (unsigned short i = 0; i < mesh->getNumSubMeshes(); ++i) {
                Ogre::SubMesh* submesh = mesh->getSubMesh( i );
                if ( !submesh ) continue;
                if(submesh->useSharedVertices) {
                        if( !added_shared ) {
                                          vertex_count += mesh->sharedVertexData->vertexCount;
                                          added_shared = true;
                        }
                } else {
                        vertex_count += submesh->vertexData->vertexCount;
                }
                index_count += submesh->indexData->indexCount;
        }
        if ( vertices ) delete vertices;
        if ( indices ) delete indices;
        vertices = new Ogre::Vector3[vertex_count];
        indices = new unsigned long[index_count];
        added_shared = false;
        for ( unsigned short i = 0; i < mesh->getNumSubMeshes(); ++i) {
                Ogre::SubMesh* submesh = mesh->getSubMesh(i);
                if ( !submesh ) continue;
                Ogre::VertexData* vertex_data = submesh->useSharedVertices ? mesh->sharedVertexData : submesh->vertexData;
                if((!submesh->useSharedVertices)||(submesh->useSharedVertices && !added_shared)) {
                        if(submesh->useSharedVertices) {
                                added_shared = true;
                                shared_offset = current_offset;
                        }
                        const Ogre::VertexElement* posElem = vertex_data->vertexDeclaration->findElementBySemantic(Ogre::VES_POSITION);
                        Ogre::HardwareVertexBufferSharedPtr vbuf = vertex_data->vertexBufferBinding->getBuffer(posElem->getSource());
                        unsigned char* vertex = static_cast<unsigned char*>(vbuf->lock(Ogre::HardwareBuffer::HBL_READ_ONLY));
                        float* pReal;
                        for( size_t j = 0; j < vertex_data->vertexCount; ++j, vertex += vbuf->getVertexSize()) {
                                posElem->baseVertexPointerToElement(vertex, &pReal);
                                Ogre::Vector3 pt(pReal[0], pReal[1], pReal[2]);
                                vertices[current_offset + j] = (orient * (pt * scale)) + position;
                        }
                        vbuf->unlock();
                        next_offset += vertex_data->vertexCount;
                }
                Ogre::IndexData* index_data = submesh->indexData;
                size_t numTris = index_data->indexCount / 3;
                Ogre::HardwareIndexBufferSharedPtr ibuf = index_data->indexBuffer;
                bool use32bitindexes = (ibuf->getType() == Ogre::HardwareIndexBuffer::IT_32BIT);
                unsigned long*  pLong = static_cast<unsigned long*>(ibuf->lock(Ogre::HardwareBuffer::HBL_READ_ONLY));
                unsigned short* pShort = reinterpret_cast<unsigned short*>(pLong);
                size_t offset = (submesh->useSharedVertices)? shared_offset : current_offset;
                if ( use32bitindexes ) {
                        for ( size_t k = 0; k < numTris*3; ++k) {
                                indices[index_offset++] = pLong[k] + static_cast<unsigned long>(offset);
                        }
                } else {
                        for ( size_t k = 0; k < numTris*3; ++k) {
                                indices[index_offset++] = static_cast<unsigned long>(pShort[k]) +
                                          static_cast<unsigned long>(offset);
                        }
                }
                ibuf->unlock();
                current_offset = next_offset;
        }
 }

Ogre::SceneManager *OgreWidget::getSceneManager()
{
    return mSceneMgr;
}

void OgreWidget::setCurrentNode(Ogre::SceneNode* node)
{
    mCurrentNode = node;
}

Ogre::SceneNode* OgreWidget::getCurrentNode()
{
    return mCurrentNode;
}
