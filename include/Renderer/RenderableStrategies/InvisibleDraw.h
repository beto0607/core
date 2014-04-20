/* 
 * File:   InvisibleStrategy.h
 * Author: francisco
 *
 * Created on 18 de abril de 2014, 18:33
 */

#ifndef INVISIBLEDRAW_H
#define	INVISIBLEDRAW_H

#include "../../Unnivelmas_conf.h"
#include <Renderer/RenderableStrategies/DrawStrategy.h>

namespace kaikai
{
    class InvisibleDraw : public DrawStrategy{
    public:
        InvisibleDraw();
        virtual ~InvisibleDraw();
        
        GLvoid drawStrategy();
        GLvoid drawRectangle(Renderable*);
        GLvoid drawMesh(Mesh*);
    private:

    };
}
#endif	/* INVISIBLESTRATEGY_H */

