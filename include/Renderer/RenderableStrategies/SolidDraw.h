/* 
 * File:   SolidDraw.h
 * Author: francisco
 *
 * Created on 18 de abril de 2014, 13:39
 */

#ifndef SOLIDDRAW_H
#define	SOLIDDRAW_H

#include <Renderer/RenderableStrategies/DrawStrategy.h>

namespace kaikai
{
    class SolidDraw : public DrawStrategy {
    public:
        SolidDraw();
        virtual ~SolidDraw();

        GLvoid drawStrategy();
        GLvoid drawRectangle(Renderable*);
        GLvoid drawMesh(Mesh*);
    private:

    };
}
#endif	/* SOLIDDRAW_H */

