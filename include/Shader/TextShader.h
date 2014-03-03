/* 
 * File:   TextShader.h
 * Author: fran
 *
 * Created on February 1, 2014, 5:25 PM
 */

#ifndef TEXTSHADER_H
#define	TEXTSHADER_H

#include <Shader/Shader.h>

namespace kaikai
{
    class TextShader : public Shader{
    public:
        TextShader();
        virtual ~TextShader();

        void setShaderVariables(Renderable*, Material*, Scene*);
        void enableShaderVariables();
        void disableShaderVariables();
    private:
        GLint vPos;
        GLint sMat;
        GLint pMat;
        GLint proM;
        GLint vUVTex;
        GLint viewP;
    };
}
#endif	/* TEXTSHADER_H */

