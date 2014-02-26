/* 
 * File:   Move.cpp
 * Author: francisco
 * 
 * Created on 23 de diciembre de 2013, 19:50
 */
#include <Command/Command.h>
#include <Command/Move.h>
#include <Core/Core.h>
#include <iostream>

using namespace kaikai;

Move::Move():Command() {
}

Move::~Move() {
}

void Move::execute()
{
    GLfloat x,y;
    std::string id;
    std::cin >> id;
    std::cin >> x;
    std::cin >> y;
    (Core::getInstance())->moveObject(id.c_str(),x,y);
}