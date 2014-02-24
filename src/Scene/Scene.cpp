/* 
 * File:   Scene.cpp
 * Author: francisco
 * 
 * Created on 12 de diciembre de 2013, 17:45
 */

#include <Scene/Scene.h>
#include <Renderer/RenderableBuffer.h>
#include <list>

using namespace unnivelmas;

Scene::Scene() {
    
}

Scene::~Scene() {
}

GLvoid Scene::drawBuffer()
{
    //std::cout << "WARN: it´s not a Scene Active\n";
}

GLvoid Scene::addRenderable(const GLchar*,Renderable*)
{

}

GLvoid  Scene::scaleObject(const GLchar*, GLfloat)
{

}

GLvoid  Scene::moveObject(const GLchar*, GLfloat,GLfloat)
{

}

GLvoid Scene::addCollider(Shape* _shape)
{

}

GLvoid Scene::addCollidable(Shape* _shape)
{

}

Renderable* Scene::getRenderable(const GLchar* _file_name)
{
    
}
        