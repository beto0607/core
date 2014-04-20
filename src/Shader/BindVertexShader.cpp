/* 
 * File:   BindVertexShader.cpp
 * Author: francisco
 * 
 * Created on 13 de abril de 2014, 18:26
 */

#include <Shader/BindVertexShader.h>
#include <Renderer/Renderable.h>

using namespace kaikai;

GLfloat bind_vertex_color[3 * 50] = 
{ 1.0,0.0,0.0 , 0.0,1.0,0.0 , 0.0,0.0,1.0 , 1.0,1.0,0.0 , 1.0,0.0,1.0 , 0.0,1.0,1.0 , 0.8,0.0,0.0 , 0.0,0.8,0.0 , 0.0,0.0,0.8 , 0.8,0.8,0.0 ,
  0.8,0.0,0.8 , 0.0,0.8,0.8 , 0.6,0.0,0.0 , 0.0,0.6,0.0 , 0.0,0.0,0.6 , 0.6,0.6,0.0 , 0.6,0.0,0.6 , 0.0,0.6,0.6 , 0.4,0.0,0.0 , 0.0,0.4,0.0 ,
  0.0,0.0,0.4 , 0.4,0.4,0.0 , 0.0,0.4,0.4 , 0.2,0.0,0.0 , 0.0,0.2,0.0 , 0.0,0.0,0.2 , 0.2,0.0,0.2 , 0.2,0.2,0.0 , 0.0,0.2,0.2 , 0.1,0.2,0.2 ,
  0.2,1.0,0.2 , 0.2,0.2,1.0 , 0.1,0.5,0.1 , 0.6,0.6,0.2 , 0.2,0.6,0.6 , 0.6,0.2,0.6 , 0.8,0.4,0.2 , 0.2,0.4,0.8 , 0.4,0.6,0.1 , 1.0,4.0,1.0 ,
  0.0,0.0,0.0 , 0.1,0.8,0.5 , 0.2,0.0,0.6 , 0.4,0.4,0.4 , 0.7,0.4,0.5 , 0.4,0.3,0.7 , 0.4,0.6,0.7 , 0.7,0.6,8.0 , 1.0,1.0,1.0 , 1.0,1.0,1.0
};

const GLchar* bind_vertex_shader_vertex = {
"#version 120\n"
"\n"
"attribute vec3 vertex_position;\n"
"attribute vec2 vertex_uv_coordinates;\n"
"attribute vec4 vertex_index;\n"
"attribute vec4 vertex_weight;\n"
"\n"
"uniform mat4 scale_matrix;\n"
"uniform mat4 rotation_matrix;\n"
"uniform mat4 position_matrix;\n"
"uniform mat4 port_view;\n"
"uniform mat4 projection_matrix;\n"
"uniform vec3 color_bind[150];  \n"
"        \n"
"varying vec3 color;\n"
"\n"
"void main(void)\n"
"{\n"
"    color = vec3(1.0,1.0,1.0);\n"
"    int i1 = int(vertex_index.x);\n"
"    int i2 = int(vertex_index.y);  \n"
"    int i3 = int(vertex_index.z);  \n"
"    int i4 = int(vertex_index.w);\n"
"    color = (color_bind[i1] * vertex_weight.x)+(color_bind[i2] * vertex_weight.y)+(color_bind[i3] * vertex_weight.z)+(color_bind[i4] * vertex_weight.w);\n"
"    vec4 vertex = vec4(vertex_position, 1.0);\n"
"    vertex *= scale_matrix;\n"
"    vertex *= rotation_matrix;\n"
"    vertex *= position_matrix;\n"
"    gl_Position = projection_matrix  * port_view * vertex;\n"
"}\n"
};

const GLchar* bind_vertex_shader_fragment = {
"#version 120\n"
"\n"
"varying vec3 color;\n"
"\n"
"void main(void)\n"
"{\n"
"    gl_FragColor = vec4(color,1.0);\n"
"} \n"
};

const GLchar* bind_vertex_shader_vector[2] = {bind_vertex_shader_vertex,bind_vertex_shader_fragment};

BindVertexShader::BindVertexShader():Shader("shader_bind_vertex", bind_vertex_shader_vector) {
    index_vertex = this->getAttributeLocation(program_shader_id,"vertex_index");
    weight_bind = this->getAttributeLocation(program_shader_id,"vertex_weight");
    color_bind = this->getUniformLocation(program_shader_id,"color_bind");
}

BindVertexShader::~BindVertexShader() {
}

void BindVertexShader::enableShaderVariables()
{
    
}

void BindVertexShader::setShaderVariables(Renderable* _renderable, Material* _material, Scene* _scene) {
    Shader::setShaderVariables(_renderable,_material,_scene);
    glEnableVertexAttribArray(index_vertex);
    glEnableVertexAttribArray(weight_bind);
    glVertexAttribPointer(index_vertex, 4, GL_FLOAT,GL_FALSE, 0, _renderable->getBindBone());
    glVertexAttribPointer(weight_bind, 4, GL_FLOAT,GL_FALSE, 0, _renderable->getWeightBone());
    glUniform3fv(color_bind,50*3,bind_vertex_color);
}

void BindVertexShader::disableShaderVariables()
{
    glDisableVertexAttribArray(attribute_vertex);
    glDisableVertexAttribArray(index_vertex);
    glDisableVertexAttribArray(weight_bind);
}

