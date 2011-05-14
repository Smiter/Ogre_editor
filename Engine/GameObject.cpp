///////////////////////////////////////////////////////////
//  GameObject.cpp
//  Implementation of the Class GameObject
//  Created on:      10-мар-2011 22:15:05
//  Original author: Max Payne
///////////////////////////////////////////////////////////


#include "GameObject.h"

/**
 * Creates a new game object, named name.
 */
GameObject::GameObject(std::string name) : Object(name), meshRenderer(0)
{
    AddComponent(new Transform(name, Ogre::Vector3(0,0,0)));
}

/**
 * Creates a new game object.
 */
GameObject::GameObject() : meshRenderer(0), transform(0)
{
}

GameObject::~GameObject(){
    /*
	if (this->camera != NULL)
	{
		delete this->camera;
	}
      */
        if (transform != 0)
	{
            delete transform;
	}	
        if (meshRenderer != 0)
        {
            delete meshRenderer;
        }
}



/**
 * Creates a game object and attaches the specified components.
 */
//GameObject GameObject::GameObject(string name, Type[] components){

//}


/**
 * Adds a component class named className to the game object.
 */
/*
Component GameObject::AddComponent(string className){

	return  NULL;
}
*/

/**
 * Adds a component class of type componentType to the game object.
 */



/*
void GameObject::BroadcastMessage(string methodName, Object parameter, SendMessageOptions options){

}
*/

/**
 * Is this game object tagged tag?
 */
/*
boolean GameObject::CompareTag(string tag){

	return  NULL;
}


GameObject GameObject::CreatePrimitive(PrimitiveType type){

	return  NULL;
}

*/
/**
 * Finds a game object by name and returns it.
 */
/*
GameObject GameObject::Find(string name){

	return  NULL;
}
*/

/**
 * Returns a list of active GameObjects tagged tag. Returns null if no GameObject
 * was found.
 */
/*
GameObject[] GameObject::FindGameObjectsWithTag(string tag){

	return  NULL;
}
*/


/**
 * Returns one active GameObject tagged tag. Returns null if no GameObject was
 * found.
 */
/*
GameObject GameObject::FindWithTag(string tag){

	return  NULL;
}


Component GameObject::GetComponent(Type type){

	return  NULL;
}
*/

/**
 * Returns the component with name type if the game object has one attached, null
 * if it doesn't.
 */
/*
Component GameObject::GetComponent(string type){

	return  NULL;
}
*/

/**
 * Returns the component of Type type in the GameObject or any of its children
 * using depth first search.
 */
/*
Component GameObject::GetComponentInChildren(Type t){

	return  NULL;
}
*/

/**
 * Returns all components of Type type in the GameObject.
 */
/*
Component[]  GameObject::GetComponents(Type type){

	return  NULL;
}
*/

/**
 * Returns all components of Type type in the GameObject or any of its children.
 */
/*
Component[]  GameObject::GetComponentsInChildren (Type t, bool includeInactive){

	return  NULL;
}
*/

/**
 * Calls the method named methodName on every MonoBehaviour in this game object.
 */
/*
void GameObject::SendMessage(string methodName, Object value, SendMessageOptions options){

}
*/

/**
 * Calls the method named methodName on every MonoBehaviour in this game object
 * and on every ancestor of the behaviour
 */
/*
void GameObject::SendMessageUpwards(string methodName, Object value, SendMessageOptions options){

}
*/

/**
 * Sets the active state of this and all the game objects children to state.
 */
/*
boolean GameObject::SetActiveRecursively(boolean state){

	return  NULL;
}
*/
