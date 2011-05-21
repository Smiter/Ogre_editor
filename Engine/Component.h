///////////////////////////////////////////////////////////
//  Component.h
//  Implementation of the Class Component
//  Created on:      25-мар-2011 12:04:25
//  Original author: Max Payne
///////////////////////////////////////////////////////////

#if !defined(EA_FD6DE8E1_06BA_419c_B6C2_5BFE52E33F5E__INCLUDED_)
#define EA_FD6DE8E1_06BA_419c_B6C2_5BFE52E33F5E__INCLUDED_

#include "Object.h"

class GameObject;
class Transform;
class MeshRenderer;

class Component : public Object
{


public:
	Component();
	virtual ~Component();
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
	 * 
	 * 
	 * The game object this component is attached to. A component is always attached
	 * to a game object.
	 */
	GameObject *gameObject;
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
/*
	void BroadcastMessage(string methodName, Object parameter = null, SendMessageOptions options = SendMessageOptions.RequireReceiver);
	boolean CompareTag(string tag);
	Component GetComponent(Type type);
	Component GetComponent(string type);
	Component GetComponentInChildren(Type t);
	Component[]  GetComponents(Type type);
	Component[]  GetComponentsInChildren (Type t, bool includeInactive = false);
	void SendMessage(string methodName, Object value = null, SendMessageOptions options = SendMessageOptions.RequireReceiver);
	void SendMessageUpwards(string methodName, Object value = null, SendMessageOptions options = SendMessageOptions.RequireReceiver);
*/
};
#endif // !defined(EA_FD6DE8E1_06BA_419c_B6C2_5BFE52E33F5E__INCLUDED_)
