/* 
 * File:   Material.h
 * Author: francisco
 *
 * Created on 29 de diciembre de 2013, 20:50
 */

#ifndef MATERIAL_H
#define	MATERIAL_H

#include "../Unnivelmas_conf.h"
#include <list>
#include <string>

namespace kaikai{
    
    class Scene;
    class Shader;
    class Texture;
    class Renderable;
    
    class Material {
    public:
        Material();
        virtual ~Material();
        
        GLvoid setVariables(Renderable*, Scene*);
        GLvoid disableVariables();
        
        Texture* getTexture();
        GLvoid setTexture(Texture*);
        
        std::string getName();
        GLvoid setName(std::string);
        
        GLvoid setShader(Shader*);
        
        //Renderable* getRenderable();
        
    protected:
        std::string name;
        std::list<Renderable*> renderables;
        Shader* shader;
        Texture* texture;
        //Renderable* actual_renderable;
    };
}
#endif	/* MATERIAL_H */

