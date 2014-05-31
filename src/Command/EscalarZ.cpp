/* 
 * File:   EscalarZ.cpp
 * Author: beto0607
 * 
 * Created on 31 de mayo de 2014, 18:26
 */

#include <Command/EscalarZ.h>
#include<Command/Command.h>
#include <iostream>
#include <Core/Core.h>
#include "Renderer/Renderable.h"

using namespace kaikai;

EscalarZ::EscalarZ():Command() {
}

EscalarZ::~EscalarZ() {
}

void EscalarZ::execute()
{
    GLfloat scale;
    std::string id;
    std::cin >> id;
    std::cin >> scale;     
    (Core::getInstance())->getRenderable(id.c_str())->scaleZ(scale);
}