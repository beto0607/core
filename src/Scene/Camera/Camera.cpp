/* 
 * File:   Camera.cpp
 * Author: francisco
 * 
 * Created on 12 de diciembre de 2013, 17:47
 */

#include <Scene/Camera/Camera.h>
#include <Scene/Camera/CameraStrategy.h>
#include <Scene/Camera/FreeCameraStrategy.h>
#include <Scene/Camera/FollowerCameraStrategy.h>
#include <Core/Core.h>
#include <iostream>


using namespace kaikai;

Camera::Camera(const GLchar* _name) {
    type = new CameraStrategy();
    position = glm::vec3(0.0f,0.0f,10.0f);
    focus = glm::vec3(0.0f,0.0f,0.0f);
    angle = glm::vec3(0.0f,1.0f,0.0f);
    name = std::string(_name);
    matrix = glm::lookAt(position,focus,angle);
}

Camera::~Camera() {
}

GLvoid Camera::setPositionX(GLfloat _x)
{
    position[0] = _x;
    focus[0] = _x;
    matrix = glm::lookAt(position,focus,angle);
}

GLvoid Camera::setPositionY(GLfloat _y)
{
    position[1] = _y;
    focus[1] = _y;
    matrix = glm::lookAt(position,focus,angle);
}

GLvoid Camera::setPositionZ(GLfloat _z)
{
    position[2] = _z;
    matrix = glm::lookAt(position,focus,angle);
}

GLfloat Camera::getPositionX()
{
    return position[0];
}

GLfloat Camera::getPositionY()
{
   return position[1];
}

GLfloat Camera::getPositionZ()
{
    return position[2];
}

GLvoid Camera::setFocusX(GLfloat _x)
{
    focus[0] = _x;
    matrix = glm::lookAt(position,focus,angle);
}

GLvoid Camera::setFocusY(GLfloat _y)
{
    focus[1] = _y;
    matrix = glm::lookAt(position,focus,angle);
}

GLvoid Camera::setFocusZ(GLfloat _z)
{
    focus[2] = _z;
    matrix = glm::lookAt(position,focus,angle);
}

GLfloat Camera::getFocusX()
{
    return focus[0];
}

GLfloat Camera::getFocusY()
{
   return focus[1];
}

GLfloat Camera::getFocusZ()
{
    return focus[2];
}

GLvoid Camera::setAngleX(GLfloat _x)
{
    angle[0] = _x;
    matrix = glm::lookAt(position,focus,angle);
}

GLvoid Camera::setAngleY(GLfloat _y)
{
    angle[1] = _y;
    matrix = glm::lookAt(position,focus,angle);
}

GLvoid Camera::setAngleZ(GLfloat _z)
{
    angle[2] = _z;
    matrix = glm::lookAt(position,focus,angle);
}

GLfloat Camera::getAngleX()
{
    return angle[0];
}

GLfloat Camera::getAngleY()
{
   return angle[1];
}

GLfloat Camera::getAngleZ()
{
    return angle[2];
}

GLfloat* Camera::getMatrixView()
{
    return glm::value_ptr(this->matrix);
}

GLvoid Camera::setName(std::string _name)
{
    name = _name;
}

std::string Camera::getName()
{
    return name;
}

GLvoid Camera::update(GLfloat _tick)
{
    type->update(_tick,this);
}

GLvoid Camera::setFreeCamera()
{
    (Core::getInstance())->addAllStateKeyListener("Left Alt",this);
    (Core::getInstance())->addAllStateKeyListener("Left Shift",this);
    (Core::getInstance())->addAllStateKeyListener("Right Ctrl",this);
    (Core::getInstance())->addMouseMovedListener(this);
    (Core::getInstance())->addTimeListener(this);
    type = new FreeCameraStrategy();
}

GLvoid Camera::setFollowerCamera(Renderable* _renderable, GLfloat _x ,GLfloat _y,GLfloat _z)
{
    (Core::getInstance())->addTimeListener(this);
    type = new FollowerCameraStrategy(_renderable,_x,_y,_z);
}

GLvoid Camera::mouseMoved(GLfloat _x, GLfloat _y)
{
    type->mouseMoved(_x,_y,this);
}

GLvoid Camera::keyLEFTALTdown()
{
    type->keyLEFTALTdown(this);
}

GLvoid Camera::keyLEFTALTup()
{
    type->keyLEFTALTup(this);
}

GLvoid Camera::keyRIGTHCTRdown()
{
    type->keyRIGTHCTRdown(this);
}

GLvoid Camera::keyRIGTHCTRup()
{
    type->keyRIGTHCTRup(this);
}

GLvoid Camera::keyLEFTSHIFTdown()
{
    type->keyRIGTHSHIFTdown(this);
}

GLvoid Camera::keyLEFTSHIFTup()
{
    type->keyRIGTHSHIFTup(this);
}