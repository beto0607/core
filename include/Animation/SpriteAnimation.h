/* 
 * File:   SpriteAnimation.h
 * Author: francisco
 *
 * Created on 20 de enero de 2014, 18:56
 */

#ifndef SPRITEANIMATION_H
#define	SPRITEANIMATION_H

#include <Animation/Animation.h>
#include <map>
#include <string>

namespace kaikai
{
    class Track;
    class Sprite;
    class Renderable;
    
    class SpriteAnimation : public Animation{
    public:
        SpriteAnimation(GLint, GLint, GLint, GLint);
        virtual ~SpriteAnimation();
        
        GLvoid addTrack(Track*);
        GLvoid play(const GLchar*);
        GLvoid next(Renderable*);
        Sprite* getSprite(GLint);
    private:
        Track* active_track;
        std::map<std::string, Track*> tracks;
        std::map<GLint, Sprite*> sprites;
    };
}
#endif	/* SPRITEANIMATION_H */

