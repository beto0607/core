/* 
 * File:   RenderableStrategy.h
 * Author: francisco
 *
 * Created on 18 de abril de 2014, 13:32
 */

#ifndef DRAWSTRATEGY_H
#define	DRAWSTRATEGY_H

#include "../../Unnivelmas_conf.h"

namespace kaikai
{
    class Renderable;
    class Mesh;
    
    class DrawStrategy {
    public:
        DrawStrategy();
        virtual ~DrawStrategy();

        virtual GLvoid drawStrategy()=0;
        virtual GLvoid drawRectangle(Renderable*)=0;
        virtual GLvoid drawMesh(Mesh*)=0;
    private:

    };
}
#endif	/* RENDERABLESTRATEGY_H */

