/* 
 * File:   Rectangle.cpp
 * Author: fran
 * 
 * Created on December 11, 2013, 9:15 AM
 */
#include <Renderer/Renderable.h>
#include <Renderer/Model2D.h>
#include <Input/MouseEventListener.h>
#include <Renderer/Rectangle.h>
#include <Renderer/Render.h>
#include <Core/Core.h>
#include <Log/Logger.h>
#include <Collision/RectangleShape.h>
#include <sstream>


using namespace unnivelmas;

Rectangle::Rectangle(const GLchar* _name, GLfloat width, GLfloat heigth):Model2D(){
    this->heigth = heigth/2;
    this->width = width/2;
    this->shape = new RectangleShape();    
    this->shape->setRenderable(this); 
    this->name = std::string(_name);
            
    GLint bufferSize, uv_size;
    
    buffer_id = (Core::getInstance())->getRenderManager()->getNextVertexBufferObjectNumber();
    uv_id = (Core::getInstance())->getRenderManager()->getNextUVBufferObjectNumber();

    width *= 0.5;
    heigth *= 0.5;
    
    vertex = new GLfloat[12];
    vertex[0]=-width;vertex[1]=heigth; vertex[2]=0.0;
    vertex[3]=-width; vertex[4]=-heigth; vertex[5]=0.0;
    vertex[6]=width;vertex[7]=heigth;vertex[8]=0.0;
    vertex[9]=width;vertex[10]=-heigth;vertex[11]=0.0;
    
    texture_coordenates = new GLfloat[8];
    texture_coordenates[0] =0.0;texture_coordenates[1] =1.0;
    texture_coordenates[2] =0.0;texture_coordenates[3] =0.0;
    texture_coordenates[4] =1.0;texture_coordenates[5] =1.0;
    texture_coordenates[6] =1.0;texture_coordenates[7] =0.0;
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,buffer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLfloat)*12, vertex, GL_STATIC_DRAW);
    glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE_ARB, &bufferSize);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,uv_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLfloat)*8, texture_coordenates, GL_STATIC_DRAW);
    glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE_ARB, &uv_size);
    
    delete vertex;
    delete texture_coordenates;
    std::stringstream message;
    message << "  Rectangle " << name << " was created with ID: " << buffer_id << " UV_ID: " << uv_id << " VertexBufferSize: " << bufferSize << " UV BufferSize: " << uv_size;
    (Core::getInstance())->getLogger()->infoLog(message.str().c_str());
}

Rectangle::~Rectangle() {
}

GLvoid Rectangle::topCollision(Renderable* _collider)
{
    this->move(this->getX(), this->getY()+5);
}

GLvoid Rectangle::bottomCollision(Renderable* _collider)
{
    this->move(this->getX(), this->getY()-5);
}

GLvoid Rectangle::leftCollision(Renderable* _collider)
{
    this->move(this->getX()+5, this->getY());
}

GLvoid Rectangle::rightCollision(Renderable* _collider)
{
    this->move(this->getX()-5, this->getY());
}