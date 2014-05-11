/* 
 * File:   JointShader.h
 * Author: francisco
 *
 * Created on 19 de abril de 2014, 17:28
 */

#ifndef JOINTSHADER_H
#define	JOINTSHADER_H

#include <Shader/Shader.h>

namespace kaikai
{
    class JointShader : public Shader{
    public:
        JointShader();
        virtual ~JointShader();
    
        GLvoid setShaderVariables(Renderable*, Material*, Scene*);
        GLvoid enableShaderVariables();
        GLvoid disableShaderVariables();
    private:
        GLuint uniform_color,uniform_inv_bindpose;
    };
}
#endif	/* JOINTSHADER_H */

