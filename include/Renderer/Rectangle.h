/* 
 * File:   Rectangle.h
 * Author: fran
 *
 * Created on December 11, 2013, 9:15 AM
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H

#include <Renderer/Model2D.h>
#include <Input/MouseEventListener.h>
#include <Core/TimeEventListener.h>

namespace unnivelmas
{
    class Rectangle : public Model2D, public MouseEventListener, public TimeEventListener
    {
        public:
            Rectangle(GLfloat,GLfloat);
            virtual ~Rectangle();
            
            GLvoid keyPressed();
            GLvoid mouseMoved(GLfloat,GLfloat);
            GLvoid update(GLfloat);
            
            GLvoid topCollision(Renderable*);
            GLvoid bottomCollision(Renderable*);
            GLvoid leftCollision(Renderable*);
            GLvoid rightCollision(Renderable*);
            
        private:
    };
}
#endif	/* RECTANGLE_H */

