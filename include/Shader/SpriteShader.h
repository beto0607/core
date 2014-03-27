/* 
 * File:   PruebaShader.h
 * Author: fran
 *
 * Created on December 14, 2013, 6:17 PM
 */

#ifndef SPRITESHADER_H
#define	SPRITESHADER_H

#include "../Unnivelmas_conf.h"
#include <Shader/Shader.h>

namespace kaikai
{
    class SpriteShader : public Shader{
    public:
        SpriteShader();
        virtual ~SpriteShader();

        void setShaderVariables(Renderable*, Material*, Scene*);
        void enableShaderVariables();
        void disableShaderVariables();
    private:
        
    };
}
#endif	/* PRUEBASHADER_H */

