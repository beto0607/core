/* 
 * File:   SetFps.cpp
 * Author: fran
 * 
 * Created on January 13, 2014, 11:29 PM
 */

#include <Command/SetFps.h>
#include <Command/Command.h>
#include <Core/Core.h>
#include <iostream>

using namespace kaikai;

SetFps::SetFps() {
}

SetFps::~SetFps() {
}

GLvoid SetFps::execute()
{
    GLint fps;
    std::cin >> fps;
    Core::getInstance()->setFPS(fps);
}