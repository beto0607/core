/* 
 * File:   Texture.h
 * Author: fran
 *
 * Created on December 25, 2013, 10:03 PM
 */

#ifndef TEXTURE_H
#define	TEXTURE_H

#include "../Unnivelmas_conf.h"
#include <string>

namespace unnivelmas
{
    class Texture {
    public:
        Texture(const GLchar*, GLuint);
        virtual ~Texture();
        
        GLuint getTexture();
        GLvoid setTexture(GLuint);
        
    private:
        GLuint id;
        std::string name;
        };
}
#endif	/* TEXTURE_H */

