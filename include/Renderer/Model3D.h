/* 
 * File:   Model3D.h
 * Author: francisco
 *
 * Created on 3 de marzo de 2014, 14:13
 */

#ifndef MODEL3D_H
#define	MODEL3D_H

#include "../Unnivelmas_conf.h"
#include <Renderer/Renderable.h>

namespace kaikai
{
    class Material;
    class Scene;
    
    class Model3D : public Renderable{
    public:
        Model3D();
        virtual ~Model3D();
        
        virtual GLvoid draw(Scene*)=0;
        GLvoid setMaterial(Material*);
        GLfloat flipX();
        GLfloat flipY();
        
        GLvoid setOrtho();
        GLvoid setOrtho(GLfloat,GLfloat,GLfloat,GLfloat,GLfloat,GLfloat);
        GLvoid setPerspective();
        GLvoid setPerspective(GLfloat,GLfloat,GLfloat,GLfloat,GLfloat);
    protected:
        Material* material;
    };
}
#endif	/* MODEL3D_H */

