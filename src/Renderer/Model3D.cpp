/* 
 * File:   Model3D.cpp
 * Author: francisco
 * 
 * Created on 3 de marzo de 2014, 14:13
 */

#include <Renderer/Renderable.h>
#include <Renderer/Model3D.h>
#include <Scene/Material.h>
#include <Scene/MaterialNull.h>
#include <Scene/Scene.h>
#include <Core/Core.h>
#include <Texture/TextureManager.h>
#include <iostream>
#include <Renderer/Render.h>

using namespace kaikai;

Model3D::Model3D() {
    material = ((Core::getInstance())->getTextureManager())->getNullMaterial();
    GLfloat x = Core::getInstance()->getRenderManager()->getRendererX();
    GLfloat y = Core::getInstance()->getRenderManager()->getRendererY();
    GLfloat aspect = y/x;
    //projection_matrix = glm::perspective(45.0f,aspect,0.1f,500.0f);
    projection_matrix = glm::frustum(-1.0f, 1.0f,-aspect,aspect,1.0f,100.0f);
}

GLvoid Model3D::setOrtho()
{
    GLfloat x = Core::getInstance()->getRenderManager()->getRendererX();
    GLfloat y = Core::getInstance()->getRenderManager()->getRendererY();
    projection_matrix = glm::ortho(0.0f,x, y, 0.0f, 0.1f, 100.0f);
}

GLvoid Model3D::setOrtho(GLfloat _left,GLfloat _rigth,GLfloat _bottom,GLfloat _top,GLfloat _near,GLfloat _far)
{
    projection_matrix = glm::ortho(_left,_rigth, _top, _bottom, _near, _far);
}

GLvoid Model3D::setPerspective()
{
    GLfloat aspect = Core::getInstance()->getRenderManager()->getRendererY() / Core::getInstance()->getRenderManager()->getRendererX();
    projection_matrix = glm::frustum(-1.0f, 1.0f,-aspect,aspect,1.0f,100.0f);
}

GLvoid Model3D::setPerspective(GLfloat _fovy,GLfloat _x,GLfloat _y,GLfloat _near,GLfloat _far)
{
    projection_matrix = glm::frustum(-1.0f, 1.0f,_y/_x,_y/_x,1.0f,200.0f);
}

Model3D::~Model3D() {

}