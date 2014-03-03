/* 
 * File:   PruebaShader.cpp
 * Author: fran
 * 
 * Created on December 14, 2013, 6:17 PM
 */

#include <Shader/Shader.h>
#include <Shader/ShaderNull.h>
#include <Scene/Scene.h>
#include <Scene/Camera.h>
#include <Renderer/Renderable.h>
#include <Scene/Material.h>
#include <Texture/Texture.h>
#include <iostream>

using namespace kaikai;

GLchar* null_shader_vertex = {
"#version 120\n"
"\n"
"attribute vec3 vertex_position;\n"
"uniform mat4 scale_matrix;\n"
"uniform mat4 rotation_matrix;\n"
"uniform mat4 position_matrix;\n"
"uniform mat4 port_view;\n"
"uniform mat4 projection_matrix;\n"
"\n"
"void main(void)\n"
"{\n"
"    vec4 vertex = vec4(vertex_position, 1.0);\n"
"    vertex *= scale_matrix;\n"
"    vertex *= position_matrix;\n"
"    vertex *= port_view;\n"
"    gl_Position = projection_matrix  * vertex;\n"
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
    vPos = glGetAttribLocation(program_shader_id,"vertex_position");
    sMat = glGetUniformLocation(program_shader_id,"scale_matrix");
    rMat = glGetUniformLocation(program_shader_id,"rotation_matrix");
    pMat = glGetUniformLocation(program_shader_id,"position_matrix");
    proM = glGetUniformLocation(program_shader_id,"projection_matrix");
    viewP = glGetUniformLocation(program_shader_id,"port_view");
    
}

ShaderNull::~ShaderNull() {
}

void ShaderNull::enableShaderVariables()
{
    
}

void ShaderNull::setShaderVariables(Renderable* _renderable, Material* _material, Scene* _scene) {
    this->enableShader();
    glUniformMatrix4fv(sMat,1,GL_FALSE,_renderable->getScale());
    glUniformMatrix4fv(pMat,1,GL_FALSE,_renderable->getPosition());
    glUniformMatrix4fv(proM,1,GL_FALSE,_renderable->getProjectionMatrix());
    glUniformMatrix4fv(viewP,1,GL_FALSE,_scene->getCamera()->getPosition());
    glEnableVertexAttribArray(vPos);
    glBindBuffer(GL_ARRAY_BUFFER,_renderable->getVertexBufferID());
    glVertexAttribPointer(vPos, 3, GL_FLOAT,GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER,_renderable->getUVBufferID());
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

void ShaderNull::disableShaderVariables()
{
    glDisableVertexAttribArray(vPos);
}