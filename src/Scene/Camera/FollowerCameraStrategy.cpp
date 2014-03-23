/* 
 * File:   FollowerCameraStrategy.cpp
 * Author: francisco
 * 
 * Created on 23 de marzo de 2014, 16:53
 */

#include <Scene/Camera/FollowerCameraStrategy.h>
#include <Renderer/Renderable.h>
#include <Scene/Camera/Camera.h>
#include <iostream>
#include <cmath>

using namespace kaikai;

FollowerCameraStrategy::FollowerCameraStrategy(Renderable* _renderable,GLfloat _x ,GLfloat _y ,GLfloat _z) {
    follower = _renderable;
    maxDistanseX = _x;
    maxDistanseY = _y;
    maxDistanseZ = _z;
}

FollowerCameraStrategy::~FollowerCameraStrategy() {
}

GLvoid FollowerCameraStrategy::mouseMoved(GLfloat _x, GLfloat _y, Camera* _camera)
{

}

GLvoid FollowerCameraStrategy::update(GLfloat _tick, Camera* _camera)
{
    GLfloat difX = _camera->getPositionX() - follower->getX();
    GLfloat absX = std::abs(difX);
    GLfloat difY = _camera->getPositionY() - follower->getY();
    GLfloat absY = std::abs(difY);
    GLfloat difZ = _camera->getPositionZ() - follower->getZ();
    GLfloat absZ = std::abs(difZ);
    if(absX > maxDistanseX)
    {
        (difX<0)?_camera->setPositionX( _camera->getPositionX() + (absX - maxDistanseX)):_camera->setPositionX( _camera->getPositionX() - (absX - maxDistanseX));
    }
    if(absY > maxDistanseY)
    {
        (difY<0)?_camera->setPositionY( _camera->getPositionY() + (absY - maxDistanseY)):_camera->setPositionY( _camera->getPositionY() - (absY - maxDistanseY));
    }
    if(absZ > maxDistanseZ)
    {
        (difZ<0)?_camera->setPositionZ( _camera->getPositionZ() + (absZ - maxDistanseZ)):_camera->setPositionZ( _camera->getPositionZ() - (absZ - maxDistanseZ));
    }
}

GLvoid FollowerCameraStrategy::keyLEFTALTdown(Camera* _camera)
{

}
         
GLvoid FollowerCameraStrategy::keyLEFTALTup(Camera* _camera)
{

}

GLvoid FollowerCameraStrategy::keyRIGTHCTRdown(Camera* _camera)
{

}

GLvoid FollowerCameraStrategy::keyRIGTHCTRup(Camera* _camera)
{

}

GLvoid FollowerCameraStrategy::keyRIGTHSHIFTdown(Camera* _camera)
{

}

GLvoid FollowerCameraStrategy::keyRIGTHSHIFTup(Camera* _camera)
{

}
