/* 
 * File:   EscalarX.cpp
 * Author: beto0607
 * 
 * Created on 31 de mayo de 2014, 18:26
 */

#include <Command/EscalarX.h>
#include<Command/Command.h>
#include <iostream>
#include <Core/Core.h>

#include "Renderer/Renderable.h"

using namespace kaikai;

EscalarX::EscalarX() : Command(){
}


EscalarX::~EscalarX() {
}

void EscalarX::execute(){
    GLfloat scale;
    std::string id;
    std::cin >> id;
    std::cin >> scale;     
    (Core::getInstance())->getRenderable(id.c_str())->scaleX(scale);
}