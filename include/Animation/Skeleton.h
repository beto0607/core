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
    class Skeleton {
    public:
        Skeleton();
        virtual ~Skeleton();

        GLvoid setJointCant(GLint);
        GLint getJointCount();
        
    private:
        GLint joint_cant;
        GLfloat* vertex_color;
        GLint* vertex_index;
        GLuint vertex_color_id, vertex_index_id;
        };
}
#endif	/* SKELETON_H */

