/* 
 * File:   Sound.cpp
 * Author: fran
 * 
 * Created on January 22, 2014, 9:04 PM
 */
#include <Core/Core.h>
#include <Audio/AudioManager.h>
#include <Audio/Audio.h>
#include <Audio/Sound.h>

using namespace unnivelmas;

Sound::Sound(const GLchar* _name,const GLchar* _filepath): Audio(_name) {
    phaserChannel = -1;
    phaser = Mix_LoadWAV(_filepath);
}

Sound::~Sound() {
}

GLvoid Sound::stop()
{
    Mix_HaltChannel(phaserChannel);
}

GLvoid Sound::play()
{
    phaserChannel = Mix_PlayChannel(0, phaser, 0);
}