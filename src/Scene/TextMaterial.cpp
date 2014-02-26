/* 
 * File:   newClass.cpp
 * Author: fran
 * 
 * Created on February 1, 2014, 4:36 PM
 */

#include <Scene/TextMaterial.h>
#include <Shader/TextShader.h>
#include <Scene/Material.h>
#include <Texture/Texture.h>

using namespace kaikai;

TextMaterial::TextMaterial() : Material(){
    this->texture = new Texture("text",0);
    this->shader  = new TextShader();
}

TextMaterial::~TextMaterial() {
}

