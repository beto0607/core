/* 
 * File:   SceneReal.cpp
 * Author: francisco
 * 
 * Created on 1 de enero de 2014, 18:32
 */

#include <Scene/Scene.h>
#include <Scene/SceneReal.h>
#include <Collision/Shape.h>
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <Renderer/Renderable.h>
#include <Collision/CollisionManager.h>

using namespace kaikai;

SceneReal::SceneReal():Scene() {
    renderables = new std::map<std::string,Renderable*>();
    collision_manager = new CollisionManager();
}

SceneReal::~SceneReal() {
}

GLvoid SceneReal::drawBuffer()
{
   collision_manager->checkCollision();
   for(std::map<std::string,Renderable*>::iterator it = renderables->begin(); it != renderables->end();++it)
   {
       ((*it).second)->drawRenderable(this);
   }

}

GLvoid SceneReal::addRenderable(const GLchar* renderable_id,Renderable* render)
{
    renderables->insert(std::pair<std::string,Renderable*>(std::string(renderable_id),render));
}

GLvoid  SceneReal::scaleObject(const GLchar* id, GLfloat _scale)
{
    std::string local_id = std::string(id);
    if(renderables->find(local_id) == renderables->end())
    {
       std::cout << "(ERROR) we coudn't find " << id << "\n";       
    }
    else
    {
       (renderables->find(local_id)->second)->scale(_scale); 
        std::cout << "id: " << id << " size: " << _scale << "\n";
    }
}

GLvoid  SceneReal::moveObject(const GLchar* id, GLfloat _x,GLfloat _y)
{
    std::string local_id = std::string(id);
    if(renderables->find(local_id) == renderables->end())
    {
        std::cout << "(ERROR) we coudn't find " << id << "\n";
    }
    else
    {
        (renderables->find(local_id)->second)->move(_x,_y);
        std::cout << "id: " << id << " moved X: " << _x << " Y: " << _y << "\n";
    }
}

GLvoid SceneReal::addCollider(Shape* _shape)
{
    this->collision_manager->addCollider(_shape);
}

GLvoid SceneReal::addCollidable(Shape* _shape)
{
    this->collision_manager->addColliding(_shape);
}

Renderable* SceneReal::getRenderable(const GLchar* _id)
{
    std::string local_id = std::string(_id);
    Renderable* resu;
    if(renderables->find(local_id) == renderables->end())
    {
        std::cout << "(ERROR) we coudn't find " << _id << "\n";
    }
    else
    {
        resu = renderables->find(local_id)->second;
    }
    return resu;
}