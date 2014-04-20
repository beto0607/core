/* 
 * File:   WireframeDraw.h
 * Author: francisco
 *
 * Created on 18 de abril de 2014, 13:40
 */

#ifndef WIREFRAMEDRAW_H
#define	WIREFRAMEDRAW_H

#include <Renderer/RenderableStrategies/DrawStrategy.h>

namespace kaikai
{
    class WireframeDraw : public DrawStrategy{
    public:
        WireframeDraw();
        virtual ~WireframeDraw();
        
        GLvoid drawStrategy();
        GLvoid drawRectangle(Renderable*);
        GLvoid drawMesh(Mesh*);
    private:

    };
}
#endif	/* WIREFRAMEDRAW_H */

