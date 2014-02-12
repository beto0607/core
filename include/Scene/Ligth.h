/* 
 * File:   Ligth.h
 * Author: francisco
 *
 * Created on 12 de diciembre de 2013, 17:47
 */

#ifndef LIGTH_H
#define	LIGTH_H

#include "../Unnivelmas_conf.h"

namespace unnivelmas{
    
    class Ligth {
    public:
        Ligth();
        virtual ~Ligth();
        
        void turnOn();
        void turnOff();
        
    private:
        glm::vec3 color;
        GLfloat intensity;
    };
}// end namespace
#endif	/* LIGTH_H */

