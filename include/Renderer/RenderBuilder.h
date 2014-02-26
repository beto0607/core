/* 
 * File:   RenderBuilder.h
 * Author: francisco
 *
 * Created on 19 de febrero de 2014, 10:06
 */

#ifndef RENDERBUILDER_H
#define	RENDERBUILDER_H

#include "../Unnivelmas_conf.h"

namespace kaikai
{
    class RenderBuilder {

        class Renderable;

    public:
        RenderBuilder();
        virtual ~RenderBuilder();

        GLvoid createRectangle(const GLchar*, GLfloat, GLfloat);
    private:

    };
}
#endif	/* RENDERBUILDER_H */

