/* 
 * File:   Shader3DNull.h
 * Author: francisco
 *
 * Created on 18 de marzo de 2014, 18:31
 */

#ifndef SHADER3DNULL_H
#define	SHADER3DNULL_H

namespace kaikai
{
    class Shader3DNull : public Shader{
    public:
        Shader3DNull();
        virtual ~Shader3DNull();

        void setShaderVariables(Renderable*, Material*, Scene*);
        void enableShaderVariables();
        void disableShaderVariables();
    private:
        GLint vPos;
        GLint rMat;
        GLint sMat;
        GLint pMat;
        GLint proM;
        GLint viewP;
    };
}
#endif	/* SHADER3DNULL_H */

