/* 
 * File:   PruebaShader.cpp
 * Author: fran
 * 
 * Created on December 14, 2013, 6:17 PM
 */

#include <Shader/Shader.h>
#include <Shader/TextShader.h>
#include <Scene/Scene.h>
#include <Renderer/Renderable.h>
#include <Scene/Material.h>
#include <Texture/Texture.h>
#include <Scene/Camera/Camera.h>
#include <iostream>

using namespace kaikai;

const GLchar* text_shader_vertex = {
"#version 120\n"
"\n"
"attribute vec3 vertex_position;\n"
"attribute vec2 vertex_uv_coordinates;\n"
"uniform mat4 scale_matrix;\n"
"uniform mat4 position_matrix;\n"
"uniform mat4 projection_matrix;\n"
"uniform mat4 port_view;\n"
"varying vec2 uv_coord;\n"
"\n"
"void main(void)\n"
"{\n"
"    vec4 vertex = vec4(vertex_position,1.0);\n"
"    vertex *= scale_matrix;\n"
"    vertex *= position_matrix;\n"
"    uv_coord = vertex_uv_coordinates;\n"
"    gl_Position = projection_matrix  * port_view * vertex;\n"
"}\n"
};

const GLchar* text_shader_fragment = {
"#version 120\n"
"\n"
"varying vec2 uv_coord;\n"
"uniform sampler2D texture_uniform_1;\n"
"\n"
"void main(void)\n"
"{\n"
"    vec4 color = texture2D(texture_uniform_1, uv_coord).zyxw;\n"
"    gl_FragColor = color;\n"
"}\n"
};

const GLchar* text_shader_vector[2] = {text_shader_vertex,text_shader_fragment};

TextShader::TextShader():Shader("text_shader",text_shader_vector) {
    
}

TextShader::~TextShader() {
}

void TextShader::enableShaderVariables()
{
    
}

void TextShader::setShaderVariables(Renderable* _renderable, Material* _material, Scene* _scene) {
    Shader::setShaderVariables(_renderable,_material,_scene);
    glBindTexture(GL_TEXTURE_2D,_material->getTexture()->getTexture());
}

void TextShader::disableShaderVariables()
{
    glDisableVertexAttribArray(attribute_vertex);
}