/* 
 * File:   Mesh.cpp
 * Author: beto0607
 * 
 * Created on 5 de febrero de 2014, 14:56
 * Al archivo que lees, cada linea tiene que terminar en un espacio en blanco
 */

#include <Core/MeshLoader.h>
#include <iostream>
#include <fstream>
#include <string> 
#include <stdlib.h>
#include <list>

using namespace unnivelmas;
using namespace std;
MeshLoader::MeshLoader(const char * file) {
    f = file;
    loadMesh();
}

GLvoid MeshLoader::setFile(const char * file){ f = file;}

GLvoid MeshLoader::loadMesh(){
    ifstream archivo(f);
    string line;
    if(archivo.is_open()){
        getline(archivo, line);
        loadVertex(line);
        getline(archivo, line);
        loadCoordenates(line);
        getline(archivo, line);
        loadIndex(line);
    }
}

GLvoid MeshLoader::loadVertex(string line){
    std::list<GLdouble> vertices = loadFloats(line);
    int x = 0;
    this->vertex = new GLdouble[(vertices.size())];
    this->vertexsize = vertices.size();
    for (std::list<GLdouble>::iterator it=vertices.begin(); it != vertices.end(); ++it){
        this->vertex[x] = (*it);
        x++;
    }
}

GLvoid MeshLoader::loadCoordenates(std::string line){
    std::list<GLdouble> vertices = loadFloats(line);
    int x = 0;
    this->coordenates = new GLdouble[vertices.size()];
    this->coordenatessize = vertices.size();
    for (std::list<GLdouble>::iterator it=vertices.begin(); it != vertices.end(); ++it){
        this->coordenates[x] = (*it);
        x++;
    }
}

std::list<GLdouble> MeshLoader::loadFloats(std::string line){
    std::list<GLdouble> list;
    char * pEnd;
    list.push_back(strtod(line.c_str(), &pEnd));
    int x = 0;
    while(x< 1000 and pEnd[1]!=*"*"){
        x++;
        list.push_back(strtod(pEnd, &pEnd));
    } 

    return list;
}

GLvoid MeshLoader::loadIndex(std::string line){
    std::list<GLint> list;
    std::cout << "index\n";
    char * pEnd;
    list.push_back(strtol(line.c_str(), &pEnd, 10));
    int x = 0;
    while(x<1000 and pEnd[1]!=*"*"){
        x++;
        list.push_back(strtol(pEnd, &pEnd, 10));
    }    
    x= 0;
    std::cout << list.size()<< " - \n";
    this->index = new GLint[list.size()];
    this->indexsize = list.size();
    for (std::list<GLint>::iterator it=list.begin(); it != list.end(); it++){
        this->index[x] = (*it);
        x++;
    }
    
}

GLdouble * MeshLoader::getVertex(){return vertex;}

GLdouble * MeshLoader::getCoordenates(){return coordenates;}

GLint * MeshLoader::getIndex(){return index;}

GLint MeshLoader::getCoordenatesSize(){return this->coordenatessize;}

GLint MeshLoader::getVertexSize(){return this->vertexsize;}

GLint MeshLoader::getIndexSize(){return this->indexsize;}

GLvoid MeshLoader::printAll(){
    std::cout << "Numeros: ";
    std::cout << "Vertices: \n";
    for(int i = 0; i < getVertexSize(); i++){
        std::cout << " - "<< vertex[i]<<".\n";
    }
    std::cout << "Coodenates: \n";
    for(int i = 0; i < getCoordenatesSize(); i++){
        std::cout << " - "<< coordenates[i]<<".\n";
    }
    std::cout <<" Indices: \n";
    for(int i = 0; i < getIndexSize(); i++){
        std::cout << " - "<< index[i]<<".\n";
    }

}

MeshLoader::~MeshLoader() {}

