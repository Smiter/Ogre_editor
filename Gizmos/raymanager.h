#ifndef RAYMANAGER_H
#define RAYMANAGER_H

class RayManager
{
public:

static Ogre::Entity*      raycastEntityOnScene(float,float,Ogre::uint32 _mask);
static Ogre::SceneNode*   raycastNodeOnScene(float,float,Ogre::uint32 _mask);
static Ogre::Vector3      raycastIntersectionOnScene(float,float,Ogre::uint32 _mask,bool,bool=false,bool=true,Ogre::SceneNode *plane=0);

private:
   static void GetMeshInformation(const Ogre::MeshPtr , size_t &, Ogre::Vector3 *&, size_t &, unsigned long *&, const Ogre::Vector3 &, const Ogre::Quaternion &, const Ogre::Vector3 &);
   static Ogre::Viewport * viewPort;
};

#endif // RAYMANAGER_H
