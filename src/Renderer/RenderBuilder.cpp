/* 
 * File:   RenderBuilder.cpp
 * Author: francisco
 * 
 * Created on 19 de febrero de 2014, 10:06
 */

#include <Renderer/RenderBuilder.h>
#include <Renderer/Renderable.h>
#include <Renderer/Rectangle.h>
#include <Core/Core.h>

using namespace unnivelmas;

RenderBuilder::RenderBuilder() {
}

RenderBuilder::~RenderBuilder() {
}

GLvoid RenderBuilder::createRectangle(const GLchar* _name, GLfloat _height, GLfloat _weigth)
{
    (Core::getInstance())->addRenderable(new Rectangle(_name,_height, _weigth));
}