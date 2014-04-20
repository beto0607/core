/* 
 * File:   SolidDraw.cpp
 * Author: francisco
 * 
 * Created on 18 de abril de 2014, 13:39
 */

#include <Renderer/RenderableStrategies/SolidDraw.h>
#include <Renderer/Mesh.h>
#include <Renderer/Renderable.h>

using namespace kaikai;

SolidDraw::SolidDraw() {
}

SolidDraw::~SolidDraw() {
}

GLvoid SolidDraw::drawStrategy()
{

}

GLvoid SolidDraw::drawRectangle(Renderable*)
{
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT, 0);
}

GLvoid SolidDraw::drawMesh(Mesh* _mesh)
{
    glDrawElements(GL_TRIANGLES,_mesh->getIndexCant(),GL_UNSIGNED_INT, 0);
}
