/* 
 * File:   RectangleShape.h
 * Author: fran
 *
 * Created on January 18, 2014, 4:06 PM
 */

#ifndef RECTANGLESHAPE_H
#define	RECTANGLESHAPE_H

#include <Collision/Shape.h>

namespace kaikai
{
    class Renderable;
    
    class RectangleShape : public Shape {
    public:
        RectangleShape();
        virtual ~RectangleShape();
        
        GLvoid checkCollision(Shape*);
    private:
        };
}
#endif	/* RECTANGLESHAPE_H */

