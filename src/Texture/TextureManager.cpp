/* 
 * File:   TextureManager.cpp
 * Author: fran
 * 
 * Created on December 25, 2013, 10:01 PM
 */

#include <Texture/TextureManager.h>
#include <Texture/Texture.h>
#include <Scene/MaterialNull.h>
#include <Log/Logger.h>
#include <iostream>
#include <sstream>

using namespace unnivelmas;

TextureManager::TextureManager() {
    GLint initted=IMG_Init(~0);
    textures = new std::map<std::string,Texture*>();
    this->loadNullTexture();
}

TextureManager::~TextureManager() {
}

GLvoid TextureManager::loadTexture(const GLchar* name,const GLchar* file_path)
{
    SDL_Surface* image;
    GLuint gl_texID;
    
    glGenTextures(1,&gl_texID);
    glBindTexture(GL_TEXTURE_2D, gl_texID);
    Texture* auxtexture = new Texture(name, gl_texID);
    
    image=IMG_Load(file_path);
    if(!image)
    {
            std::stringstream mesage;
            mesage << "Texture: " << name << " File: " << file_path << " " << IMG_GetError();
            (Logger::getInstance())->warnningLog(mesage.str().c_str());
            textures->insert(std::pair<std::string,Texture*>(std::string(name), this->getTexture("null_texture")));
    }
    else
    {    
        int Mode = GL_RGB;
        if(image->format->BytesPerPixel == 4) {
            Mode = GL_RGBA;
        }
        glTexImage2D(GL_TEXTURE_2D,0 , Mode, image->w, image->h, 0, Mode, GL_UNSIGNED_BYTE, image->pixels);
        glGenerateMipmap(GL_TEXTURE_2D);

        textures->insert(std::pair<std::string,Texture*>(std::string(name), auxtexture));
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        std::stringstream mesage;
        mesage << "Texture: " << name << " FILE: " << file_path << " ID: " << gl_texID << " was loaded susefull";
        (Logger::getInstance())->infoLog(mesage.str().c_str());
        SDL_FreeSurface(image);
    }
}

GLvoid TextureManager::loadNullTexture()
{
    GLbyte null_texture[16] = {0,255,0,150,0,255,0,150,0,255,0,150,0,255,0,150}; 
    GLuint gl_texID;
        
    glGenTextures(1,&gl_texID);
    glBindTexture(GL_TEXTURE_2D, gl_texID);
    Texture* auxtexture = new Texture("null_texture", gl_texID);
    
    glTexImage2D(GL_TEXTURE_2D,0 , GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, null_texture);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    textures->insert(std::pair<std::string,Texture*>(std::string("null_texture"), auxtexture));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    std::stringstream mesage;
    mesage << "Texture: null_texture FILE:  ID: " << gl_texID << " was loaded susefull";
    (Logger::getInstance())->infoLog(mesage.str().c_str());
        
    
}

Texture* TextureManager::getTexture(const GLchar* name)
{
    Texture* resu = (textures->find(std::string(name)))->second;
    if(resu == NULL)
        std::cout << "CRITICAL: " << name <<" was not found \n";
    return resu;
}

Material* TextureManager::getNullMaterial()
{
    return material_null;
}

GLvoid TextureManager::setNullMaterial(Material* _material)
{
    material_null = _material;
}