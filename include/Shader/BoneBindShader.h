/* 
 * File:   BoneBindShader.h
 * Author: francisco
 *
 * Created on 15 de abril de 2014, 18:28
 */

#ifndef BONEBINDSHADER_H
#define	BONEBINDSHADER_H

#include <Shader/Shader.h>

namespace kaikai
{
    class BoneBindShader : public Shader{
    public:
        BoneBindShader();
        virtual ~BoneBindShader();
        
        void setShaderVariables(Renderable*, Material*, Scene*);
        void enableShaderVariables();
        void disableShaderVariables();
    private:
        GLuint index_vertex;
        GLuint inv_pose;
        GLuint weight_bind;

    };
}
#endif	/* BONEBINDSHADER_H */

