/* 
 * File:   KKMeshLoader.cpp
 * Author: francisco
 * 
 * Created on 11 de marzo de 2014, 16:54
 */

#include <Renderer/KKMeshLoader.h>
#include <Renderer/Actor.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace kaikai;

KKMeshLoader::KKMeshLoader() {
    functions.insert(std::pair<std::string,KKMeshLoaderFunction>(std::string("NAME"),&KKMeshLoader::loadName));
    functions.insert(std::pair<std::string,KKMeshLoaderFunction>(std::string("JOINTS"),&KKMeshLoader::loadMeshCant));
    functions.insert(std::pair<std::string,KKMeshLoaderFunction>(std::string("MESHES"),&KKMeshLoader::loadJointCant));
    functions.insert(std::pair<std::string,KKMeshLoaderFunction>(std::string("MESH"),&KKMeshLoader::loadMesh));
    functions.insert(std::pair<std::string,KKMeshLoaderFunction>(std::string("JOINT"),&KKMeshLoader::loadJoint));
}

KKMeshLoader::~KKMeshLoader() {
}

Actor* KKMeshLoader::loadKKModel(const GLchar* _filename)
{
    Actor* resu = new Actor();
    std::ifstream myfile;
    myfile.open(_filename, std::ios::in);
    if(myfile.is_open())
    {
        std::string word;
        while(myfile >> word)
        {
            if(functions.find(word) != functions.end())
            {
                (this->*functions.find(word)->second)(myfile,resu);
            }
        }
    }
    else
    {
        std::cout << "no abierto\n";
    } 
    return resu;
}

GLvoid KKMeshLoader::loadName(std::ifstream& _file, Actor* _actor)
{
    std::string name;
    _file >> name;
    _actor->setName(name);
}

GLvoid KKMeshLoader::loadMesh(std::ifstream& _file, Actor* _actor)
{
    std::cout << "Malla\n";
}

GLvoid KKMeshLoader::loadJoint(std::ifstream& _file, Actor* _actor)
{
    std::cout << "Pivote\n";
}

GLvoid KKMeshLoader::loadHeader(std::ifstream& _file, Actor* _actor)
{

}        
    
GLvoid KKMeshLoader::loadMeshCant(std::ifstream& _file, Actor* _actor)
{
    GLint mesh_cant;
    _file >> mesh_cant;
    _actor->setMeshCount(mesh_cant);
}

GLvoid KKMeshLoader::loadJointCant(std::ifstream& _file, Actor* _actor)
{
    GLint joint_cant;
    _file >> joint_cant;
    _actor->setJointCount(joint_cant);
}
