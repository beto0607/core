/* 
 * File:   Joint.h
 * Author: francisco
 *
 * Created on 2 de abril de 2014, 14:12
 */

#ifndef JOINT_H
#define	JOINT_H

#include "../Unnivelmas_conf.h"
#include <Renderer/Model3D.h>
#include <string>
#include <list>

namespace kaikai
{
    class DrawStrategy;
    class Skeleton;
    class Scene;
    class Shader;
    
    class Joint : public Model3D{
    public:
        Joint();
        virtual ~Joint();
        
        GLvoid setId(GLint);
        GLvoid setName(std::string);
        GLvoid setParentId(GLint);
        GLvoid setHeader(glm::vec3);
        GLvoid setTail(glm::vec3);
        GLvoid setRotation(glm::quat);
        
        GLint getId();
        std::string getName();
        GLint getParentId();
        glm::vec3 getHeader();
        glm::vec3 getTail();
        glm::quat getRotation();
        
        GLvoid addChild(Joint*);
        GLvoid draw(Scene*);
        GLvoid draw(Scene*,Shader*);
        
        GLvoid setInvertedMatrix(Skeleton*);
        
        GLvoid setSkeleton(Skeleton*);
        Skeleton* getSkeleton();
    private:
        Skeleton* skeleton;
        DrawStrategy* draw_strategy;
        std::string name;
        GLint id;
        GLint parent_id;
        glm::vec3 head;
        glm::vec3 tail;
        glm::quat rotation;
        Joint* faher;
        std::list<Joint*> childs;
    };
}
#endif	/* JOINT_H */

