/* 
 * File:   SceneReal.h
 * Author: francisco
 *
 * Created on 1 de enero de 2014, 18:32
 */

#ifndef SCENEREAL_H
#define	SCENEREAL_H

#include <Scene/Scene.h>

namespace unnivelmas
{
    class Renderable;
    
    class SceneReal : public Scene{
    public:
        SceneReal();
        virtual ~SceneReal();
        
        GLvoid drawBuffer();
        GLvoid addRenderable(const GLchar*,Renderable*);
        GLvoid scaleObject(const GLchar*, GLfloat);
        GLvoid moveObject(const GLchar*, GLfloat,GLfloat);
        GLvoid addCollider(Shape*);
        GLvoid addCollidable(Shape*);
        Renderable* getRenderable(const GLchar*);
        
    private:

    };
}
#endif	/* SCENEREAL_H */

