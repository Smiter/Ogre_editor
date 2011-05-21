#include "raymanager.h"

Ogre::Viewport * RayManager::viewPort = 0;

Ogre::Entity * RayManager::raycastEntityOnScene(OgreWidget * ogreWidget,float _x, float _y,Ogre::uint32 _mask)
{
    viewPort = ogreWidget->getSceneManager()->getCurrentViewport();
    float WindowWidth=viewPort->getActualWidth();
    float WindowHeight=viewPort->getActualHeight();

            //ќбъ€вим массив из 3-х точек, в который будем записывать треугольнк, который пересек луч.
            // qDebug()<<_x / WindowWidth<<" "<<_y / WindowHeight<<"\n";
            Ogre::Ray _ray = ogreWidget->getCamera()->getCameraToViewportRay(_x / WindowWidth , _y / WindowHeight); /// стрел€ем лучом из курсора
            Ogre::Vector3 inters = Ogre::Vector3::ZERO;
            Ogre::Entity* ent = 0;
            Ogre::Vector3 singleRes;

            if ( ogreWidget->getRaySceneQuery() != NULL ) {
                    ogreWidget->getRaySceneQuery()->clearResults( );
                    ogreWidget->getRaySceneQuery()->setRay( _ray );
                    //ogreWidget->getRaySceneQuery()->setQueryTypeMask(Ogre::SceneManager::ENTITY_TYPE_MASK);
                    ogreWidget->getRaySceneQuery()->setQueryMask( _mask );
                    ogreWidget->getRaySceneQuery()->setSortByDistance(true);
                    if ( ogreWidget->getRaySceneQuery()->execute().size() <= 0 ) {
                                       return 0;
                      }
            } else {
                    Ogre::LogManager::getSingleton().logMessage("...Cannot raycast without RaySceneQuery instance...");
                    return 0;
            }
            Ogre::Real closest_distance = -1.0f;
            Ogre::Vector3 closest_result;
            Ogre::RaySceneQueryResult &query_result = ogreWidget->getRaySceneQuery()->getLastResults();
            Ogre::RaySceneQueryResult::iterator itr = query_result.begin( );

            /// перебор всех объектов, в которые попал луч
            for (size_t qr_idx = 0; qr_idx < query_result.size( ); qr_idx++, itr++ )
            {
                    if ((closest_distance >= 0.0f) && (closest_distance < query_result[qr_idx].distance)) {
                            break;
                    }
                    if (query_result[qr_idx].movable != NULL)
                    {
                            ent = static_cast< Ogre::Entity * >(query_result[ qr_idx ].movable);
                            if ( ent )
                            {
                                //qDebug()<<(_ray.getPoint((*itr).distance)).x<<" "<<(_ray.getPoint((*itr).distance)).y<<" "<<(_ray.getPoint((*itr).distance)).z<<"\n";
                                    return ent;
                            }
                    }
            }
            return 0;

 }





