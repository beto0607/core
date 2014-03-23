/* 
 * File:   CameraStrategy.h
 * Author: francisco
 *
 * Created on 19 de marzo de 2014, 19:22
 */

#ifndef CAMERASTRATEGY_H
#define	CAMERASTRATEGY_H

#include "../../Unnivelmas_conf.h"

namespace kaikai
{
    class Camera;
    
    class CameraStrategy {
    public:
        CameraStrategy();
        virtual ~CameraStrategy();
        
         virtual GLvoid mouseMoved(GLfloat, GLfloat,Camera*);
         virtual GLvoid keyLEFTALTdown(Camera*);
         virtual GLvoid keyLEFTALTup(Camera*);
         virtual GLvoid keyRIGTHCTRdown(Camera*);
         virtual GLvoid keyRIGTHCTRup(Camera*);
         virtual GLvoid keyRIGTHSHIFTdown(Camera*);
         virtual GLvoid keyRIGTHSHIFTup(Camera*);
         virtual GLvoid update(GLfloat,Camera*);
    private:

        };
}
#endif	/* CAMERASTRATEGY_H */

