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
    for(std::list<Renderable*>::iterator it = meshes.begin(); it != meshes.end(); ++it)
        (*it)->draw(_scene);
}

GLvoid Actor::addRenderable(Renderable* _renderable)
{
    meshes.push_back(_renderable);
}

GLvoid Actor::move(GLfloat _x,GLfloat _y,GLfloat _z)
{
    for(std::list<Renderable*>::iterator it = meshes.begin(); it != meshes.end(); ++it)
        (*it)->move(_x,_y,_z);
}

GLvoid Actor::scale(GLfloat _s)
{
     for(std::list<Renderable*>::iterator it = meshes.begin(); it != meshes.end(); ++it)
        (*it)->scale(_s);
}