Ogre::SceneNode * RayManager::raycastNodeOnScene(OgreWidget * ogreWidget,float _x, float _y,Ogre::uint32 _mask)
{
    viewPort = ogreWidget->getSceneManager()->getCurrentViewport();
    float WindowWidth=viewPort->getActualWidth();
    float WindowHeight=viewPort->getActualHeight();

            //ќбъ€вим массив из 3-х точек, в который будем записывать треугольнк, который пересек луч.
            Ogre::Vector3 Face[3];

            Ogre::Ray _ray = ogreWidget->getCamera()->getCameraToViewportRay(_x / WindowWidth , _y / WindowHeight); /// стрел€ем лучом из курсора
            Ogre::Vector3 inters = Ogre::Vector3::ZERO;
            Ogre::Entity* ent = 0;
            Ogre::Vector3 singleRes;

            if ( ogreWidget->getRaySceneQuery() != NULL ) {
                    ogreWidget->getRaySceneQuery()->clearResults( );
                    ogreWidget->getRaySceneQuery()->setQueryTypeMask(Ogre::SceneManager::ENTITY_TYPE_MASK);
                    ogreWidget->getRaySceneQuery()->setQueryMask( _mask );
                    ogreWidget->getRaySceneQuery()->setRay( _ray );
                    ogreWidget->getRaySceneQuery()->setSortByDistance(true);
                    if ( ogreWidget->getRaySceneQuery()->execute().size() <= 0 ) {
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
            Ogre::RaySceneQueryResult &query_result = ogreWidget->getRaySceneQuery()->getLastResults();
            Ogre::RaySceneQueryResult::iterator itr = query_result.begin( );

            /// перебор всех объектов, в которые попал луч
            for (size_t qr_idx = 0; qr_idx < query_result.size( ); qr_idx++, itr++ ) {
                    if ((closest_distance >= 0.0f) && (closest_distance < query_result[qr_idx].distance)) {
                            break;
                    }
                    if (query_result[qr_idx].movable != NULL) {
                            ent = static_cast< Ogre::Entity * >(query_result[ qr_idx ].movable);
                            if ( ent ) {

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
                                    }
                            }
                    }
            }
            if (closest_distance >= 0.0f && ent)
            {

                    return ogreWidget->getSceneManager()->getSceneNode(ent->getName());

            }
            return 0;
}




Ogre::Vector3  RayManager::raycastIntersectionOnScene(OgreWidget * ogreWidget,float _x, float _y,Ogre::uint32 _mask,bool bounds,bool local,bool global, Ogre::SceneNode * plane)
{
    viewPort = ogreWidget->getSceneManager()->getCurrentViewport();
    float WindowWidth=viewPort->getActualWidth();
    float WindowHeight=viewPort->getActualHeight();

            //ќбъ€вим массив из 3-х точек, в который будем записывать треугольнк, который пересек луч.
            Ogre::Vector3 Face[3];

            Ogre::Ray _ray = ogreWidget->getCamera()->getCameraToViewportRay(_x / WindowWidth , _y / WindowHeight); /// стрел€ем лучом из курсора
            Ogre::Vector3 inters = Ogre::Vector3::ZERO;
            Ogre::Entity* ent = 0;
            Ogre::Vector3 singleRes;

            if ( ogreWidget->getRaySceneQuery() != NULL ) {
                    ogreWidget->getRaySceneQuery()->clearResults( );
                    ogreWidget->getRaySceneQuery()->setQueryTypeMask(Ogre::SceneManager::ENTITY_TYPE_MASK);
                    ogreWidget->getRaySceneQuery()->setQueryMask( _mask );
                    ogreWidget->getRaySceneQuery()->setRay( _ray );
                    ogreWidget->getRaySceneQuery()->setSortByDistance(true);
                    if ( ogreWidget->getRaySceneQuery()->execute().size() <= 0 ) {
                                       return Ogre::Vector3::ZERO;
                      }
            } else {
                    Ogre::LogManager::getSingleton().logMessage("...Cannot raycast without RaySceneQuery instance...");
                    return Ogre::Vector3::ZERO;
            }
            Ogre::Real closest_distance = -1.0f;
            Ogre::Vector3 closest_result;
            Ogre::RaySceneQueryResult &query_result = ogreWidget->getRaySceneQuery()->getLastResults();
            Ogre::RaySceneQueryResult::iterator itr = query_result.begin( );

            /// перебор всех объектов, в которые попал луч
            for (size_t qr_idx = 0; qr_idx < query_result.size( ); qr_idx++, itr++ ) {
                    if ((closest_distance >= 0.0f) && (closest_distance < query_result[qr_idx].distance)) {
                            break;
                    }
                    if (query_result[qr_idx].movable != NULL) {
                            ent = static_cast< Ogre::Entity * >(query_result[ qr_idx ].movable);
                            if ( ent ) {
                                   if(bounds)
                                   {
                                      // if(global)
                                      // {
                                           return   _ray.getPoint((*itr).distance);
                                      // }
                                       //if(local)
                                       //{
                                          // return   plane->convertWorldToLocalPosition(_ray.getPoint((*itr).distance));
                                       //}
                                   }
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
                                            if (new_closest_found)
                                            {
                                                if(global)
                                                {
                                                    return   closest_result = _ray.getPoint(closest_distance);
                                                }
                                                if(local)
                                                {
                                                    return   plane->convertWorldToLocalPosition(_ray.getPoint(closest_distance));
                                                }


                                            }
                                    }
                            }
                    }
            }
            if (closest_distance >= 0.0f && ent)
            {

                if(global)
                {
                    return   closest_result = _ray.getPoint(closest_distance);
                }
                if(local)
                {
                    return   plane->convertWorldToLocalPosition(closest_result);
                }

            }
            return Ogre::Vector3::ZERO;
}


void RayManager::GetMeshInformation(const Ogre::MeshPtr mesh, size_t &vertex_count, Ogre::Vector3 *&vertices, size_t &index_count, unsigned long *&indices, const Ogre::Vector3 &position, const Ogre::Quaternion &orient, const Ogre::Vector3 &scale) {
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
