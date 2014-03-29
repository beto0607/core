/* 
 * File:   Actor.h
 * Author: francisco
 *
 * Created on 5 de marzo de 2014, 23:54
 */

#ifndef ACTOR_H
#define	ACTOR_H

#include <Renderer/Model3D.h>
#include <map>
#include <string>

namespace kaikai
{
    class Scene;
    class Joint;
    class Material;
    
    class Actor : public Model3D{
    public:
        Actor();
        virtual ~Actor();
 
        GLvoid draw(Scene*);
        
        GLvoid setMeshCount(GLint);
        GLint getMeshCount();
        
        GLvoid setJointCount(GLint);
        GLint setJointCount();
        
        GLvoid addRenderable(Renderable*);
        
        GLvoid move(GLfloat,GLfloat,GLfloat);
        GLvoid scale(GLfloat);
        GLvoid setMaterial(const GLchar*, Material*);
    private:
        std::map<std::string,Renderable*> meshes;
        Joint* root_joint;
        GLint mesh_cant, joint_cant;
    };
}
#endif	/* ACTOR_H */

