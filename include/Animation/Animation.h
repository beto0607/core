/* 
 * File:   Animation.h
 * Author: francisco
 *
 * Created on 20 de enero de 2014, 18:55
 */

#ifndef ANIMATION_H
#define	ANIMATION_H

#include <Animation/Animation.h>
#include <map>
#include <string>
#include "../Unnivelmas_conf.h"

namespace unnivelmas
{
    class Renderable;
    class Sprite;
    
    class Animation {
    public:
        Animation();
        virtual ~Animation();
 
        virtual GLvoid play(const GLchar*);
        virtual GLvoid next(Renderable*);
        virtual Sprite* getSprite(GLint);
    private:
    };
}
#endif	/* ANIMATION_H */

