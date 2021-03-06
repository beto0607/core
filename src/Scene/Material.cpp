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

using namespace kaikai;

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

GLvoid Material::setVariables(Renderable* _renderable, Scene* _scene)
{
    shader->setShaderVariables(_renderable, this, _scene);
}

GLvoid Material::disableVariables()
{
    
}

/*Renderable* Material::getRenderable()
{
    return actual_renderable;
}*/

std::string Material::getName()
{
    return name;
}

GLvoid Material::setName(std::string _name)
{
    name = _name;
}