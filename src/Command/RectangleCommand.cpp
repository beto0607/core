/* 
 * File:   RectangleCommand.cpp
 * Author: francisco
 * 
 * Created on 8 de enero de 2014, 19:19
 */

#include <Command/Command.h>
#include <Command/RectangleCommand.h>
#include <Core/Core.h>
#include <Renderer/Rectangle.h>
#include <string>
#include <iostream>

using namespace unnivelmas;

RectangleCommand::RectangleCommand() {
}

RectangleCommand::~RectangleCommand() {
}

GLvoid RectangleCommand::execute()
{
    GLint weigth, heigth;
    std::string id;
    std::cin >> id; 
    std::cin >> heigth;
    std::cin >> weigth;
    (Core::getInstance())->addRenderable(id.c_str(),new Rectangle(heigth,weigth));
    std::cout << "Rectangle was Created Sussefully id: " << id << "\n";
}

