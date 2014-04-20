/* 
 * File:   BindVertexShader.h
 * Author: francisco
 *
 * Created on 13 de abril de 2014, 18:26
 */

#ifndef BINDVERTEXSHADER_H
#define	BINDVERTEXSHADER_H

#include "../Unnivelmas_conf.h"
#include <Shader/Shader.h>

namespace kaikai
{
    class BindVertexShader : public Shader{
    public:
        BindVertexShader();
        virtual ~BindVertexShader();

        void setShaderVariables(Renderable*, Material*, Scene*);
        void enableShaderVariables();
        void disableShaderVariables();
    private:
        GLuint index_vertex;
        GLuint color_bind;
        GLuint weight_bind;
    };
}
#endif	/* BINDVERTEXSHADER_H */

