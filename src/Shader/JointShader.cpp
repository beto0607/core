/* 
 * File:   JointShader.cpp
 * Author: francisco
 * 
 * Created on 19 de abril de 2014, 17:28
 */

#include <Shader/Shader.h>
#include <Shader/JointShader.h>
#include <Animation/Joint.h>
#include <iostream>

using namespace kaikai;

JointShader::JointShader():Shader("joint_shader","resources/shaders/joint.vert","resources/shaders/joint.frag")
{
    uniform_color = this->getUniformLocation(program_shader_id,"joint_id");
}

JointShader::~JointShader() {
}

GLvoid JointShader::setShaderVariables(Renderable* _renderable, Material* _material, Scene* _scene)
{
    Shader::setShaderVariables(_renderable,_material,_scene);
    glUniform1f(uniform_color,((Joint*)_renderable)->getId());
}
 
GLvoid JointShader::enableShaderVariables()
{

}

GLvoid JointShader::disableShaderVariables()
{

}
