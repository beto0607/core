/* 
 * File:   Camera.h
 * Author: francisco
 *
 * Created on 12 de diciembre de 2013, 17:47
 */

#ifndef CAMERA_H
#define	CAMERA_H

#include "../Unnivelmas_conf.h"
#include <Renderer/Renderable.h>

namespace kaikai{
    
    class Scene;
    
    class Camera : public Renderable{
    public:
        Camera();
        virtual ~Camera();
        
        GLvoid setX(GLfloat);
        GLvoid setY(GLfloat);
        GLvoid setZ(GLfloat);
        GLfloat getX();
        GLfloat getY();
        GLfloat getZ();
        
        GLvoid move(GLfloat, GLfloat);
        GLvoid move(GLfloat, GLfloat, GLfloat);
        
        GLvoid draw(Scene*);
        
    private:
        
        };
}
#endif	/* CAMERA_H */

