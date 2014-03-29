/* 
 * File:   Actor.cpp
 * Author: francisco
 * 
 * Created on 5 de marzo de 2014, 23:54
 */

#include <Renderer/Actor.h>
#include <iostream>
#include <Renderer/Model3D.h>

using namespace kaikai;

Actor::Actor() {
           
}

Actor::~Actor() {
}

GLvoid Actor::setMeshCount(GLint _count)
{
    mesh_cant = _count;
}

GLint Actor::getMeshCount()
{
    return mesh_cant;
}

GLvoid Actor::setJointCount(GLint _count)
{
    joint_cant = _count;
}

GLint Actor::setJointCount()
{
    return joint_cant;
}

GLvoid Actor::draw(Scene* _scene)
{
    for(std::map<std::string,Renderable*>::iterator it = meshes.begin(); it != meshes.end(); ++it)
        it->second->draw(_scene);
}

GLvoid Actor::addRenderable(Renderable* _renderable)
{
    meshes.insert(std::pair<std::string,Renderable*>(_renderable->getName(), _renderable));
}

GLvoid Actor::move(GLfloat _x,GLfloat _y,GLfloat _z)
{
    for(std::map<std::string,Renderable*>::iterator it = meshes.begin(); it != meshes.end(); ++it)
        it->second->move(_x,_y,_z);
}

GLvoid Actor::scale(GLfloat _s)
{
     for(std::map<std::string,Renderable*>::iterator it = meshes.begin(); it != meshes.end(); ++it)
        it->second->scale(_s);
}

GLvoid Actor::setMaterial(const GLchar* _name, Material* _mat)
{
    meshes.find(std::string(_name))->second->setMaterial(_mat);
}