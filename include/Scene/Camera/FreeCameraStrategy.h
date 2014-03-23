/* 
 * File:   FreeCameraStrategy.h
 * Author: francisco
 *
 * Created on 19 de marzo de 2014, 19:28
 */

#ifndef FREECAMERASTRATEGY_H
#define	FREECAMERASTRATEGY_H

#include <Scene/Camera/CameraStrategy.h>

namespace kaikai
{
    class Camera;
    
    class FreeCameraStrategy : public CameraStrategy{
    public:
        FreeCameraStrategy();
        virtual ~FreeCameraStrategy();
        
         GLvoid mouseMoved(GLfloat, GLfloat,Camera*);
         GLvoid keyLEFTALTdown(Camera*);
         GLvoid keyLEFTALTup(Camera*);
         GLvoid keyRIGTHCTRdown(Camera*);
         GLvoid keyRIGTHCTRup(Camera*);
         GLvoid keyRIGTHSHIFTdown(Camera*);
         GLvoid keyRIGTHSHIFTup(Camera*);
         GLvoid update(GLfloat,Camera*);
    private:
        GLint altpresed,ctrlpressed,shiftpressed;
        GLfloat difX,difY,lastX,lastY;
    };
}
#endif	/* FREECAMERASTRATEGY_H */

