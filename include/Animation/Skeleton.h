/* 
 * File:   Skeleton.h
 * Author: francisco
 *
 * Created on 2 de abril de 2014, 12:21
 */

#ifndef SKELETON_H
#define	SKELETON_H

#include "../Unnivelmas_conf.h"

namespace kaikai
{
    class Joint;
    
    class Skeleton {
    public:
        Skeleton();
        virtual ~Skeleton();

        GLvoid setJointCant(GLint);
        GLint getJointCount();
        
        GLvoid allocateMemory(GLint);
        
    private:
        GLint joint_cant;
        Joint* joint_root;
        glm::mat4* joint_rotation;
    };
}
#endif	/* SKELETON_H */

