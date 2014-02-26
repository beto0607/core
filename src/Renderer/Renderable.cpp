
#include <Renderer/Renderable.h>
#include <Animation/Animation.h>
#include <Core/Core.h>
#include <Log/Logger.h>
#include <Scripting/Renderablelua.h>
#include <sstream>

using namespace kaikai;

Renderable::Renderable():MouseEventListener(),TimeEventListener(){
    animation = new Animation();
    scale_matrix = glm::mat3(1.0f);
    lua = new Renderablelua(this);
    width = 0;
    heigth = 0;
    radius = 0;
}

Renderable::~Renderable() {
    lua->~Renderablelua();
}

GLvoid Renderable::move(GLfloat x, GLfloat y)
{
    position_matrix = glm::mat3(1.0,0.0,x,
                                0.0,1.0,y,
                                0.0,0.0,1.0);
}

GLvoid Renderable::move(GLfloat x, GLfloat y, GLfloat z)
{
    position_matrix = glm::mat3(1.0,0.0,x,
                                0.0,1.0,y,
                                0.0,0.0,z);
}
            
GLfloat Renderable::getX()
{
    return position_matrix[0][2];
}

GLvoid Renderable::setX(GLfloat x)
{
    position_matrix[0][2] = x;
}
            
GLfloat Renderable::getY()
{
    return position_matrix[1][2];
}

GLvoid Renderable::setY(GLfloat y)
{
    position_matrix[1][2] = y;
}

GLfloat Renderable::getZ()
{
    return position_matrix[2][2];
}

GLvoid Renderable::setZ(GLfloat z)
{
    position_matrix[2][2] = z;
}

GLvoid Renderable::scale(GLfloat _scale)
{
    this->scale_matrix = glm::mat3(_scale,0.0,0.0,
                                   0.0,_scale,0.0,
                                   0.0,0.0,_scale);
}

GLfloat* Renderable::getScale()
{
    return glm::value_ptr(this->scale_matrix);
}

GLfloat* Renderable::getRotation()
{
    return glm::value_ptr(this->angle_matrix);
}

GLfloat* Renderable::getPosition()
{
    return glm::value_ptr(this->position_matrix);
}

GLfloat* Renderable::getProjectionMatrix()
{
    return glm::value_ptr(projection_matrix);
}

glm::vec2 Renderable::getTopRigth()
{
    return glm::vec2(position_matrix[0][2] + width,position_matrix[1][2] - heigth);
}
                        
glm::vec2 Renderable::getTopLeft()
{
    return glm::vec2(position_matrix[0][2] - width,position_matrix[1][2] - heigth);
}

glm::vec2 Renderable::getBottomRigth()
{
    return glm::vec2(position_matrix[0][2] + width,position_matrix[1][2] + heigth);
}

glm::vec2 Renderable::getBottomLeft()
{
    return glm::vec2(position_matrix[0][2] - width,position_matrix[1][2] + heigth);
}

GLfloat Renderable::getRadius()
{
    return radius;
}

GLfloat Renderable::getHeight()
{
        return heigth;
}
                        
GLfloat Renderable::getWidth()
{
        return width;
}

GLuint Renderable::getVertexBufferID()
{
    return buffer_id;
}

GLuint Renderable::getUVBufferID()
{
    return uv_id;
}

GLvoid Renderable::setName(std::string _name)
{
    name = _name;
}

std::string Renderable::getName()
{
    return name;
}

Shape* Renderable::getShape()
{
    return shape;
}

GLfloat Renderable::getTop()
{
    return position_matrix[1][2] - heigth;
}

GLfloat Renderable::getBottom()
{
    return position_matrix[1][2] + heigth;
}

GLfloat Renderable::getRigth()
{
    return position_matrix[0][2] + width;
}

GLfloat Renderable::getLeft()
{
    return position_matrix[0][2] - width;
}

GLvoid Renderable::topCollision(Renderable* _collider)
{

}

GLvoid Renderable::bottomCollision(Renderable* _collider)
{

}

GLvoid Renderable::leftCollision(Renderable* _collider)
{

}

GLvoid Renderable::rightCollision(Renderable* _collider)
{

}

GLvoid Renderable::setAnimation(Animation* _animation)
{
    animation = _animation;
}
                        
GLvoid Renderable::drawRenderable()
{
    animation->next(this);
    this->draw();
}

GLvoid Renderable::setUVCoordinates(GLfloat* new_uv_coordinates)
{
    glBindBuffer(GL_ARRAY_BUFFER,uv_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*8, new_uv_coordinates, GL_STATIC_DRAW);
}

GLvoid Renderable::play(const GLchar* _name)
{
    animation->play(_name);
}

GLvoid Renderable::openLUAfile(const GLchar* _filename)
{
    lua->openLUAFile(_filename);
}

GLvoid Renderable::mouseMoved(GLfloat x, GLfloat y)
{
    lua->mouseMoved(x,y);
}

GLvoid Renderable::keyPressed()
{

}                        

GLvoid Renderable::update(GLfloat _tick)
{

}