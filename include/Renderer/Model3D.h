/* 
 * File:   Model3D.h
 * Author: francisco
 *
 * Created on 3 de marzo de 2014, 14:13
 */

#ifndef MODEL3D_H
#define	MODEL3D_H

namespace kaikai
{
    class Model3D : public Renderable{
    public:
        Model3D();
        virtual ~Model3D();
        
        GLvoid draw(Scene*);
        GLvoid setMaterial(Material*);
        GLfloat flipX();
        GLfloat flipY();
    private:
        Material* material;
    };
}
#endif	/* MODEL3D_H */

