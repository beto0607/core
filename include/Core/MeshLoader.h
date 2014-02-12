/* 
 * File:   Mesh.h
 * Author: beto0607
 *
 * Created on 5 de febrero de 2014, 14:56
 */

#ifndef MESHLOADER_H
#define	MESHLOADER_H

#include "../Unnivelmas_conf.h"
#include <fstream>
#include <string>
#include <iostream>
#include <list>

namespace unnivelmas{
    class MeshLoader {
    public:
        MeshLoader(const char * );
        GLdouble * getVertex();
        GLdouble * getCoordenates();
        GLint * getIndex();
        GLint getVertexSize();
        GLint getCoordenatesSize();
        GLint getIndexSize();
        GLvoid loadMesh();
        GLvoid setFile(const char * );
        virtual ~MeshLoader();
        GLvoid printAll();
    private:
        GLvoid loadVertex(std::string);
        GLvoid loadCoordenates(std::string);
        GLvoid loadIndex(std::string);
        std::list<GLdouble> loadFloats(std::string);
        const char * f;
        
        GLdouble * vertex;
        GLdouble * coordenates;
        GLint * index;
        GLint indexsize;
        GLint vertexsize;
        GLint coordenatessize;
    };
}
#endif	/* MESH_H */

