/* 
 * File:   AnimationState.cpp
 * Author: francisco
 * 
 * Created on 22 de enero de 2014, 18:06
 */

#include <Animation/TrackState.h>
#include <Animation/Track.h>
#include <Animation/TrackStateChanged.h>
#include <Unnivelmas_conf.h>

using namespace unnivelmas;

TrackState::TrackState() {
}

TrackState::~TrackState() {
}

GLvoid TrackState::changeState(Track* _track)
{
    _track->setState(new TrackStateChanged());
}

GLvoid TrackState::updateTrack(Track* _track ,Renderable* _renderable,Animation* _animation)
{

}
