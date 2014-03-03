/* 
 * File:   Text.h
 * Author: fran
 *
 * Created on February 1, 2014, 1:35 PM
 */

#ifndef TEXT_H
#define	TEXT_H

#include <Renderer/Rectangle.h>
#include <string>

namespace kaikai
{
    class Font;
    
    class Text : public Rectangle{
    public:
        Text(const GLchar*,Font*);
        Text(const GLchar*);
        virtual ~Text();
        
        GLvoid draw(Scene*);
        GLvoid setText(const GLchar*);
        GLvoid setColor(GLfloat,GLfloat,GLfloat, GLfloat);
        GLvoid setFont(Font*);
    private:
        SDL_Color color;
        std::string text;
        Font* my_font;
        SDL_Surface* surface;
        SDL_Surface* mesage;
        SDL_BlendMode saved_mode;
        GLuint texture_id;
        };
}
#endif	/* TEXT_H */

