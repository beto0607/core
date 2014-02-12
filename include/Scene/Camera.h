/* 
 * File:   Camera.h
 * Author: francisco
 *
 * Created on 12 de diciembre de 2013, 17:47
 */

#ifndef CAMERA_H
#define	CAMERA_H

#include "../Unnivelmas_conf.h"

namespace unnivelmas{
    
    class Camera {
    public:
        Camera();
        virtual ~Camera();
        
        GLvoid move(GLfloat,GLfloat,GLfloat);
        GLvoid rotate(GLfloat,GLfloat,GLfloat);
    private:
        glm::mat4 position;
        glm::mat4 angle;
        
        };
}
#endif	/* CAMERA_H */

