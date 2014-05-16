/* 
 * File:   Ligth.h
 * Author: francisco
 *
 * Created on 12 de diciembre de 2013, 17:47
 */

#ifndef LIGTH_H
#define	LIGTH_H

#include "../Unnivelmas_conf.h"

namespace kaikai{
    
    class Ligth {
    public:
        Ligth();
        virtual ~Ligth();
        
        void turnOn();
        void turnOff();
        
        GLfloat getIntensity();
        GLfloat getColorR();
        GLfloat getColorG();
        GLfloat getColorB();
    private:
        glm::vec3 color;
        GLfloat intensity;
    };
}// end namespace
#endif	/* LIGTH_H */

