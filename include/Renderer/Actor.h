/* 
 * File:   Actor.h
 * Author: francisco
 *
 * Created on 5 de marzo de 2014, 23:54
 */

#ifndef ACTOR_H
#define	ACTOR_H

#include <Renderer/Renderable.h>
#include <list>

namespace kaikai
{
    class Scene;
    
    class Actor : public Renderable{
    public:
        Actor(const GLchar*);
        virtual ~Actor();
 
        GLvoid draw(Scene*);
    private:
        std::list<Renderable*> meshes;
    };
}
#endif	/* ACTOR_H */

