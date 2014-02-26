/* 
 * File:   Clock.h
 * Author: fran
 *
 * Created on December 8, 2013, 4:37 PM
 */

#ifndef CLOCK_H
#define	CLOCK_H

#include "../Unnivelmas_conf.h"
#include <list>

namespace kaikai
{
    class Entity;
    class TimeEventListener;
    class Text;
    class Font;
    
    class Clock {
        public:
            Clock(GLint);
            virtual ~Clock();

            GLvoid endLoop(GLint, GLint);
            GLvoid setFPS(GLint);
            GLvoid showFPS();
            GLvoid addListener(TimeEventListener*);
            GLvoid setFPSTextFont(Font*);
        private:
            std::list<TimeEventListener*> listeners;
            GLfloat frame_time;
            GLint fps, frame_count, final_fps;
            GLfloat frame_tick;
            Text* fps_info;
    };
};// namespace



#endif	/* CLOCK_H */

