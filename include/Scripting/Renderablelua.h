/* 
 * File:   Renderablelua.h
 * Author: francisco
 *
 * Created on 21 de febrero de 2014, 19:06
 */

#ifndef RENDERABLELUA_H
#define	RENDERABLELUA_H

#include "../Unnivelmas_conf.h"

namespace kaikai
{
    class Renderable;
    
    class Renderablelua {
    public:
        Renderablelua(Renderable*);
        virtual ~Renderablelua();
        
        GLvoid openLUAFile(const GLchar*);
        GLvoid mouseMoved(GLfloat,GLfloat);
        
        
    private:
        Renderable* renderable;
        lua_State* L;
    };
}
#endif	/* RENDERABLELUA_H */

