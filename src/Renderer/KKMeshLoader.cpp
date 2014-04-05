/* 
 * File:   KKMeshLoader.cpp
 * Author: francisco
 * 
 * Created on 11 de marzo de 2014, 16:54
 */

#include <Renderer/KKMeshLoader.h>
#include <Renderer/Actor.h>
#include <Renderer/Mesh.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace kaikai;

KKMeshLoader::KKMeshLoader() {
    functions.insert(std::pair<std::string,KKMeshLoaderFunction>(std::string("NAME"),&KKMeshLoader::loadName));
    functions.insert(std::pair<std::string,KKMeshLoaderFunction>(std::string("MESHES"),&KKMeshLoader::loadMeshCant));
    functions.insert(std::pair<std::string,KKMeshLoaderFunction>(std::string("JOINTS"),&KKMeshLoader::loadJointCant));
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
        std::cout << "We coudnt find: "<< _filename <<"\n";
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
    Mesh* newmesh = new Mesh();
    std::string name;
    GLint vertex_count, index_count, row_index;
    _file >> name;
    _file >> vertex_count;
    _file >> index_count;
    GLfloat* vertex = new GLfloat[vertex_count*3];
    GLfloat* normal = new GLfloat[vertex_count*3];
    GLfloat* uv_coord = new GLfloat[vertex_count*2];
    GLuint* index = new GLuint[index_count*3];
    for(int i=0;i<vertex_count;i++)
    {
        _file >> row_index;_file >> vertex[0+i*3];_file >> vertex[1+i*3];_file >> vertex[2+i*3];_file >> normal[0+i*3];_file >> normal[1+i*3];_file >> normal[2+i*3];_file >> uv_coord[0+i*2];_file >> uv_coord[1+i*2];
    }
    for(int i=0;i<index_count;i++)
    {
        _file >> row_index;_file >> index[0+i*3];_file >> index[1+i*3];_file >> index[2+i*3];
    }
    newmesh->setName(name);
    newmesh->setVertex(vertex,vertex_count);
    newmesh->setNormal(normal,vertex_count);
    newmesh->setUVCoord(uv_coord,vertex_count);
    newmesh->setIndex(index, index_count);
    delete vertex;
    delete normal;
    delete uv_coord;
    delete index;    
    _actor->addRenderable(newmesh);
}

GLvoid KKMeshLoader::loadJoint(std::ifstream& _file, Actor* _actor)
{
    Joint** aux_joint;
    
    
    
    delete aux_joint;
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
