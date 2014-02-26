/* 
 * File:   Sound.h
 * Author: fran
 *
 * Created on January 22, 2014, 9:04 PM
 */

#ifndef SOUND_H
#define	SOUND_H

#include <Audio/Audio.h>
#include "../Unnivelmas_conf.h"

namespace kaikai
{
    class Sound :public Audio{
    public:
        Sound(const GLchar*,const GLchar*);
        virtual ~Sound();
 
        GLvoid stop();
        GLvoid play();
        
    private:
        Mix_Chunk* phaser;
        GLint phaserChannel;
    };
}
#endif	/* SOUND_H */

