/* 
 * File:   Skeleton.cpp
 * Author: francisco
 * 
 * Created on 2 de abril de 2014, 12:21
 */

#include <Animation/Skeleton.h>

using namespace kaikai;

Skeleton::Skeleton() {
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
