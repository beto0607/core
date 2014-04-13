/* 
 * File:   Skeleton.cpp
 * Author: francisco
 * 
 * Created on 2 de abril de 2014, 12:21
 */

#include <Animation/Skeleton.h>
#include <iostream>

using namespace kaikai;

Skeleton::Skeleton() {
    joint_cant = 0;
}

Skeleton::~Skeleton() {
}

GLvoid Skeleton::setJointCant(GLint _cant)
{
    joint_cant = _cant;
}

GLint Skeleton::getJointCount()
{
    return joint_cant;
}

GLvoid Skeleton::allocateMemory(GLint vertex_cant)
{
    joint_rotation = new glm::mat4[joint_cant];
}
