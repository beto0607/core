/* 
 * File:   Sprite.cpp
 * Author: fran
 * 
 * Created on January 21, 2014, 10:06 PM
 */

#include <Animation/Sprite.h>
#include <Renderer/Renderable.h>
#include <iostream>

using namespace unnivelmas;

Sprite::Sprite(GLfloat dx, GLfloat dy, GLint _row, GLint _column) {
    uv_coords = new GLfloat[8];
    uv_coords[2] =(dx * _column);uv_coords[3] =1-(dy * (_row+1));
    uv_coords[0] =(dx * _column);uv_coords[1] =1-(dy * _row);
    uv_coords[6] =(dx * (_column+1));uv_coords[7] =1-(dy * (_row+1));
    uv_coords[4] =(dx * (_column+1));uv_coords[5] =1-(dy * _row);
           
}

Sprite::~Sprite() {
    delete uv_coords;
}

GLvoid Sprite::setSprite(Renderable* _renderable)
{
    _renderable->setUVCoordinates(uv_coords);
}
