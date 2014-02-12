/* 
 * File:   CollisionEntity.h
 * Author: francisco
 *
 * Created on 14 de enero de 2014, 18:52
 */

#ifndef COLLISIONENTITY_H
#define	COLLISIONENTITY_H

#include "../Unnivelmas_conf.h"

namespace unnivelmas
{
    class Renderable;
    
    class Shape {
    public:
        Shape();
        virtual ~Shape();
        
        GLvoid setRenderable(Renderable*);
        Renderable* getRenderable();
        virtual GLvoid checkCollision(Shape*);
    protected:
        Renderable* renderable;
    };
}
#endif	/* COLLISIONENTITY_H */

