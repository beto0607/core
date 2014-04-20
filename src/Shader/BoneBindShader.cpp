/* 
 * File:   BoneBindShader.cpp
 * Author: francisco
 * 
 * Created on 15 de abril de 2014, 18:28
 */

#include <Shader/BoneBindShader.h>
#include <Renderer/Renderable.h>
#include <Scene/Material.h>
#include <Texture/Texture.h>
#include <Renderer/Actor.h>

using namespace kaikai;

BoneBindShader::BoneBindShader() : Shader("shader_bind_vertex", "resources/shaders/bind.vert", "resources/shaders/bind.frag"){
    index_vertex = this->getAttributeLocation(program_shader_id,"vertex_index");
    weight_bind = this->getAttributeLocation(program_shader_id,"vertex_weight");
    inv_pose = this->getUniformLocation(program_shader_id,"inv_pose");
}

BoneBindShader::~BoneBindShader() {
}

void BoneBindShader::enableShaderVariables()
{
    
}

void BoneBindShader::setShaderVariables(Renderable* _renderable, Material* _material, Scene* _scene) {
    Shader::setShaderVariables(_renderable,_material,_scene);
    glEnableVertexAttribArray(index_vertex);
    glEnableVertexAttribArray(weight_bind);
    glVertexAttribPointer(index_vertex, 4, GL_FLOAT,GL_FALSE, 0, _renderable->getBindBone());
    glVertexAttribPointer(weight_bind, 4, GL_FLOAT,GL_FALSE, 0, _renderable->getWeightBone());
    //glUniformMatrix4fv(inv_pose,50,GL_FALSE,((Actor*)_renderable)->getInvertedPoseMatrixArray());
    glBindTexture(GL_TEXTURE_2D,_material->getTexture()->getTexture());
}

void BoneBindShader::disableShaderVariables()
{
    glDisableVertexAttribArray(attribute_vertex);
    glDisableVertexAttribArray(index_vertex);
    glDisableVertexAttribArray(weight_bind);
}
