/* 
 * File:   PruebaShader.cpp
 * Author: fran
 * 
 * Created on December 14, 2013, 6:17 PM
 */

#include <Shader/Shader.h>
#include <Shader/ShaderNull.h>
#include <Scene/Scene.h>
#include <Scene/Camera/Camera.h>
#include <Renderer/Renderable.h>
#include <Scene/Material.h>
#include <Texture/Texture.h>
#include <iostream>

using namespace kaikai;

const GLchar* null_shader_vertex = {
"#version 120\n"
"\n"
"attribute vec3 vertex_position;\n"
"attribute vec2 vertex_uv_coordinates;\n"
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
"    gl_Position = projection_matrix  * port_view * vertex;\n"
"}\n"
};

const GLchar* null_shader_fragment = {
"#version 120\n"
"\n"
"void main(void)\n"
"{\n"
"      gl_FragColor = vec4(0.0,1.0,0.0,1.0);\n"
"}\n" 
};
const GLchar* null_shader_vector[2] = {null_shader_vertex,null_shader_fragment};

ShaderNull::ShaderNull():Shader("shader_null", null_shader_vector) {
        
}

ShaderNull::~ShaderNull() {
}

void ShaderNull::enableShaderVariables()
{
    
}

void ShaderNull::setShaderVariables(Renderable* _renderable, Material* _material, Scene* _scene) {
    Shader::setShaderVariables(_renderable,_material,_scene);
}

void ShaderNull::disableShaderVariables()
{
    glDisableVertexAttribArray(attribute_vertex);
}