///////////////////////////////////////////////////////////
//  MeshRenderer.h
//  Implementation of the Class MeshRenderer
//  Created on:      07-апр-2011 22:55:58
//  Original author: Max Payne
///////////////////////////////////////////////////////////

#if !defined(EA_13853455_424F_46f4_AC0F_6072E31102D4__INCLUDED_)
#define EA_13853455_424F_46f4_AC0F_6072E31102D4__INCLUDED_

#include "Component.h"

#include <OgreEntity.h>

class MeshRenderer : public Component
{
    friend class GameObject;

private:
        Ogre::Entity *entity;

public:
	MeshRenderer();
        MeshRenderer(Ogre::String name, Ogre::String mesh, Ogre::String material);
	~MeshRenderer();
/*
	Ogre::MeshPtr get_mesh();
	void set_mesh(Ogre::Mesh &mesh);

	// Returns the instantiated Mesh assigned to the renderer.
	__declspec(property(get=get_mesh, put=set_mesh))
		Ogre::MeshPtr mesh;
*/
};

#endif // !defined(EA_13853455_424F_46f4_AC0F_6072E31102D4__INCLUDED_)
