/* 
 * File:   Mesh.cpp
 * Author: francisco
 * 
 * Created on 5 de marzo de 2014, 23:46
 */

#include <Renderer/Mesh.h>
#include <Renderer/Model3D.h>
#include <Scene/Material.h>
#include <Core/Core.h>
#include <Renderer/Render.h>
#include <Log/Logger.h>
#include <sstream>

using namespace kaikai;

Mesh::Mesh() : Model3D(){
    buffer_id = (Core::getInstance())->getRenderManager()->getNextVertexBufferObjectNumber();
    normal_id = (Core::getInstance())->getRenderManager()->getNextVertexBufferObjectNumber();
    uv_id = (Core::getInstance())->getRenderManager()->getNextUVBufferObjectNumber();
    index_id = (Core::getInstance())->getRenderManager()->getNextUVBufferObjectNumber();
}

Mesh::~Mesh() {
}

GLvoid Mesh::draw(Scene* _scene)
{
    material->setVariables(this,_scene);
    glEnableClientState(GL_INDEX_ARRAY);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,index_id);
    glDrawElements(GL_TRIANGLES,index_cant,GL_UNSIGNED_INT, 0);
    glDisableClientState(GL_INDEX_ARRAY);
    material->disableVariables();
}

GLvoid Mesh::setVertex(GLfloat* _vertex, GLint _cant)
{
    vertex_cant = _cant*3;
    GLint bufferSize;
    glBindBuffer(GL_ARRAY_BUFFER,buffer_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vertex_cant, _vertex, GL_STATIC_DRAW);
    glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &bufferSize);
    if(vertex_cant != bufferSize/sizeof(GLfloat))
    {
        std::stringstream mesage;
        mesage << "MESH: " << this->getName() << " had an error: Vertex, " << vertex_cant << " is diferent from " << bufferSize/sizeof(GLfloat) << "\n";
        (Logger::getInstance())->criticalLog(mesage.str());
    }
}
 
GLvoid Mesh::setNormal(GLfloat* _normal, GLint _cant)
{
    GLint bufferSize;
    glBindBuffer(GL_ARRAY_BUFFER,normal_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vertex_cant, _normal, GL_STATIC_DRAW);
    glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &bufferSize);
    if(vertex_cant != bufferSize/sizeof(GLfloat))
    {
        std::stringstream mesage;
        mesage << "MESH: " << this->getName() << " had an error: Normals, " << vertex_cant << " is diferent from " << bufferSize/sizeof(GLfloat) << "\n";
        (Logger::getInstance())->criticalLog(mesage.str());
    }
}
 
GLvoid Mesh::setUVCoord(GLfloat* _uv_coord, GLint _cant)       
{
    GLint bufferSize;
    glBindBuffer(GL_ARRAY_BUFFER,uv_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*_cant*2, _uv_coord, GL_STATIC_DRAW);
    glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &bufferSize);
    if(vertex_cant/3 != bufferSize/sizeof(GLfloat))
    {
        std::stringstream mesage;
        mesage << "MESH: " << this->getName() << " had an error: UV cord, " << vertex_cant/3 << " is diferent from " << bufferSize/sizeof(GLfloat) << "\n";
        (Logger::getInstance())->criticalLog(mesage.str());
    }
}

GLvoid Mesh::setIndex(GLuint* _index, GLint _cant)
{
    index_cant = _cant*3;
    GLint bufferSize;
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,index_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*index_cant, _index, GL_STATIC_DRAW);
    glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &bufferSize);
    if(index_cant != bufferSize/sizeof(GLuint))
    {
        std::stringstream mesage;
        mesage << "MESH: " << this->getName() << " had an error: Index, " << index_cant << " is diferent from " << bufferSize/sizeof(GLuint) << "\n";
        (Logger::getInstance())->criticalLog(mesage.str());
    }
    std::stringstream mesage;
    mesage << "MESH was load susefull with: " << vertex_cant/3 << " vertex and " << index_cant/3 << " index";
    (Logger::getInstance())->infoLog(mesage.str());
}