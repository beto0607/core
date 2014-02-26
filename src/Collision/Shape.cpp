/* 
 * File:   CollisionEntity.cpp
 * Author: francisco
 * 
 * Created on 14 de enero de 2014, 18:52
 */

#include <Collision/Shape.h>

using namespace kaikai;

Shape::Shape() {
}

Shape::~Shape() {
}

GLvoid Shape::checkCollision(Shape* _shape)
{

}

GLvoid Shape::setRenderable(Renderable* _renderable)
{
    renderable = _renderable;
}

Renderable* Shape::getRenderable()
{
    return renderable;
}