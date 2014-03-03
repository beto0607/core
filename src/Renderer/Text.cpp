/* 
 * File:   Text.cpp
 * Author: fran
 * 
 * Created on February 1, 2014, 1:35 PM
 */

#include <Renderer/Text.h>
#include <Renderer/Rectangle.h>
#include <Scene/TextMaterial.h>
#include <Texture/Font.h>
#include <Texture/Texture.h>
#include <iostream>

using namespace kaikai;

Text::Text(const GLchar* _name,Font* _font): Rectangle(_name,1.1,1.1){
    my_font = _font;
    this->material = new TextMaterial();
    glGenTextures(1,&texture_id);
    this->material->getTexture()->setTexture(texture_id);
    this->setText(" ");
}

Text::Text(const GLchar* _name): Rectangle(_name,1.1,1.1)
{
    this->material = new TextMaterial();
    glGenTextures(1,&texture_id);
    this->material->getTexture()->setTexture(texture_id);
}

Text::~Text() {
}

GLvoid Text::setText(const GLchar* _text)
{
    mesage = TTF_RenderUTF8_Blended(my_font->getFont(), _text, color);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    scale_matrix[0][0] = mesage->w;
    scale_matrix[1][1] = mesage->h;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mesage->w, mesage->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, mesage->pixels);
    glBindTexture(GL_TEXTURE_2D, 0);
    }

GLvoid Text::setColor(GLfloat _red,GLfloat _green,GLfloat _blue, GLfloat _alpha)
{
    color.r = _red;
    color.g = _green;
    color.b = _blue;
    color.a = _alpha;
}

GLvoid Text::setFont(Font* _font)
{
    my_font = _font;
}

GLvoid Text::draw(Scene* _scene)
{
    glPushAttrib(GL_ENABLE_BIT);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    Model2D::draw(_scene);
    glDisable(GL_BLEND);
}