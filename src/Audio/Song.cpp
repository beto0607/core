/* 
 * File:   Song.cpp
 * Author: fran
 * 
 * Created on January 22, 2014, 9:03 PM
 */
#include <Core/Core.h>
#include <Audio/Song.h>
#include <Audio/Audio.h>
#include <Log/Logger.h>
#include <iostream>
#include <string>

using namespace unnivelmas;

Song::Song(const GLchar* _name,const GLchar* _filepath): Audio(_name) {
    music = Mix_LoadMUS(_filepath);
    if(music == NULL)
    {
        std::string mesage = ("Music Load Fail");
        mesage.append(Mix_GetError());
        (Logger::getInstance())->warnningLog(mesage.c_str());
    }
    (Core::getInstance())->addAudio(this);
}

Song::~Song() {
    Mix_FreeMusic(music);
}

GLvoid Song::stop()
{
    Mix_HaltMusic();
}

GLvoid Song::play()
{
    Mix_PlayMusic(music, 1);
}
