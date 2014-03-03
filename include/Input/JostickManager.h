/* 
 * File:   JostickManager.h
 * Author: fran
 *
 * Created on January 23, 2014, 8:36 PM
 */

#ifndef JOSTICKMANAGER_H
#define	JOSTICKMANAGER_H

#include "../Unnivelmas_conf.h"
#include <Input/InputController.h>
#include <list>

namespace kaikai
{
    class JoystickListener;
    
    class JostickManager : public InputController{
    public:
        JostickManager();
        virtual ~JostickManager();
        
        GLvoid joyAxisMotion(SDL_Event);
        GLvoid joyButtonUp(SDL_Event);
        GLvoid joyDeviceAdded(SDL_Event);
        GLvoid joyButtonDown(SDL_Event);
        
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

