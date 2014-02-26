/* 
 * File:   AudioManager.cpp
 * Author: fran
 * 
 * Created on January 22, 2014, 8:59 PM
 */

#include <Audio/AudioManager.h>
#include <Audio/Audio.h>
#include <Log/Logger.h>

using namespace kaikai;

AudioManager::AudioManager() {
    if(Mix_Init(MIX_INIT_OGG) != MIX_INIT_OGG)
    {
        std::string mesage = std::string("AudioManager has a problem: ");
        mesage.append(Mix_GetError());
        (Logger::getInstance())->criticalLog(mesage.c_str());
    }
    Mix_VolumeMusic(128);
    (Logger::getInstance())->infoLog("AudioManager was load Susefully");
}

AudioManager::~AudioManager() {
    (Logger::getInstance())->infoLog("AudioManager was destroyed");
}

GLvoid AudioManager::addAudio(const GLchar* _name, Audio* _audio)
{
    audios.insert(std::pair<std::string,Audio*>(std::string(_name), _audio));
}

GLvoid AudioManager::play(const GLchar* _name)
{
    std::map<std::string, Audio*>::iterator it = audios.find(_name);
    if(it != audios.end())
        it->second->play();
    else
    {
        std::string mesage = std::string(_name);
        mesage.append(" doesnt exist");
        (Logger::getInstance())->warnningLog(mesage.c_str());
    }
}

GLvoid AudioManager::openAudioDevice()
{
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) 
    {
        std::string mesage = std::string("Unable to open audio device: ");
        mesage.append(Mix_GetError());
        (Logger::getInstance())->criticalLog(mesage.c_str());
    }
}