///////////////////////////////////////////////////////////
//  Object.h
//  Implementation of the Class Object
//  Created on:      25-мар-2011 12:04:36
//  Original author: Max Payne
///////////////////////////////////////////////////////////
#include <String>

#if !defined(EA_F4D63257_8910_4e5e_A25E_59FA7064AA20__INCLUDED_)
#define EA_F4D63257_8910_4e5e_A25E_59FA7064AA20__INCLUDED_

class Object
{

public:
	Object();
	Object(std::string);
	virtual ~Object();
	/**
	 * The name of the object.
	 */
	std::string name;
/*
	static void Destroy(Object obj, float t = 0.0f);
	static Object FindObjectOfType(Type type);
	static Object[] FindObjectsOfType(Type type);
	int GetInstanceID();
	static Object Instantiate(Object original, Vector3 position, Quaternion rotation);
	static Object Instantiate(Object original);
	static boolean operator !=(Object x, Object y);
	static boolean operator ==(Object x, Object y);
	static boolean operator boolean(Object exists);
*/

};
#endif // !defined(EA_F4D63257_8910_4e5e_A25E_59FA7064AA20__INCLUDED_)
