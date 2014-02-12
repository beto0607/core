/* 
 * File:   RectangleShape.cpp
 * Author: fran
 * 
 * Created on January 18, 2014, 4:06 PM
 */

#include <Collision/RectangleShape.h>
#include <Collision/Shape.h>
#include <Renderer/Renderable.h>
#include <iostream>

using namespace unnivelmas;

RectangleShape::RectangleShape():Shape() {
}

RectangleShape::~RectangleShape() {
}

GLvoid RectangleShape::checkCollision(Shape* _shape)
{
   GLfloat xradius = renderable->getWidth() + _shape->getRenderable()->getWidth();
   GLfloat yradius = renderable->getHeight() + _shape->getRenderable()->getHeight();
   GLfloat dist_x  = renderable->getX() - _shape->getRenderable()->getX();
   GLfloat dist_y  = renderable->getY() - _shape->getRenderable()->getY();
   if((std::abs(dist_x) < xradius) &&  (std::abs(dist_y) < yradius))
   {
       if(dist_x < 0 && std::abs(dist_x) > std::abs(dist_y))
       {
           renderable->rightCollision(_shape->getRenderable());
           _shape->getRenderable()->leftCollision(renderable);
       }
       if(dist_x > 0 && std::abs(dist_x) > std::abs(dist_y))
       {
           renderable->leftCollision(_shape->getRenderable());
           _shape->getRenderable()->rightCollision(renderable);
       }
       if(dist_y < 0 && std::abs(dist_x) < std::abs(dist_y))
       {
           renderable->bottomCollision(_shape->getRenderable());
           _shape->getRenderable()->topCollision(renderable);
       }
       if(dist_y > 0 && std::abs(dist_x) < std::abs(dist_y))
       {
           renderable->topCollision(_shape->getRenderable());
           _shape->getRenderable()->bottomCollision(renderable);
       }
   }
}

