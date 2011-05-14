///////////////////////////////////////////////////////////
//  GameObject.h
//  Implementation of the Class GameObject
//  Created on:      10-мар-2011 22:15:04
//  Original author: Max Payne
///////////////////////////////////////////////////////////

#if !defined(EA_F8FE5BDE_87C6_4529_A358_02EBE63AEF42__INCLUDED_)
#define EA_F8FE5BDE_87C6_4529_A358_02EBE63AEF42__INCLUDED_

#include "Object.h"
#include "Component.h"

#include "Transform.h"
#include "MeshRenderer.h"

#include <String>
#include <typeinfo>

class GameObject : public Object
{

public:
	~GameObject();
	/**
	 * Is the GameObject active? Activates/Deactivates the GameObject.
	 */
	bool active;
	/**
	 * The Animation attached to this GameObject (null if there is none attached).
	 */
//	Animation animation;
	/**
	 * The AudioSource attached to this GameObject (null if there is none attached).
	 */
//	AudioSource audio;
	/**
	 * The Camera attached to this GameObject (null if there is none attached).
	 */
//	MyCamera *camera;
	/**
	 * The Collider attached to this GameObject (null if there is none attached).
	 */
//	Collider collider;
	/**
	 * The layer the game object is in. A layer is in the range [0...32]
	 */
//	int layer;
	/**
	 * The Light attached to this GameObject (null if there is none attached).
	 */
//	Light light;
	/**
	 * The ParticleEmitter attached to this GameObject (null if there is none
	 * attached).
	 */
//	ParticleEmitter particleEmitter;
	/**
	 * The Renderer attached to this GameObject (null if there is none attached).
	 */
	MeshRenderer *meshRenderer;
	/**
	 * The Rigidbody attached to this GameObject (null if there is none attached).
	 */
//	Rigidbody rigidbody;
	/**
	 * The tag of this game object.
	 */
//	string tag;
	/**
	 * The Transform attached to this GameObject (null if there is none attached).
	 */

	Transform *transform;

	GameObject (std::string);
	GameObject ();

	template <class ComponentType>
	Component *AddComponent(ComponentType* component)
	{

		std::string str = typeid(*component).name();

                if (str == "9Transform")
		{

			this->transform = dynamic_cast<Transform*> (component);

			this->transform->gameObject = this;
/*
			if (this->camera != NULL)
			{
				this->transform->camera = this->camera;

				this->transform->AttachObject(static_cast<Ogre::MovableObject*> (this->camera));
			}
*/
			if (this->meshRenderer != NULL)
			{
                                transform->meshRenderer = meshRenderer;

                                transform->sceneNode->attachObject(meshRenderer->entity);
			}

//			return (Transform*) component;

		}
   /*
		if (str == "class MyCamera")
		{

			this->camera = dynamic_cast<MyCamera*> (component);

			this->camera->gameObject = this;


			if (this->transform != NULL)
			{
				this->camera->transform = this->transform;

				this->transform->AttachObject(dynamic_cast<Ogre::MovableObject*> (component));
			}
			if (this->meshRenderer != NULL)
			{
				this->camera->meshRenderer = this->meshRenderer;
			}

//			return dynamic_cast<MyCamera*> (component);

		}
   */
                if (str == "12MeshRenderer")
		{

			this->meshRenderer = dynamic_cast<MeshRenderer*> (component);

			this->meshRenderer->gameObject = this;


			if (this->transform != NULL)
			{
                                meshRenderer->transform = transform;

                                transform->sceneNode->attachObject(meshRenderer->entity);
			}
/*
			if (this->camera != NULL)
			{
				this->meshRenderer->camera = this->camera;
			}
*/
//			return dynamic_cast<MeshRenderer*> (component);
		}
		
		return dynamic_cast<Component*> (component);
	}

/*
	GameObject GameObject(string name, Type[] components);
	Component AddComponent(string className);
	void BroadcastMessage(string methodName, Object parameter = null, SendMessageOptions options = SendMessageOptions.RequireReceiver);
	boolean CompareTag(string tag);
	static GameObject CreatePrimitive(PrimitiveType type);
	GameObject Find(string name);
	GameObject[] FindGameObjectsWithTag(string tag);
	GameObject FindWithTag(string tag);
	Component GetComponent(Type type);
	Component GetComponent(string type);
	Component GetComponentInChildren(Type t);
	Component[]  GetComponents(Type type);
	Component[]  GetComponentsInChildren (Type t, bool includeInactive = false);
	void SendMessage(string methodName, Object value = null, SendMessageOptions options = SendMessageOptions.RequireReceiver);
	void SendMessageUpwards(string methodName, Object value = null, SendMessageOptions options = SendMessageOptions.RequireReceiver);
	boolean SetActiveRecursively(boolean state);
*/

};
#endif // !defined(EA_F8FE5BDE_87C6_4529_A358_02EBE63AEF42__INCLUDED_)
