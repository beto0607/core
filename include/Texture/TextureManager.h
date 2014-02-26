/* 
 * File:   TextureManager.h
 * Author: fran
 *
 * Created on December 25, 2013, 10:01 PM
 */

#ifndef TEXTUREMANAGER_H
#define	TEXTUREMANAGER_H

#include "../Unnivelmas_conf.h"
#include <map> 
#include <string>

namespace kaikai{
    
    class Texture;
    class Material;
    class Shader;
    
    class TextureManager {
    public:
        TextureManager();
        virtual ~TextureManager();
        
        GLvoid loadTexture(const GLchar*,const GLchar*);
        GLvoid loadNullTexture();
        Texture* getTexture(const GLchar*);
        
        Material* getNullMaterial();
        GLvoid setNullMaterial(Material*);
    private:
        Material* material_null;
        Shader* shader_null;
        std::map<std::string,Texture*>* textures;        
    };
}
#endif	/* TEXTUREMANAGER_H */

