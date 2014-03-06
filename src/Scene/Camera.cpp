/* 
 * File:   Camera.cpp
 * Author: francisco
 * 
 * Created on 12 de diciembre de 2013, 17:47
 */

#include <Scene/Camera.h>
#include <iostream>

using namespace kaikai;

Camera::Camera() {
    position = glm::vec3(0.0f,0.0f,2.0f);
    focus = glm::vec3(0.0f,0.0f,0.0f);
    angle = glm::vec3(0.0f,1.0f,0.0f);
    position_matrix = glm::lookAt(position,focus,angle);
}

Camera::~Camera() {
}

GLvoid Camera::setPositionX(GLfloat _x)
{
    position[0] = _x;
    focus[0] = _x;
    position_matrix = glm::lookAt(position,focus,angle);
}

GLvoid Camera::setPositionY(GLfloat _y)
{
    position[1] = _y;
    focus[1] = _y;
    position_matrix = glm::lookAt(position,focus,angle);
}

GLvoid Camera::setPositionZ(GLfloat _z)
{
    position[2] = _z;
    position_matrix = glm::lookAt(position,focus,angle);
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
    position_matrix = glm::lookAt(position,focus,angle);
}

GLvoid Camera::setFocusY(GLfloat _y)
{
    focus[1] = _y;
    position_matrix = glm::lookAt(position,focus,angle);
}

GLvoid Camera::setFocusZ(GLfloat _z)
{
    focus[2] = _z;
    position_matrix = glm::lookAt(position,focus,angle);
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
    position_matrix = glm::lookAt(position,focus,angle);
}

GLvoid Camera::setAngleY(GLfloat _y)
{
    angle[1] = _y;
    position_matrix = glm::lookAt(position,focus,angle);
}

GLvoid Camera::setAngleZ(GLfloat _z)
{
    angle[2] = _z;
    position_matrix = glm::lookAt(position,focus,angle);
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

GLvoid Camera::draw(Scene*)
{

}