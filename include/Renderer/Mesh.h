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
    class Mesh : public Model3D{
    public:
        Mesh(const GLchar*, GLfloat*, GLfloat*, GLfloat*, GLint*);
        virtual ~Mesh();
    private:

    };
}
#endif	/* MESH_H */

