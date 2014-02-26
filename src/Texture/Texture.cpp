/* 
 * File:   Texture.cpp
 * Author: fran
 * 
 * Created on December 25, 2013, 10:03 PM
 */

#include <Texture/Texture.h>
#include <iostream>
#include <string>

using namespace kaikai;

Texture::Texture(const GLchar* _name, GLuint _id) {
    name = std::string(_name);
    id = _id;   
}

Texture::~Texture() {
}

GLuint Texture::getTexture()
{
    return id;
}

GLvoid Texture::setTexture(GLuint _id)
{
    id = _id;
}