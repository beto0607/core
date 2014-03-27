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
        
    };
}
#endif	/* SHADER3DNULL_H */

