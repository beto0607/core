/* 
 * File:   TrackStateChanged.h
 * Author: francisco
 *
 * Created on 22 de enero de 2014, 18:10
 */

#ifndef TRACKSTATECHANGED_H
#define	TRACKSTATECHANGED_H

#include <Animation/TrackState.h>
#include "../Unnivelmas_conf.h"

namespace kaikai
{
    class Renderable;
    class Animation;
    class Track;
    
    class TrackStateChanged : public TrackState{
    public:
        TrackStateChanged();
        virtual ~TrackStateChanged();
        
        GLvoid changeState(Track*);
        GLvoid updateTrack(Track*,Renderable*,Animation*);
    private:

    };
}
#endif	/* TRACKSTATECHANGED_H */

