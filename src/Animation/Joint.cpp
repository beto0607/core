/* 
 * File:   Joint.cpp
 * Author: francisco
 * 
 * Created on 2 de abril de 2014, 14:12
 */

#include <Animation/Joint.h>
#include <Animation/Skeleton.h>
#include <Renderer/RenderableStrategies/InvisibleDraw.h>
#include <Renderer/RenderableStrategies/SolidDraw.h>
#include <Shader/Shader.h>
#include <Core/Core.h>
#include <Renderer/Render.h>
#include <iostream>

using namespace kaikai;

Joint::Joint():Model3D() {
    draw_strategy = new InvisibleDraw();
    head = glm::vec3(0.0);
    tail = glm::vec3(0.0,0.0,1.0);
    vertex_id = (Core::getInstance())->getRenderManager()->getNextVertexBufferObjectNumber();
}

Joint::~Joint() {
}

GLvoid Joint::setId(GLint _id)
{
    id = _id;
}

GLvoid Joint::setName(std::string _name)
{
    name = _name;
}

GLvoid Joint::setParentId(GLint _parent_id)
{
    parent_id = _parent_id;
}

GLvoid Joint::setHeader(glm::vec3 _header) 
{
    head = _header;
    glBindBuffer(GL_ARRAY_BUFFER,vertex_id);
    GLfloat _vertex[6] = {head[0],head[1],head[2],tail[0],tail[1],tail[2]};
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*6, _vertex, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

GLvoid Joint::setTail(glm::vec3 _tail)
{
    tail = _tail;
}

GLvoid Joint::setRotation(glm::quat _rotation)
{
    rotation = _rotation;
}

GLint Joint::getId()
{
    return id;
}

std::string Joint::getName()
{
    return name;
}

GLint Joint::getParentId()
{
    return parent_id;
}
        
glm::vec3 Joint::getHeader()
{
    return head;
}
        
glm::vec3 Joint::getTail()
{
    return tail;
}
        
glm::quat Joint::getRotation()
{
    return rotation;
}

GLvoid Joint::addChild(Joint* _child)
{
    childs.push_back(_child);
}

GLvoid Joint::draw(Scene* _scene, Shader* _shader)
{
    _shader->setShaderVariables(this,material,_scene);
     glDrawArrays(GL_LINE_STRIP,0,2);
    _shader->disableShaderVariables();
    for(std::list<Joint*>::iterator it = childs.begin(); it != childs.end(); ++it)
        (*it)->draw(_scene,_shader);
}

GLvoid Joint::draw(Scene* _scene)
{
    
}

GLvoid Joint::setInvertedMatrix(Skeleton* _skeleton)
{
    glm::mat4* inverted_matrix = _skeleton->getInvertedMatrixById(this->id);
    (*inverted_matrix)[0][3] = (head[0]*-1);
    (*inverted_matrix)[1][3] = (head[1]*-1);
    (*inverted_matrix)[2][3] = (head[2]*-1);
}
