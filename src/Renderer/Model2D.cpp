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
#include <Scene/Scene.h>
#include <Core/Core.h>
#include <Texture/TextureManager.h>
#include <iostream>
#include <Renderer/Render.h>

using namespace kaikai;

Model2D::Model2D():Renderable() {
    material = ((Core::getInstance())->getTextureManager())->getNullMaterial();
    GLfloat x = Core::getInstance()->getRenderManager()->getRendererX();
    GLfloat y = Core::getInstance()->getRenderManager()->getRendererY();
    projection_matrix = glm::ortho(0.0f,x, y, 0.0f, 0.1f, 100.0f);
}

Model2D::~Model2D() {
}

void Model2D::draw(Scene* _scene)
{
    glBindVertexArray(vba_id);
        material->setVariables(this,_scene);
        glDrawArrays(GL_TRIANGLE_STRIP,0,4);
        material->disableVariables();
    glBindVertexArray(0);
}

GLfloat Model2D::flipX()
{
    scale_matrix[0][0] *= -1;
}

GLfloat Model2D::flipY()
{
    scale_matrix[1][1] *= -1;
}

GLvoid Model2D::setOrtho()
{
    GLfloat x = Core::getInstance()->getRenderManager()->getRendererX();
    GLfloat y = Core::getInstance()->getRenderManager()->getRendererY();
    projection_matrix = glm::ortho(0.0f,x, y, 0.0f, 0.1f, 100.0f);
}

GLvoid Model2D::setOrtho(GLfloat _left,GLfloat _rigth,GLfloat _bottom,GLfloat _top,GLfloat _near,GLfloat _far)
{
    projection_matrix = glm::ortho(_left,_rigth, _top, _bottom, _near, _far);
}

GLvoid Model2D::setPerspective()
{
    GLfloat x = Core::getInstance()->getRenderManager()->getRendererX();
    GLfloat y = Core::getInstance()->getRenderManager()->getRendererY();
    projection_matrix = glm::perspective(5.0f, (GLfloat)(-1.0*x) / y, 1.0f, 1000.0f);
}

GLvoid Model2D::setPerspective(GLfloat _fovy,GLfloat _x,GLfloat _y,GLfloat _near,GLfloat _far)
{
    projection_matrix = glm::perspective(_fovy, _x / _y, _near, _far);
}