/* 
 * File:   CollisionManager.h
 * Author: francisco
 *
 * Created on 14 de enero de 2014, 18:24
 */

#ifndef COLLISIONMANAGER_H
#define	COLLISIONMANAGER_H

#include "../Unnivelmas_conf.h"
#include <list>

namespace kaikai
{
    class Shape;
    
    class CollisionManager {
    public:
        CollisionManager();
        virtual ~CollisionManager();
        
        GLvoid addCollider(Shape*);
        GLvoid addColliding(Shape*);
        
        GLvoid checkCollision();
    private:
        std::list<Shape*> colliders;
        std::list<Shape*> colliding;
    };
}
#endif	/* COLLISIONMANAGER_H */

