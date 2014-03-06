/* 
 * File:   Model2D.h
 * Author: fran
 *
 * Created on December 11, 2013, 8:02 AM
 */

#ifndef MODEL2D_H
#define	MODEL2D_H

#include "../Unnivelmas_conf.h"
#include <Renderer/Renderable.h>

namespace kaikai
{
    class Material;
    class Scene;
    
    class Model2D : public Renderable
    {
        public:
            Model2D();
            virtual ~Model2D();

            void draw(Scene*);
            void setMaterial(Material*);
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

#endif	/* MODEL2D_H */

