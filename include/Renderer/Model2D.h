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

namespace unnivelmas
{
    class Material;
    
    class Model2D : public Renderable
    {
        public:
            Model2D();
            virtual ~Model2D();

            void draw();
            void setMaterial(Material*);
            GLfloat* getVertexBufferOffset();
            GLfloat flipX();
            GLfloat flipY();
            
        protected:
            GLfloat* vertex;
            GLfloat* texture_coordenates;
            GLint* index;
            Material* material;
    };    
}

#endif	/* MODEL2D_H */

