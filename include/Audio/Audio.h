/* 
 * File:   Audio.h
 * Author: fran
 *
 * Created on January 22, 2014, 9:03 PM
 */

#ifndef AUDIO_H
#define	AUDIO_H

#include "../Unnivelmas_conf.h"
#include <string>

namespace unnivelmas
{
    class Audio {
    public:
        Audio(const GLchar*);
        virtual ~Audio();
        
        const GLchar* getName();
        virtual GLvoid play()=0;
        virtual GLvoid stop()=0;
    private:
        std::string name;
    };
}
#endif	/* AUDIO_H */

