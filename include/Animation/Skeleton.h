/* 
 * File:   Skeleton.h
 * Author: francisco
 *
 * Created on 2 de abril de 2014, 12:21
 */

#ifndef SKELETON_H
#define	SKELETON_H

#include "../Unnivelmas_conf.h"
#include <Core/TimeEventListener.h>
#include <map>

namespace kaikai
{
    class Joint; 
    class JointShader;  
    class Scene;
    /**
     * @author: Francisco Blanco
     * @description: Skeleton is a Joints group that has all movements animation data with an Actor
     */
    class Skeleton : public TimeEventListener{
    public:
        Skeleton();
        virtual ~Skeleton();

        GLvoid setJointCant(GLint _cant); //!< this function sets a joint_cant variable with _cant value.
        GLint getJointCount(); //!< this function returns joint_cant value.
        
        GLvoid allocateMemory(GLint); //!< allocates memory in joint_rotation and joint_inverted_matrix.
        GLfloat* getInvertedPoseMatrixArray(); //!< returns joint_rotation pointer, it's used to pass Inverted Bind Pose to Shaders.
        
        GLvoid setJoint(Joint*);
        GLvoid draw(Scene*);
        
        GLvoid setX(GLfloat);
        GLvoid setY(GLfloat);
        GLvoid setZ(GLfloat);
        
        GLvoid setAngleX(GLfloat);
        GLvoid setAngleY(GLfloat);
        GLvoid setAngleZ(GLfloat);
        
        GLvoid update(GLfloat _tick);
        
        glm::mat4* getInvertedMatrixById(GLint);
    private:
        GLint joint_cant; /** \brief number of joints */
        std::map<GLint,Joint*> joint_collection;
        Joint* joint_root;
        glm::mat4* joint_rotation;
        glm::mat4* joint_inverted_matrix;
        JointShader* shader;
    };
}
#endif	/* SKELETON_H */

