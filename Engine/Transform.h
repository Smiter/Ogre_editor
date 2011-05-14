///////////////////////////////////////////////////////////
//  Transform.h
//  Implementation of the Class Transform
//  Created on:      24-мар-2011 23:38:50
//  Original author: Max Payne
///////////////////////////////////////////////////////////

#if !defined(EA_01E8BA7E_76B7_4afd_9AC4_270769AEC375__INCLUDED_)
#define EA_01E8BA7E_76B7_4afd_9AC4_270769AEC375__INCLUDED_

#include "Component.h"

#include "OgreVector3.h"
#include "OgreQuaternion.h"

#include "OgreSceneNode.h"

enum Space{ World, Self };

class Transform  : public Component
{
    friend class GameObject;

private:

        Ogre::SceneNode *sceneNode;

public:
	Transform();
        Transform(Ogre::String, Ogre::Vector3);
	~Transform();

	// GETTERS AND SETTERS
/*
	// Get\Set Position
	Ogre::Vector3 &get_position();
	void set_position(const Ogre::Vector3&);

	// Get\Set Local Position
	Ogre::Vector3 get_localPosition();
	void set_localPosition(const Ogre::Vector3&);

	// Get\Set Rotation
	Ogre::Quaternion get_rotation();
	void set_rotation(const Ogre::Quaternion&);

	// Get\Set Local Rotation
	Ogre::Quaternion get_localRotation();
	void set_localRotation(const Ogre::Quaternion&);

	// Get Scale
	Ogre::Vector3 get_scale();

	// Get\Set Local Scale
	Ogre::Vector3 get_localScale();
	void set_localScale(const Ogre::Vector3&);

	// Get\Set Root
	Transform get_root();
	void set_root(const Transform&);

	// Get\Set Parent
	Transform get_parent();
	void set_parent(Transform&);

	// Get ChildCount
	unsigned short get_childCount();

	// Get\Set Look Vector
	Ogre::Vector3 get_look();
	void set_look(const Ogre::Vector3&);

	// Get\Set Left Vector
	Ogre::Vector3 get_left();
	void set_left(const Ogre::Vector3&);

	// Get\Set Up Vector
	Ogre::Vector3 get_up();
	void set_up(const Ogre::Vector3&);

	// Get\Set Euler Angles
	Ogre::Vector3 get_eulerAngles();
	void set_eulerAngles(const Ogre::Vector3&);

	// Get\Set Local Euler Angles
	Ogre::Vector3 get_localEulerAngles();
	void set_localEulerAngles(const Ogre::Vector3&);

	// Transforms Local To World Matrix
	Ogre::Matrix4 get_localToWorldMatrix();

	// Transforms World To Local Matrix
	Ogre::Matrix4 get_worldToLocalMatrix();
*/
	// PROPERTIES
/*
	// The position of the transform in world space.
	__declspec(property(get=get_position, put=set_position)) 
		Ogre::Vector3 &position;

	// The position of the transform in world space.
	__declspec(property(get=get_localPosition, put=set_localPosition)) 
		Ogre::Vector3 localPosition;

	// The rotation of the transform in world space stored as a Quaternion.
	__declspec(property(get=get_rotation, put=set_rotation)) 
		Ogre::Quaternion rotation;

	// The rotation of the transform in world space stored as a Quaternion.
	__declspec(property(get=get_localRotation, put=set_localRotation)) 
		Ogre::Quaternion localRotation;

	// The global scale of the object (Read Only).
	__declspec(property(get=get_scale)) 
		Ogre::Vector3 lossyScale; 

	// The scale of the transform relative to the parent.
	__declspec(property(get=get_localScale, put=set_localScale)) 
		Ogre::Vector3 localPosition;

	// Returns the topmost transform in the hierarchy.
	__declspec(property(get=get_root, put=set_root))
		Transform root;

	// The parent node of the transform.
	__declspec(property(get=get_parent, put=set_parent))
		Transform parent;

	// The number of children the Transform has.
	__declspec(property(get=get_childCount))
		unsigned short childCount;

	// The blue axis of the transform in world space.
	__declspec(property(get=get_look, put=set_look))
		Ogre::Vector3 look;

	// The red axis of the transform in world space.
	__declspec(property(get=get_left, put=set_left))
		Ogre::Vector3 left;

	// The green axis of the transform in world space.
	__declspec(property(get=get_up, put=set_up))
		Ogre::Vector3 up;

	// The rotation as Euler angles in degrees.
	__declspec(property(get=get_eulerAngles, put=set_eulerAngles))
		Ogre::Vector3 eulerAngles;

	// The rotation as Euler angles in degrees relative to the parent transform's rotation.
	__declspec(property(get=get_localEulerAngles, put=set_localEulerAngles))
		Ogre::Vector3 localEulerAngles;

	// Matrix that transforms a point from local space into world space (Read Only).
	__declspec(property(get=get_localToWorldMatrix)) 
		Ogre::Matrix4 localToWorldMatrix;

	// Matrix that transforms a point from world space into local space (Read Only).
	__declspec(property(get=get_worldToLocalMatrix)) 
		Ogre::Matrix4 worldToLocalMatrix ;
*/

	// CLASS METHODS
/*
	void DetachChildren();
//	Transform Find(Ogre::String name);
	Ogre::Vector3 InverseTransformDirection(Ogre::Vector3 direction);
	Ogre::Vector3 InverseTransformDirection(Ogre::Real x, Ogre::Real y, Ogre::Real z);
	Ogre::Vector3 InverseTransformPoint(Ogre::Vector3 position);
	Ogre::Vector3 InverseTransformPoint(Ogre::Real x, Ogre::Real y, Ogre::Real z);
	bool isChildOf(Transform parent);
	Ogre::Vector3 TransformDirection(Ogre::Vector3 direction);
	Ogre::Vector3 TransformDirection(Ogre::Real x, Ogre::Real y, Ogre::Real z);
	Ogre::Vector3 TransformPoint(Ogre::Vector3 position);
	Ogre::Vector3 TransformPoint(Ogre::Real x, Ogre::Real y, Ogre::Real z);
	void LookAt(Transform *target, Ogre::Vector3 lookAxis = Ogre::Vector3::NEGATIVE_UNIT_Z);
	void LookAt(Ogre::Vector3 worldPosition, Ogre::Vector3 lookAxis = Ogre::Vector3::NEGATIVE_UNIT_Z);
	void Rotate(Ogre::Vector3 eulerAngles, TransformSpace relativeTo = TS_PARENT);
	void Rotate(Ogre::Real xAngle, Ogre::Real yAngle, Ogre::Real zAngle, TransformSpace relativeTo = TS_PARENT );
	void Rotate(Ogre::Vector3 axis, Ogre::Real angle, TransformSpace relativeTo = TS_PARENT);
	void RotateAround(Ogre::Vector3 point, Ogre::Vector3 axis, float angle);
	void Translate(Ogre::Vector3 translation, TransformSpace relativeTo = TS_PARENT );
	void Translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, TransformSpace relativeTo = TS_PARENT );
	void Translate(Ogre::Vector3 translation, Transform relativeTo);
	void Translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Transform relativeTo);
*/

};
#endif // !defined(EA_01E8BA7E_76B7_4afd_9AC4_270769AEC375__INCLUDED_)
