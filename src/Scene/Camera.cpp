/* 
 * File:   Camera.cpp
 * Author: francisco
 * 
 * Created on 12 de diciembre de 2013, 17:47
 */

#include <Scene/Camera.h>

using namespace unnivelmas;

Camera::Camera() {
    position = glm::mat4(1.0,0.0,0.0,0.0,
                         0.0,1.0,0.0,0.0,
                         0.0,0.0,1.0,0.0,
                         0.0,0.0,0.0,1.0);
    angle    = glm::mat4(1.0,0.0,0.0,0.0,
                         0.0,1.0,0.0,0.0,
                         0.0,0.0,1.0,0.0,
                         0.0,0.0,0.0,1.0);
}

Camera::~Camera() {
}

GLvoid Camera::move(GLfloat x,GLfloat y,GLfloat z)
{
    position[0][0] += x;
    position[1][1] += y;
    position[2][2] += z;
}

GLvoid Camera::rotate(GLfloat x,GLfloat y,GLfloat z)
{

}