/* 
 * File:   Track.cpp
 * Author: fran
 * 
 * Created on January 21, 2014, 10:16 PM
 */

#include <Animation/Track.h>
#include <Animation/Animation.h>
#include <Animation/SpriteAnimation.h>
#include <Animation/Sprite.h>
#include <iostream>
#include <Animation/TrackState.h>
#include <Animation/TrackStateChanged.h>

using namespace unnivelmas;

Uint32 my_callbackfunc(Uint32 interval, void *param)
{
    ((Track*)param)->incrementTick();
    ((Track*)param)->getState()->changeState((Track*)param);
    return(interval);
}

Track::Track(const GLchar* name, GLint delay) {
    state = new TrackStateChanged();
    this->name = std::string(name);
    id = SDL_AddTimer(delay, my_callbackfunc, this);
}

Track::~Track() {
}

GLvoid Track::next(Renderable* _renderable, Animation* _animation)
{
    state->updateTrack(this,_renderable,_animation);
}

GLvoid Track::addTrack(GLint _new_track)
{
    tracks.push_back(_new_track);
    actual_track = tracks.begin();
}

std::string Track::getName()
{
    return name;
}

GLvoid Track::incrementTick()
{
    ++actual_track;
    if(actual_track == tracks.end())
        actual_track = tracks.begin();
}

GLint Track::getActualTrack()
{
    return *actual_track;
}

GLvoid Track::setState(TrackState* _state)
{
    state = _state;
}

TrackState* Track::getState()
{
    return state;
}