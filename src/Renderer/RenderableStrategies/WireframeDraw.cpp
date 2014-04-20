/* 
 * File:   WireframeDraw.cpp
 * Author: francisco
 * 
 * Created on 18 de abril de 2014, 13:40
 */

#include <Renderer/RenderableStrategies/WireframeDraw.h>
#include <Renderer/Mesh.h>
#include <Renderer/Renderable.h>

using namespace kaikai;

WireframeDraw::WireframeDraw() {
}

WireframeDraw::~WireframeDraw() {
}

GLvoid WireframeDraw::drawStrategy()
{

}

GLvoid WireframeDraw::drawRectangle(Renderable*)
{
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT, 0);
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );  
}

GLvoid WireframeDraw::drawMesh(Mesh* _mesh)
{
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glDrawElements(GL_TRIANGLES,_mesh->getIndexCant(),GL_UNSIGNED_INT, 0);
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );  
}
