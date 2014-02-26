/* 
 * File:   CollisionManager.cpp
 * Author: francisco
 * 
 * Created on 14 de enero de 2014, 18:24
 */

#include <Collision/CollisionManager.h>
#include <Log/Logger.h>
#include <Collision/Shape.h>
#include <iostream>
#include <list>

using namespace kaikai;

CollisionManager::CollisionManager() {
    Logger::getInstance()->infoLog("CollisionManager was created susefully");
}

CollisionManager::~CollisionManager() {
    Logger::getInstance()->infoLog("CollisionManager was destroyed");
}

GLvoid CollisionManager::addCollider(Shape* entity)
{
    this->colliders.push_back(entity);
}

GLvoid CollisionManager::addColliding(Shape* entity)
{
    this->colliding.push_back(entity);
}
        
GLvoid CollisionManager::checkCollision()
{
    for(std::list<Shape*>::iterator it = colliders.begin(); it != colliders.end(); ++it)
        for(std::list<Shape*>::iterator it_colliding = colliding.begin(); it_colliding != colliding.end(); ++it_colliding)
            (*it)->checkCollision(*it_colliding);
}

