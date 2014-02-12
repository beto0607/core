/* 
 * File:   Font.h
 * Author: fran
 *
 * Created on February 1, 2014, 1:53 PM
 */

#ifndef FONT_H
#define	FONT_H

#include "../Unnivelmas_conf.h"

namespace unnivelmas
{
    class Font {
    public:
        Font(const GLchar*,GLint);
        virtual ~Font();
        
        TTF_Font* getFont();
    private:
        TTF_Font* font_style;
    };
}
#endif	/* FONT_H */

