/* 
 * File:   Sprite.h
 * Author: fran
 *
 * Created on January 21, 2014, 10:06 PM
 */

#ifndef SPRITE_H
#define	SPRITE_H

#include "../Unnivelmas_conf.h"

namespace unnivelmas
{
    class Renderable;
    
    class Sprite {
    public:
        Sprite(GLfloat, GLfloat,GLint, GLint);
        virtual ~Sprite();
 
        GLvoid setSprite(Renderable*);
    private:
        GLfloat*  uv_coords;
    };
}
#endif	/* SPRITE_H */

