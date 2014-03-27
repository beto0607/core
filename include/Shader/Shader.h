/* 
 * File:   Shader.h
 * Author: francisco
 *
 * Created on 12 de diciembre de 2013, 19:29
 */

#ifndef SHADER_H
#define	SHADER_H

#include "../Unnivelmas_conf.h"
#include <string>

namespace kaikai{
    
    class Material;
    class Renderable;
    class Scene;
    
    class Shader {
    public:
        Shader(const GLchar*,const GLchar*,const GLchar*);
        Shader(const GLchar*,const GLchar**);
        virtual ~Shader();
            
        GLint getAttributeLocation(GLuint, const GLchar*);
        GLint getUniformLocation(GLuint, const GLchar*);
        
        virtual GLvoid enableShaderVariables();
        virtual GLvoid setShaderVariables(Renderable*, Material*, Scene*);
        virtual GLvoid disableShaderVariables();
        
    protected:
        std::string name;
        GLenum program_shader_id;
        GLenum vertex_shader_id;
        GLenum fragment_shader_id;    
        GLuint attribute_vertex, attribute_coordinate_vertex;
        GLuint uniform_scale_matrix, uniform_rotation_matrix, uniform_position_matrix;
        GLint proM;
        GLint viewP;
    };
}
#endif	/* SHADER_H */

