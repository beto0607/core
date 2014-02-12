/* 
 * File:   Material.cpp
 * Author: francisco
 * 
 * Created on 29 de diciembre de 2013, 20:50
 */

#include <Scene/Material.h>
#include <Shader/Shader.h>
#include <Renderer/Renderable.h>
#include <list>
#include <iostream>

using namespace unnivelmas;

Material::Material() {
}

Material::~Material() {
}

GLvoid Material::setShader(Shader* _shader)
{
    shader = _shader;
}

Texture* Material::getTexture()
{
    return this->texture;
}

GLvoid Material::setTexture(Texture* _texture)
{
    texture = _texture;
}

GLvoid Material::setVariables(Renderable* _renderable)
{
    shader->setShaderVariables(_renderable, this);
}

GLvoid Material::disableVariables()
{
    shader->disableShader();
}

/*Renderable* Material::getRenderable()
{
    return actual_renderable;
}*/
