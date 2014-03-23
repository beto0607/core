/* 
 * File:   FollowerCameraStrategy.h
 * Author: francisco
 *
 * Created on 23 de marzo de 2014, 16:53
 */

#ifndef FOLLOWERCAMERASTRATEGY_H
#define	FOLLOWERCAMERASTRATEGY_H

#include <Scene/Camera/CameraStrategy.h>

namespace kaikai
{
    class Renderable;
    
    class FollowerCameraStrategy : public CameraStrategy{
    public:
        FollowerCameraStrategy(Renderable*,GLfloat,GLfloat,GLfloat);
        virtual ~FollowerCameraStrategy();
 
        GLvoid mouseMoved(GLfloat, GLfloat,Camera*);
        GLvoid keyLEFTALTdown(Camera*);
        GLvoid keyLEFTALTup(Camera*);
        GLvoid keyRIGTHCTRdown(Camera*);
        GLvoid keyRIGTHCTRup(Camera*);
        GLvoid keyRIGTHSHIFTdown(Camera*);
        GLvoid keyRIGTHSHIFTup(Camera*);
        GLvoid update(GLfloat,Camera*);
        
    private:
        Renderable* follower;
        GLfloat maxDistanseX,maxDistanseY,maxDistanseZ;
    };
}
#endif	/* FOLLOWERCAMERASTRATEGY_H */

