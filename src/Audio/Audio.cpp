/* 
 * File:   Audio.cpp
 * Author: fran
 * 
 * Created on January 22, 2014, 9:03 PM
 */

#include <Audio/Audio.h>
#include <string>

using namespace unnivelmas;

Audio::Audio(const GLchar* _name) {
    name = std::string(_name);
}

Audio::~Audio() {
}

const GLchar* Audio::getName()
{
    return name.c_str();
}
