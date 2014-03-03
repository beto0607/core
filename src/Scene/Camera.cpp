/* 
 * File:   Camera.cpp
 * Author: francisco
 * 
 * Created on 12 de diciembre de 2013, 17:47
 */

#include <Scene/Camera.h>
#include <iostream>

using namespace kaikai;

Camera::Camera():Renderable() {
}

Camera::~Camera() {
}

GLvoid Camera::setX(GLfloat _x)
{
    Renderable::setX(_x*-1);
}

GLvoid Camera::setY(GLfloat _y)
{
    Renderable::setY(_y*-1);
}

GLvoid Camera::setZ(GLfloat _z)
{
    Renderable::setZ(_z*-1);
}

GLfloat Camera::getX()
{
    return Renderable::getX() * -1;
}

GLfloat Camera::getY()
{
   return Renderable::getY() * -1;
}

GLfloat Camera::getZ()
{
    return Renderable::getZ() * -1;
}

GLvoid Camera::move(GLfloat _x, GLfloat _y)
{
    position_matrix[0][3] += (_x * -1);
    position_matrix[1][3] += (_y * -1);
}

GLvoid Camera::move(GLfloat _x, GLfloat _y, GLfloat _z)
{
    position_matrix[0][3] += (_x * -1);
    position_matrix[1][3] += (_y * -1);
    position_matrix[2][3] += (_z * -1);
}

GLvoid Camera::draw(Scene*)
{

}