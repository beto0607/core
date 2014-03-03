/* 
 * File:   PruebaShader.cpp
 * Author: fran
 * 
 * Created on December 14, 2013, 6:17 PM
 */
#include <Shader/Shader.h>
#include <Shader/SpriteShader.h>
#include <Scene/Scene.h>
#include <Renderer/Renderable.h>
#include <Scene/Material.h>
#include <Scene/Camera.h>
#include <Texture/Texture.h>
#include <iostream>

using namespace kaikai;

GLchar* sprite_shader_vertex = {
"#version 120\n"
"\n"
"attribute vec3 vertex_position;\n"
"attribute vec2 vertex_color;\n"
"uniform mat4 scale_matrix;\n"
"uniform mat3 rotation_matrix;\n"
"uniform mat4 position_matrix;\n"
"uniform mat4 projection_matrix;\n"
"varying vec2 uv_coord;\n"
"uniform mat4 port_view;\n"
"\n"
"void main(void)\n"
"{\n"
"    vec4 vertex = vec4(vertex_position,1.0);\n"
"    vertex *= scale_matrix;\n"
"    vertex *= position_matrix;\n"
"    uv_coord = vertex_color;\n"
"    vertex *= port_view;\n"
"    gl_Position = projection_matrix  * vertex;\n"
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
    viewP = getUniformLocation(program_shader_id,"port_view");
}

SpriteShader::~SpriteShader() {
}

void SpriteShader::enableShaderVariables()
{
    
}

void SpriteShader::setShaderVariables(Renderable* _renderable, Material* _material, Scene* _scene) {
    this->enableShader();
    glUniformMatrix4fv(sMat,1,GL_FALSE,_renderable->getScale());
    glUniformMatrix3fv(rMat,1,GL_FALSE,_renderable->getRotation());
    glUniformMatrix4fv(pMat,1,GL_FALSE,_renderable->getPosition());
    glUniformMatrix4fv(proM,1,GL_FALSE,_renderable->getProjectionMatrix());
    glUniformMatrix4fv(viewP,1,GL_FALSE,_scene->getCamera()->getPosition());
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