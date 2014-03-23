/* 
 * File:   Camera.h
 * Author: francisco
 *
 * Created on 12 de diciembre de 2013, 17:47
 */

#ifndef CAMERA_H
#define	CAMERA_H

#include "../../Unnivelmas_conf.h"
#include <Core/TimeEventListener.h>
#include <Input/MouseEventListener.h>
#include <Input/JoystickListener.h>
#include <Input/KeyBoardListener.h>
#include <string>

namespace kaikai{
    
    class CameraStrategy;
    class Renderable;
    class Scene;
    
    class Camera : public MouseEventListener, public TimeEventListener, public JoystickListener, public KeyBoardListener{
    public:
        Camera(const GLchar*);
        virtual ~Camera();
        
        GLvoid update(GLfloat);
        
        GLfloat* getMatrixView();
        GLvoid setName(std::string);
        std::string getName();
        
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
        
        GLvoid mouseMoved(GLfloat, GLfloat);
        GLvoid keyLEFTALTdown();
        GLvoid keyLEFTALTup();
        GLvoid keyRIGTHCTRdown();
        GLvoid keyRIGTHCTRup();
        GLvoid keyLEFTSHIFTdown();
        GLvoid keyLEFTSHIFTup();
        GLvoid setFreeCamera();
        GLvoid setFollowerCamera(Renderable*, GLfloat,GLfloat,GLfloat);
        
    private:
        std::string name;
        glm::vec3 position;
        glm::vec3 focus;
        glm::vec3 angle;
        glm::mat4 matrix;
        CameraStrategy* type;
        };
}
#endif	/* CAMERA_H */

