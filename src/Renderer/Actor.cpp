/* 
 * File:   Actor.cpp
 * Author: francisco
 * 
 * Created on 5 de marzo de 2014, 23:54
 */

#include <Renderer/Actor.h>
#include <Animation/Skeleton.h>
#include <iostream>
#include <Renderer/Model3D.h>

using namespace kaikai;

Actor::Actor() {
    skeleton = new Skeleton();
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

GLvoid Actor::setX(GLfloat _x)
{
    Renderable::setX(_x);
    for(std::map<std::string,Renderable*>::iterator it = meshes.begin(); it != meshes.end(); ++it)
        it->second->setX(_x);
}

GLvoid Actor::setY(GLfloat _y)
{
    Renderable::setY(_y);
    for(std::map<std::string,Renderable*>::iterator it = meshes.begin(); it != meshes.end(); ++it)
        it->second->setY(_y);
}

GLvoid Actor::setZ(GLfloat _z)
{
    Renderable::setZ(_z);
    for(std::map<std::string,Renderable*>::iterator it = meshes.begin(); it != meshes.end(); ++it)
        it->second->setZ(_z);
}

GLvoid Actor::setAngleX(GLfloat _x)
{
    Renderable::setAngleX(_x);
    for(std::map<std::string,Renderable*>::iterator it = meshes.begin(); it != meshes.end(); ++it)
        it->second->setAngleX(_x);
}

GLvoid Actor::setAngleY(GLfloat _y)
{
    Renderable::setAngleY(_y);
    for(std::map<std::string,Renderable*>::iterator it = meshes.begin(); it != meshes.end(); ++it)
        it->second->setAngleY(_y);
}

GLvoid Actor::setAngleZ(GLfloat _z)
{
    Renderable::setAngleZ(_z);
    for(std::map<std::string,Renderable*>::iterator it = meshes.begin(); it != meshes.end(); ++it)
        it->second->setAngleZ(_z);
}

GLvoid Actor::setJointCount(GLint _count)
{
    skeleton->setJointCant(_count);
}

GLint Actor::getJointCount()
{
    return skeleton->getJointCount();
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