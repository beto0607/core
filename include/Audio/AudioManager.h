/* 
 * File:   AudioManager.h
 * Author: fran
 *
 * Created on January 22, 2014, 8:59 PM
 */

#ifndef AUDIOMANAGER_H
#define	AUDIOMANAGER_H

#include "../Unnivelmas_conf.h"
#include <string>
#include <map>

namespace kaikai
{
    class Audio;
    
    class AudioManager {
    public:
        AudioManager();
        virtual ~AudioManager();
        
        GLvoid openAudioDevice();
        GLvoid addAudio(const GLchar*, Audio*);
        GLvoid play(const GLchar*);
    private:
        std::map<std::string, Audio*> audios;
        GLint audio_rate;
        GLuint audio_format;
        GLint audio_channels;
        GLint audio_buffers;
    };
}
#endif	/* AUDIOMANAGER_H */

