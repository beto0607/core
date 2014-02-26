/* 
 * File:   JoystickListener.h
 * Author: fran
 *
 * Created on January 23, 2014, 10:06 PM
 */

#ifndef JOYSTICKLISTENER_H
#define	JOYSTICKLISTENER_H

#include "../Unnivelmas_conf.h"

namespace kaikai
{
    class JoystickListener {
    public:
        JoystickListener();
        virtual ~JoystickListener();
        
        virtual GLvoid buttonDown(GLint);
        virtual GLvoid buttonUp(GLint);
        virtual GLvoid axisMove(GLint,GLint);
    private:

    };
}
#endif	/* JOYSTICKLISTENER_H */

