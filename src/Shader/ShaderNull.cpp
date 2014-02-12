/* 
 * File:   PruebaShader.cpp
 * Author: fran
 * 
 * Created on December 14, 2013, 6:17 PM
 */

#include <Shader/Shader.h>
#include <Shader/ShaderNull.h>
#include <Renderer/Renderable.h>
#include <Scene/Material.h>
#include <Texture/Texture.h>
#include <iostream>

using namespace unnivelmas;

GLchar* null_shader_vertex = {
"#version 120\n"
"\n"
"attribute vec3 vertex_position;\n"
"uniform mat3 scale_matrix;\n"
"uniform mat3 position_matrix;\n"
"uniform mat4 projection_matrix;\n"
"\n"
"void main(void)\n"
"{\n"
"    vec3 vertex = vertex_position;\n"
"    vertex *= scale_matrix;\n"
"    vertex[0] += position_matrix[0][2];\n"
"    vertex[1] += position_matrix[1][2];\n"
"    gl_Position = projection_matrix  * vec4(vertex, 1.0);\n"
"}\n"
};

GLchar* null_shader_fragment = {
"#version 120\n"
"\n"
"void main(void)\n"
"{\n"
"      gl_FragColor = vec4(0.0,1.0,0.0,1.0);\n"
"}\n" 
};
GLchar* null_shader_vector[2] = {null_shader_vertex,null_shader_fragment};

ShaderNull::ShaderNull():Shader(null_shader_vector) {
    vPos = getAttributeLocation(program_shader_id,"vertex_position");
    sMat = getUniformLocation(program_shader_id,"scale_matrix");
    pMat = getUniformLocation(program_shader_id,"position_matrix");
    proM = getUniformLocation(program_shader_id,"projection_matrix");
}

ShaderNull::~ShaderNull() {
}

void ShaderNull::enableShaderVariables()
{
    
}

void ShaderNull::setShaderVariables(Renderable* _renderable, Material* _material) {
    this->enableShader();
    glUniformMatrix3fv(sMat,1,GL_FALSE,_renderable->getScale());
    glUniformMatrix3fv(pMat,1,GL_FALSE,_renderable->getPosition());
    glUniformMatrix4fv(proM,1,GL_FALSE,_renderable->getProjectionMatrix());
    glEnableVertexAttribArray(vPos);
    glBindBuffer(GL_ARRAY_BUFFER,_renderable->getVertexBufferID());
    glVertexAttribPointer(vPos, 3, GL_FLOAT,GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER,_renderable->getUVBufferID());
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindTexture(GL_TEXTURE_2D,_material->getTexture()->getTexture());
}

void ShaderNull::disableShaderVariables()
{
    glDisableVertexAttribArray(vPos);
}