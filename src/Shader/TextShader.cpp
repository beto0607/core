/* 
 * File:   PruebaShader.cpp
 * Author: fran
 * 
 * Created on December 14, 2013, 6:17 PM
 */

#include <Shader/Shader.h>
#include <Shader/TextShader.h>
#include <Renderer/Renderable.h>
#include <Scene/Material.h>
#include <Texture/Texture.h>
#include <iostream>

using namespace unnivelmas;

GLchar* text_shader_vertex = {
"#version 120\n"
"\n"
"attribute vec3 vertex_position;\n"
"attribute vec2 texture_cordinates;\n"
"uniform mat3 scale_matrix;\n"
"uniform mat3 position_matrix;\n"
"uniform mat4 projection_matrix;\n"
"varying vec2 uv_coord;\n"
"\n"
"void main(void)\n"
"{\n"
"    vec3 vertex = vertex_position;\n"
"    vertex *= scale_matrix;\n"
"    vertex[0] += position_matrix[0][2];\n"
"    vertex[1] += position_matrix[1][2];\n"
"    uv_coord = texture_cordinates;\n"
"    gl_Position = projection_matrix  * vec4(vertex, 1.0);\n"
"}\n"
};

GLchar* text_shader_fragment = {
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

GLchar* text_shader_vector[2] = {text_shader_vertex,text_shader_fragment};

TextShader::TextShader():Shader(text_shader_vector) {
    vPos = getAttributeLocation(program_shader_id,"vertex_position");
    vUVTex = getAttributeLocation(program_shader_id,"texture_cordinates");
    sMat = getUniformLocation(program_shader_id,"scale_matrix");
    pMat = getUniformLocation(program_shader_id,"position_matrix");
    proM = getUniformLocation(program_shader_id,"projection_matrix");
}

TextShader::~TextShader() {
}

void TextShader::enableShaderVariables()
{
    
}

void TextShader::setShaderVariables(Renderable* _renderable, Material* _material) {
    this->enableShader();
    glUniformMatrix3fv(sMat,1,GL_FALSE,_renderable->getScale());
    glUniformMatrix3fv(pMat,1,GL_FALSE,_renderable->getPosition());
    glUniformMatrix4fv(proM,1,GL_FALSE,_renderable->getProjectionMatrix());
    glEnableVertexAttribArray(vPos);
    glBindBuffer(GL_ARRAY_BUFFER,_renderable->getVertexBufferID());
    glVertexAttribPointer(vPos, 3, GL_FLOAT,GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER,_renderable->getUVBufferID());
    glEnableVertexAttribArray(vUVTex);
    glVertexAttribPointer(vUVTex, 2, GL_FLOAT,GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindTexture(GL_TEXTURE_2D,_material->getTexture()->getTexture());
}

void TextShader::disableShaderVariables()
{
    glDisableVertexAttribArray(vPos);
}