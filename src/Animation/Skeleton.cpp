/* 
 * File:   Skeleton.cpp
 * Author: francisco
 * 
 * Created on 2 de abril de 2014, 12:21
 */

#include <Animation/Skeleton.h>
#include <Renderer/Renderable.h>
#include <Animation/Joint.h>
#include <Renderer/RenderableStrategies/InvisibleDraw.h>
#include <Shader/JointShader.h>
#include <iostream>
#include <map>

using namespace kaikai;

Skeleton::Skeleton() {
    shader = new JointShader();
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
    joint_inverted_matrix = new glm::mat4[joint_cant];
}

GLfloat* Skeleton::getInvertedPoseMatrixArray()
{
    return glm::value_ptr(joint_inverted_matrix[0]);
}

GLvoid Skeleton::setJoint(Joint* _joint)
{
    joint_collection.insert(std::pair<GLint,Joint*>(_joint->getId(),_joint));
    if(_joint->getParentId() == -1)
    {
        _joint->setInvertedMatrix(this);
        this->joint_root = _joint; 
    }
    else
    {
        std::map<GLint,Joint*>::iterator it = joint_collection.find(_joint->getParentId()); 
        if(it != joint_collection.end())
            it->second->addChild(_joint);
    }
}

GLvoid Skeleton::draw(Scene* _scene)
{
    glLineWidth(5.f);
    joint_root->draw(_scene,shader);
    glLineWidth(1.f);
}

GLvoid Skeleton::setX(GLfloat _x)
{
    for(std::map<GLint,Joint*>::iterator it = joint_collection.begin(); it != joint_collection.end(); ++it)
        it->second->setX(_x);
}

GLvoid Skeleton::setY(GLfloat _y)
{
    for(std::map<GLint,Joint*>::iterator it = joint_collection.begin(); it != joint_collection.end(); ++it)
        it->second->setY(_y);
}

GLvoid Skeleton::setZ(GLfloat _z)
{
    for(std::map<GLint,Joint*>::iterator it = joint_collection.begin(); it != joint_collection.end(); ++it)
        it->second->setZ(_z);
}
        
GLvoid Skeleton::setAngleX(GLfloat _x)
{
    for(std::map<GLint,Joint*>::iterator it = joint_collection.begin(); it != joint_collection.end(); ++it)
        it->second->setAngleX(_x);
}

GLvoid Skeleton::setAngleY(GLfloat _y)
{
    for(std::map<GLint,Joint*>::iterator it = joint_collection.begin(); it != joint_collection.end(); ++it)
        it->second->setAngleY(_y);
}

GLvoid Skeleton::setAngleZ(GLfloat _z)
{
    for(std::map<GLint,Joint*>::iterator it = joint_collection.begin(); it != joint_collection.end(); ++it)
        it->second->setAngleZ(_z);
}

GLvoid Skeleton::update(GLfloat _tick)
{
    
}