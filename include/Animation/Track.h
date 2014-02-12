/* 
 * File:   Track.h
 * Author: fran
 *
 * Created on January 21, 2014, 10:16 PM
 */

#ifndef TRACK_H
#define	TRACK_H

#include "../Unnivelmas_conf.h"
#include <list>
#include <string>

namespace unnivelmas
{
    class Renderable;
    class Animation;
    class TrackState;
    
    class Track {
    public:
        Track(const GLchar*,GLint);
        virtual ~Track();
    
        GLvoid addTrack(GLint);
        GLint getActualTrack();
        GLvoid next(Renderable*, Animation*);
        GLvoid incrementTick();
        std::string getName();
        GLvoid setState(TrackState*);
        TrackState* getState();
    private:
        TrackState* state;
        SDL_TimerID id;
        std::list<GLint>::iterator actual_track;
        std::string name;
        std::list<GLint> tracks;
    };
}
#endif	/* TRACK_H */

