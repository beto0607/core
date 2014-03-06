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
        
        GLvoid setPositionX(GLfloat);
        GLvoid setPositionY(GLfloat);
        GLvoid setPositionZ(GLfloat);
        GLfloat getPositionX();
        GLfloat getPositionY();
        GLfloat getPositionZ();
        
        GLvoid setFocusX(GLfloat);
        GLvoid setFocusY(GLfloat);
        GLvoid setFocusZ(GLfloat);
        GLfloat getFocusX();
        GLfloat getFocusY();
        GLfloat getFocusZ();
        
        GLvoid setAngleX(GLfloat);
        GLvoid setAngleY(GLfloat);
        GLvoid setAngleZ(GLfloat);
        GLfloat getAngleX();
        GLfloat getAngleY();
        GLfloat getAngleZ();
        
        GLvoid draw(Scene*);
        
    private:
        glm::vec3 position;
        glm::vec3 focus;
        glm::vec3 angle;
        };
}
#endif	/* CAMERA_H */

