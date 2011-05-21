///////////////////////////////////////////////////////////
//  Transform.cpp
//  Implementation of the Class Transform
//  Created on:      24-мар-2011 23:38:50
//  Original author: Max Payne
///////////////////////////////////////////////////////////

#include "Transform.h"

#include "mainwindow.h"

Transform::Transform()  {

        sceneNode = MainWindow::getInstance()->ogreWindow->getSceneManager()->createSceneNode("Unknown");

}

Transform::Transform(Ogre::String name, Ogre::Vector3 pos){


        sceneNode = MainWindow::getInstance()->ogreWindow->getSceneManager()->getRootSceneNode()->createChildSceneNode(name);

        sceneNode->setPosition(Ogre::Vector3(pos));
        sceneNode->scale(1.0, 1.0, 1.0);


        MainWindow::getInstance()->AddItemToSceneList(name);
}

Transform::~Transform(){
        delete sceneNode;
}


/*
// Returns object's position

Ogre::Vector3 &Transform::get_position()
{
	return const_cast<Ogre::Vector3&> (this->_getDerivedPosition());
}

void Transform::set_position(const Ogre::Vector3 &position)
{
	this->_setDerivedPosition(position);
}

Ogre::Vector3 Transform::get_localPosition()
{
	return this->getPosition();
}

void Transform::set_localPosition(const Ogre::Vector3 &position)
{
	this->setPosition(position);
}

Ogre::Quaternion Transform::get_rotation()
{
	return this->_getDerivedOrientation();
}

void Transform::set_rotation(const Ogre::Quaternion &rotation)
{
	this->_setDerivedOrientation(rotation);
}

Ogre::Quaternion Transform::get_localRotation()
{
	return this->getOrientation();
}

void Transform::set_localRotation(const Ogre::Quaternion &rotation)
{
	this->setOrientation(rotation);
}

Ogre::Vector3 Transform::get_scale()
{
	return this->_getDerivedScale();
}

Ogre::Vector3 Transform::get_localScale()
{
	return this->getScale();
}

void Transform::set_localScale(const Ogre::Vector3 &scale)
{
	this->setScale(position);
}

Transform Transform::get_root()
{
	// Returning the topmost transform object
	return *(this);
}

void Transform::set_root(const Transform&)
{
	// Setting the topmost transform object

}

Transform Transform::get_parent()
{
	return (Transform&) *(this->getParentSceneNode());
}

void Transform::set_parent(Transform &parent)
{
	this->setParent( (Ogre::Node*) &parent);
}

unsigned short Transform::get_childCount()
{
	return this->numChildren();
}

Ogre::Vector3 Transform::get_look()
{
	return this->_getDerivedOrientation() * Ogre::Vector3::NEGATIVE_UNIT_Z; 
}

void Transform::set_look(const Ogre::Vector3& look)
{
	this->rotation = get_look().getRotationTo(look);
}

Ogre::Vector3 Transform::get_left()
{
	return this->_getDerivedOrientation() * Ogre::Vector3::UNIT_X;
}

void Transform::set_left(const Ogre::Vector3& left)
{
	this->rotation = get_left().getRotationTo(left);
}

Ogre::Vector3 Transform::get_up()
{
	return this->_getDerivedOrientation() * Ogre::Vector3::UNIT_Y;
}

void Transform::set_up(const Ogre::Vector3& up)
{
	this->rotation = get_up().getRotationTo(up);
}

*/

/*
Ogre::Vector3 Transform::get_eulerAngles()
{
	Ogre::Matrix3 mat;
	Ogre::Radian yRad, pRad, rRad;
	rotation.ToRotationMatrix(mat);
	mat.ToEulerAnglesYXZ(yRad, pRad, rRad);
	
	return Ogre::Vector3(pRad.valueDegrees(), yRad.valueDegrees(), rRad.valueDegrees());
}

void Transform::set_eulerAngles(const Ogre::Vector3& euler)
{
	Ogre::Matrix3 mat;
	Ogre::Radian yRad(euler.y), pRad(euler.x), rRad(euler.z);
	mat.FromEulerAnglesYXZ(yRad, pRad, rRad);
	rotation.FromRotationMatrix(mat);
}

Ogre::Vector3 Transform::get_localEulerAngles()
{
	Ogre::Matrix3 mat;
	Ogre::Radian yRad, pRad, rRad;
	localRotation.ToRotationMatrix(mat);
	mat.ToEulerAnglesYXZ(yRad, pRad, rRad);

	return Ogre::Vector3(pRad.valueDegrees(), yRad.valueDegrees(), rRad.valueDegrees());
}

void Transform::set_localEulerAngles(const Ogre::Vector3& euler)
{
	Ogre::Matrix3 mat;
	Ogre::Radian yRad(euler.y), pRad(euler.x), rRad(euler.z);
	mat.FromEulerAnglesYXZ(yRad, pRad, rRad);
	localRotation.FromRotationMatrix(mat);
}

Ogre::Matrix4 Transform::get_localToWorldMatrix()
{
	// ? 
	// As I understood, this function returns a Matrix4x4 which
	// multiplying with local point you will get a new Matrix4x4
	// in world space. The same is concerned with the next function
	return Ogre::Matrix4::ZERO;
}

Ogre::Matrix4 Transform::get_worldToLocalMatrix()
{
	// ?
	return Ogre::Matrix4::ZERO;
}

*/


