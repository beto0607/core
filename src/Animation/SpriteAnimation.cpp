/* 
 * File:   SpriteAnimation.cpp
 * Author: francisco
 * 
 * Created on 20 de enero de 2014, 18:56
 */

#include <Animation/Animation.h>
#include <Animation/SpriteAnimation.h>
#include <Animation/Sprite.h>
#include <Animation/Track.h>
#include <Log/Logger.h>
#include <string>
#include <sstream>

using namespace kaikai;

SpriteAnimation::SpriteAnimation(GLint _image_heigth,GLint _image_width, GLint _column, GLint _row) {
    GLint total_animations = 0;
    GLfloat dx = (float)(_image_heigth/_column)/(float)_image_width;
    GLfloat dy = (float)(_image_heigth/_row)/(float)_image_heigth;
    
    for (GLint i=0;i<_row;i++)
        for (GLint j=0;j<_column;j++)
        {
            sprites.insert(std::pair<GLint, Sprite*>(total_animations, new Sprite(dx,dy,i,j)));
            total_animations++;
        }
    Track* track = new Track("default",1000);
    track->addTrack(1);
    this->addTrack(track);
}

SpriteAnimation::~SpriteAnimation() {
}

GLvoid SpriteAnimation::play(const GLchar* _track_name)
{
    std::map<std::string,Track*>::iterator it = tracks.find(std::string(_track_name));
    if(it != tracks.end())
        active_track = it->second;
    else
        std::cout << _track_name << " doesnt exist\n";
}

GLvoid SpriteAnimation::next(Renderable* _renderable)
{
    active_track->next(_renderable,this);
}

GLvoid SpriteAnimation::addTrack(Track* _track)
{
    active_track = _track;
    tracks.insert(std::pair<std::string,Track*>(_track->getName(),_track));
}

Sprite* SpriteAnimation::getSprite(GLint index)
{
    std::map<GLint,Sprite*>::iterator it = sprites.find(index);
    Sprite* sprite;
    if(it == sprites.end())
    {
        sprite = sprites.begin()->second;
        std::string message = std::string("Error while extract animation from ");
        message.append(active_track->getName());
        message.append(" ");
        std::stringstream number;
        number << index;
        message.append(number.str());
        message.append(" doesnt exist");
        (Logger::getInstance())->criticalLog(message.c_str());
    }
    else
    {
        sprite = it->second;
    }
    return sprite;
}