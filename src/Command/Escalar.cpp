/* 
 * File:   Escalar.cpp
 * Author: francisco
 * 
 * Created on 22 de diciembre de 2013, 19:03
 */

#include <Command/Escalar.h>
#include<Command/Command.h>
#include <iostream>
#include <Core/Core.h>

using namespace kaikai;

Escalar::Escalar():Command() {
}

Escalar::~Escalar() {
}

void Escalar::execute()
{
    GLfloat scale;
    std::string id;
    std::cin >> id;
    std::cin >> scale;     
    (Core::getInstance())->scaleObject(id.c_str(),scale);
}