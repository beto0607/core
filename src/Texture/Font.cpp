/* 
 * File:   Font.cpp
 * Author: fran
 * 
 * Created on February 1, 2014, 1:53 PM
 */

#include <Texture/Font.h>
#include <Log/Logger.h>
#include <sstream>


namespace unnivelmas
{
    Font::Font(const GLchar* _file, GLint _size) {
        font_style = TTF_OpenFont(_file, _size);
        if ( font_style == NULL ) {
            std::stringstream mesage;
            mesage << "Couldn't load "<< _file << " font" << SDL_GetError();
            (Logger::getInstance())->criticalLog(mesage.str());
        }
    }

    Font::~Font() {
    }

    TTF_Font* Font::getFont()
    {
        return font_style;
    }
}