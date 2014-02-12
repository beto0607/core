/* 
 * File:   TrackStateChanged.cpp
 * Author: francisco
 * 
 * Created on 22 de enero de 2014, 18:10
 */

#include <Animation/TrackStateChanged.h>
#include <Animation/TrackState.h>
#include <Animation/Track.h>
#include <Animation/SpriteAnimation.h>
#include <Animation/Sprite.h>
#include <iostream>

using namespace unnivelmas;

TrackStateChanged::TrackStateChanged():TrackState(){
}

TrackStateChanged::~TrackStateChanged() {
}

GLvoid TrackStateChanged::changeState(Track* _track)
{
    
}

GLvoid TrackStateChanged::updateTrack(Track* _track ,Renderable* _renderable,Animation* _animation)
{
    (_animation->getSprite(_track->getActualTrack()))->setSprite(_renderable);
    _track->setState(new TrackState());
}