/**
 * Finds a child by name and returns it.
 */

/*
Transform Transform::Find(Ogre::String name){

	// DOESN'T CAST FROM NODE TO TRANSFORM
	return  static_cast<Transform>(*(this->getChild(name)));
}


bool Transform::isChildOf(Transform parent){

	if (this->getChild(parent.name))
		return true;
	return false;
}



void Transform::LookAt(Transform *target, Ogre::Vector3 lookAxis){
	this->lookAt(target->position, TS_LOCAL, lookAxis );
}




void Transform::LookAt(Ogre::Vector3 worldPosition, Ogre::Vector3 lookAxis){
	this->lookAt(worldPosition, TS_LOCAL, lookAxis);
}



Ogre::Vector3 Transform::TransformDirection(Ogre::Vector3 direction){
	Ogre::Vector3 localNorm = (Ogre::Vector3) direction.normalise();
	localNorm = this->convertLocalToWorldPosition(localNorm);

	return  localNorm * direction.length();
}



Ogre::Vector3 Transform::TransformDirection(Ogre::Real x, Ogre::Real y, Ogre::Real z){

	return  this->TransformDirection(Ogre::Vector3(x, y, z));
}



Ogre::Vector3 Transform::TransformPoint(Ogre::Vector3 position){

	return this->convertLocalToWorldPosition(position);
}



Ogre::Vector3 Transform::TransformPoint(Ogre::Real x, Ogre::Real y, Ogre::Real z){
	
	return  this->TransformPoint(Ogre::Vector3(x, y, z));
}


Ogre::Vector3 Transform::InverseTransformDirection(Ogre::Vector3 direction){

	Ogre::Vector3 worldNorm = (Ogre::Vector3) direction.normalise();
	worldNorm = this->convertWorldToLocalPosition(worldNorm);

	return  worldNorm * direction.length();
}


Ogre::Vector3 Transform::InverseTransformDirection(Ogre::Real x, Ogre::Real y, Ogre::Real z){

	return  this->InverseTransformDirection(Ogre::Vector3(x, y, z));
}



Ogre::Vector3 Transform::InverseTransformPoint(Ogre::Vector3 position){

	return this->convertWorldToLocalPosition(position);
}



Ogre::Vector3 Transform::InverseTransformPoint(Ogre::Real x, Ogre::Real y, Ogre::Real z){

	return  this->InverseTransformPoint(Ogre::Vector3(x, y, z));
}


void Transform::Translate(Ogre::Vector3 translation, TransformSpace relativeTo){
	this->translate(translation, relativeTo);
}


void Transform::Translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, TransformSpace relativeTo){
	this->translate(x, y, z, relativeTo);
}

void Transform::Translate(Ogre::Vector3 translation, Transform relativeTo) {
	Ogre::Matrix3 mat;
	relativeTo.rotation.ToRotationMatrix(mat);
	this->translate(mat, translation, TS_WORLD);
}
void Transform::Translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Transform relativeTo) {
	Ogre::Matrix3 mat;
	relativeTo.rotation.ToRotationMatrix(mat);
	this->translate(mat, Ogre::Vector3(x, y, z), TS_WORLD);
}

void Transform::Rotate(Ogre::Vector3 eulerAngles, TransformSpace relativeTo){
	Ogre::Matrix3 mat;
	Ogre::Radian yRad(eulerAngles.y), pRad(eulerAngles.x), rRad(eulerAngles.z);
	mat.FromEulerAnglesYXZ(yRad, pRad, rRad);
	Ogre::Quaternion quat(mat);

	this->rotate(quat, relativeTo);
}


void Transform::Rotate(Ogre::Real xAngle, Ogre::Real yAngle, Ogre::Real zAngle, TransformSpace relativeTo){
	Ogre::Matrix3 mat;
	Ogre::Radian yRad(yAngle), pRad(xAngle), rRad(zAngle);
	mat.FromEulerAnglesYXZ(yRad, pRad, rRad);
	Ogre::Quaternion quat(mat);

	this->rotate(quat, relativeTo);
}

void Transform::Rotate(Ogre::Vector3 axis, Ogre::Real angle, TransformSpace relativeTo){
	Ogre::Radian radAngle(angle);
	this->rotate(axis, radAngle, relativeTo);
}

void Transform::RotateAround(Ogre::Vector3 point, Ogre::Vector3 axis, Ogre::Real angle){
	
	Ogre::Vector3 position = this->position;
	Ogre::Quaternion quaternion; 
	quaternion.FromAngleAxis(Ogre::Radian(angle), axis);
	Ogre::Vector3 vector2 = (position - point);
	vector2 = ((Ogre::Vector3) (quaternion * vector2));
	position = (point + vector2);
	this->position = position;

	this->rotate(axis, Ogre::Radian(angle));
}
*/
