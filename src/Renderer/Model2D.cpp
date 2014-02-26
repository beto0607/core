/* 
 * File:   Model2D.cpp
 * Author: fran
 * 
 * Created on December 11, 2013, 8:02 AM
 */
#include <Renderer/Renderable.h>
#include <Renderer/Model2D.h>
#include <Scene/Material.h>
#include <Scene/MaterialNull.h>
#include <Core/Core.h>
#include <Texture/TextureManager.h>
#include <iostream>

using namespace kaikai;

Model2D::Model2D():Renderable() {
    material = ((Core::getInstance())->getTextureManager())->getNullMaterial();
    projection_matrix = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, 0.0f, 100.0f);
}

Model2D::~Model2D() {
}

void Model2D::draw()
{
    material->setVariables(this);
    //glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,index);
    glDrawArrays(GL_TRIANGLE_STRIP,0,4);
    material->disableVariables();
}

GLfloat* Model2D::getVertexBufferOffset()
{
    return vertex;
}

GLvoid Model2D::setMaterial(Material* _mat)
{
    this->material = _mat;
}

GLfloat Model2D::flipX()
{
    scale_matrix[0][0] *= -1;
}

GLfloat Model2D::flipY()
{
    scale_matrix[1][1] *= -1;
}