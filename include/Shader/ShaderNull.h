/* 
 * File:   PruebaShader.h
 * Author: fran
 *
 * Created on December 14, 2013, 6:17 PM
 */

#ifndef PRUEBASHADER_H
#define	PRUEBASHADER_H

#include <Shader/Shader.h>

namespace kaikai
{
    class ShaderNull : public Shader{
    public:
        ShaderNull();
        virtual ~ShaderNull();

        void setShaderVariables(kaikai::Renderable*, kaikai::Material*);
        void enableShaderVariables();
        void disableShaderVariables();
    private:
        GLint vPos;
        GLint sMat;
        GLint pMat;
        GLint proM;
    };
}
#endif	/* PRUEBASHADER_H */

