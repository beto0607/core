/* 
 * File:   KKMeshLoader.h
 * Author: francisco
 *
 * Created on 11 de marzo de 2014, 16:54
 */

#ifndef KKMESHLOADER_H
#define	KKMESHLOADER_H

#include "../Unnivelmas_conf.h"
#include <iostream>
#include <fstream>
#include <map>

namespace kaikai
{
    class Actor;
    class KKMeshLoader;
    typedef GLvoid (KKMeshLoader::*KKMeshLoaderFunction)(std::ifstream&,Actor*);
    
    class KKMeshLoader {
    public:
        KKMeshLoader();
        virtual ~KKMeshLoader();
        
        Actor* loadKKModel(const GLchar*);
    private:
        std::map<std::string,KKMeshLoaderFunction> functions;
        
        GLvoid loadName(std::ifstream&,Actor*);
        GLvoid loadMesh(std::ifstream&,Actor*);
        GLvoid loadJoint(std::ifstream&,Actor*);
        GLvoid loadMeshCant(std::ifstream&,Actor*);
        GLvoid loadJointCant(std::ifstream&,Actor*);
        GLvoid loadHeader(std::ifstream&,Actor*);        
    };
}
#endif	/* KKMESHLOADER_H */

