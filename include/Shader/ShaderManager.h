/* 
 * File:   ShaderManager.h
 * Author: francisco
 *
 * Created on 12 de diciembre de 2013, 19:28
 */

#ifndef SHADERMANAGER_H
#define	SHADERMANAGER_H

#include <map>
#include <string>

namespace kaikai{
    
    class Shader;
    
    class ShaderManager {
    public:
        ShaderManager();
        virtual ~ShaderManager();
    private:
        std::map<std::string,Shader*> shaders;
    };
}
#endif	/* SHADERMANAGER_H */

