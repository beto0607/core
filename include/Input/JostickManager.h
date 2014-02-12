/* 
 * File:   JostickManager.h
 * Author: fran
 *
 * Created on January 23, 2014, 8:36 PM
 */

#ifndef JOSTICKMANAGER_H
#define	JOSTICKMANAGER_H

#include "../Unnivelmas_conf.h"
#include <list>

namespace unnivelmas
{
    class JoystickListener;
    
    class JostickManager {
    public:
        JostickManager();
        virtual ~JostickManager();
        
        GLvoid createJoystick();
        GLvoid buttonDown(SDL_JoyButtonEvent);
        GLvoid buttonUp(SDL_JoyButtonEvent);
        GLvoid axisMove(SDL_JoyAxisEvent);
        
        GLvoid addButtonDownListener(JoystickListener*);
        GLvoid addButtonUpListener(JoystickListener*);
        GLvoid addAxisListener(JoystickListener*);
    private:
        GLint cant_jostiks;
        GLint jostick_id;
        std::list<JoystickListener*> button_down_listeners;
        std::list<JoystickListener*> button_up_listeners;
        std::list<JoystickListener*> button_axis_listeners;
    };
}
#endif	/* JOSTICKMANAGER_H */

