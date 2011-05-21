///////////////////////////////////////////////////////////
//  MeshRenderer.cpp
//  Implementation of the Class MeshRenderer
//  Created on:      07-апр-2011 22:55:58
//  Original author: Max Payne
///////////////////////////////////////////////////////////

#include "MeshRenderer.h"
//#include "ogre_test.h"

#include <OgreMeshManager.h>

#include "mainwindow.h"
#include "QtWidget.h"

MeshRenderer::MeshRenderer(){
	
}

MeshRenderer::MeshRenderer(Ogre::String name, Ogre::String mesh, Ogre::String material){

    entity = MainWindow::getInstance()->ogreWindow->getSceneManager()->createEntity(name, mesh);
    entity->setMaterialName(material);
    entity->setQueryFlags(OgreWidget::NONE_MASK);
}

MeshRenderer::~MeshRenderer(){
    delete entity;
}
/*

Ogre::MeshPtr MeshRenderer::get_mesh()
{
	return this->getMesh();
}

void MeshRenderer::set_mesh(Ogre::Mesh &mesh)
{
	
}
*/
