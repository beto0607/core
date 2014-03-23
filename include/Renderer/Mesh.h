/* 
 * File:   Mesh.h
 * Author: francisco
 *
 * Created on 5 de marzo de 2014, 23:46
 */

#ifndef MESH_H
#define	MESH_H

#include <Renderer/Model3D.h>

namespace kaikai
{
    class Scene;
    
    class Mesh : public Model3D{
    public:
        Mesh();
        virtual ~Mesh();
        
        GLvoid draw(Scene*);
        GLvoid setVertex(GLfloat*, GLint);
        GLvoid setNormal(GLfloat*, GLint);
        GLvoid setUVCoord(GLfloat*, GLint);
        GLvoid setIndex(GLuint*, GLint);
    private:
        GLint vertex_cant, index_cant;
        GLuint normal_id, index_id;
    };
}
#endif	/* MESH_H */

