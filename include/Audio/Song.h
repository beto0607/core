/* 
 * File:   Song.h
 * Author: fran
 *
 * Created on January 22, 2014, 9:03 PM
 */

#ifndef SONG_H
#define	SONG_H

#include <Audio/Audio.h>
#include "../Unnivelmas_conf.h"

namespace unnivelmas
{
    class Song : public Audio{
    public:
        Song(const GLchar*,const GLchar*);
        virtual ~Song();
 
        GLvoid stop();
        GLvoid play();
        
    private:
        Mix_Music* music;
    };
}
#endif	/* SONG_H */

