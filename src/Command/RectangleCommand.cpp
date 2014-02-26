/* 
 * File:   RectangleCommand.cpp
 * Author: francisco
 * 
 * Created on 8 de enero de 2014, 19:19
 */

#include <Command/Command.h>
#include <Command/RectangleCommand.h>
#include <Renderer/RenderBuilder.h>
#include <Renderer/Rectangle.h>
#include <Renderer/Render.h>
#include <Core/Core.h>
#include <string>
#include <iostream>

using namespace kaikai;

RectangleCommand::RectangleCommand() {
}

RectangleCommand::~RectangleCommand() {
}

GLvoid RectangleCommand::execute()
{
    GLfloat weigth, heigth;
    std::string id;
    std::cin >> id; 
    std::cin >> heigth;
    std::cin >> weigth;
    SDL_GL_MakeCurrent((Core::getInstance())->getRenderManager()->getWindow(), (Core::getInstance())->getRenderManager()->getThreadContext());
    (Core::getInstance())->getRenderBuilder()->createRectangle(id.c_str(),heigth,weigth);
    SDL_GL_MakeCurrent((Core::getInstance())->getRenderManager()->getWindow(), NULL);
    std::cout << "Rectangle was Created Sussefully ID: " << id.c_str() << "\n";
}

