/* 
 * File:   AnimationState.h
 * Author: francisco
 *
 * Created on 22 de enero de 2014, 18:06
 */

#ifndef ANIMATIONSTATE_H
#define	ANIMATIONSTATE_H

#include "../Unnivelmas_conf.h"

namespace unnivelmas
{
    class Renderable;
    class Animation;
    class Track;
    
    class TrackState {
    public:
        TrackState();
        virtual ~TrackState();

        GLvoid changeState(Track*);
        virtual GLvoid updateTrack(Track*,Renderable*,Animation*);
    private:

    };
}
#endif	/* ANIMATIONSTATE_H */

