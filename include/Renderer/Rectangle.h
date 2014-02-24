/* 
 * File:   Rectangle.h
 * Author: fran
 *
 * Created on December 11, 2013, 9:15 AM
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H

#include <Renderer/Model2D.h>

namespace unnivelmas
{
    class Rectangle : public Model2D
    {
        public:
            Rectangle(const GLchar*,GLfloat,GLfloat);
            virtual ~Rectangle();
            
            GLvoid topCollision(Renderable*);
            GLvoid bottomCollision(Renderable*);
            GLvoid leftCollision(Renderable*);
            GLvoid rightCollision(Renderable*);
            
        private:
    };
}
#endif	/* RECTANGLE_H */

