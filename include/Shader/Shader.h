/* 
 * File:   Shader.h
 * Author: francisco
 *
 * Created on 12 de diciembre de 2013, 19:29
 */

#ifndef SHADER_H
#define	SHADER_H

#include "../Unnivelmas_conf.h"

namespace kaikai{
    
    class Material;
    class Renderable;
    
    class Shader {
    public:
        Shader(const GLchar*,const GLchar*);
        Shader(GLchar**);
        virtual ~Shader();
        
        GLvoid enableShader();
        GLvoid disableShader();
    
        GLint getAttributeLocation(GLuint, const GLchar*);
        GLint getUniformLocation(GLuint, const GLchar*);
        
        virtual GLvoid enableShaderVariables()=0;
        virtual GLvoid setShaderVariables(Renderable*, Material*)=0;
        virtual GLvoid disableShaderVariables()=0;
        
    protected:
        GLenum program_shader_id;
        GLenum vertex_shader_id;
        GLenum fragment_shader_id;        
    };
}
#endif	/* SHADER_H */

