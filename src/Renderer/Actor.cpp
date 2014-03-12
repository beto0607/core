/* 
 * File:   Actor.cpp
 * Author: francisco
 * 
 * Created on 5 de marzo de 2014, 23:54
 */

#include <Renderer/Actor.h>

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

GLvoid Actor::draw(Scene*)
{

}
