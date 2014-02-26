/* 
 * File:   PruebaShader.cpp
 * Author: fran
 * 
 * Created on December 14, 2013, 6:17 PM
 */
#include <Shader/Shader.h>
#include <Shader/SpriteShader.h>
#include <Renderer/Renderable.h>
#include <Scene/Material.h>
#include <Texture/Texture.h>
#include <iostream>

using namespace kaikai;

GLchar* sprite_shader_vertex = {
"#version 120\n"
"\n"
"attribute vec3 vertex_position;\n"
"attribute vec2 vertex_color;\n"
"uniform mat3 scale_matrix;\n"
"uniform mat3 rotation_matrix;\n"
"uniform mat3 position_matrix;\n"
"uniform mat4 projection_matrix;\n"
"uniform mat4 port_view;\n"
"varying vec2 uv_coord;\n"
"\n"
"void main(void)\n"
"{\n"
"    vec3 vertex = vertex_position;\n"
"    vertex *= scale_matrix;\n"
"    vertex[0] += position_matrix[0][2];\n"
"    vertex[1] += position_matrix[1][2];\n"
"    uv_coord = vertex_color;\n"
"    gl_Position = projection_matrix  * vec4(vertex, 1.0);\n"
"}\n"
};

GLchar* sprite_shader_fragment = {
"#version 120\n"
"\n"
"varying vec2 uv_coord;\n"
"uniform sampler2D texture_uniform_1;\n"
"\n"
"void main(void)\n"
"{\n"
"      gl_FragColor = texture2D(texture_uniform_1, uv_coord).xyzw;\n"
"}\n"
};

GLchar* sprite_shader_vector[2] = {sprite_shader_vertex, sprite_shader_fragment};

SpriteShader::SpriteShader():Shader(sprite_shader_vector) {
    vPos = getAttributeLocation(program_shader_id,"vertex_position");
    vCol = getAttributeLocation(program_shader_id,"vertex_color");
    sMat = getUniformLocation(program_shader_id,"scale_matrix");
    rMat = getUniformLocation(program_shader_id,"rotation_matrix");
    pMat = getUniformLocation(program_shader_id,"position_matrix");
    proM = getUniformLocation(program_shader_id,"projection_matrix");
    vieP = getUniformLocation(program_shader_id,"port_view");
    //tUni = getUniformLocation(program_shader_id,"texture_uniform_1");
}

SpriteShader::~SpriteShader() {
}

void SpriteShader::enableShaderVariables()
{
    
}

void SpriteShader::setShaderVariables(Renderable* _renderable, Material* _material) {
    this->enableShader();
    glm::vec3 eye = glm::vec3(0.0f,0.0f,10.0f);
    glm::vec3 center = glm::vec3(0.0f,0.0f,0.0f);
    glm::vec3 up = glm::vec3(0.0f,1.0f,0.0f);
    glm::mat4 viewport_matrix = glm::lookAt(eye,center,up);
    glUniformMatrix3fv(sMat,1,GL_FALSE,_renderable->getScale());
    glUniformMatrix3fv(rMat,1,GL_FALSE,_renderable->getRotation());
    glUniformMatrix3fv(pMat,1,GL_FALSE,_renderable->getPosition());
    glUniformMatrix4fv(proM,1,GL_FALSE,_renderable->getProjectionMatrix());
    glUniformMatrix4fv(vieP,1,GL_FALSE,glm::value_ptr(viewport_matrix));
    glEnableVertexAttribArray(vPos);
    glBindBuffer(GL_ARRAY_BUFFER,_renderable->getVertexBufferID());
    glVertexAttribPointer(vPos, 3, GL_FLOAT,GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER,_renderable->getUVBufferID());
    glEnableVertexAttribArray(vCol);
    glVertexAttribPointer(vCol, 2, GL_FLOAT,GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindTexture(GL_TEXTURE_2D,_material->getTexture()->getTexture());
    glUniform1i(tUni, 1);
}

void SpriteShader::disableShaderVariables()
{
    glDisableVertexAttribArray(vPos);
    glDisableVertexAttribArray(vCol);
}