/* 
 * File:   InputController.h
 * Author: francisco
 *
 * Created on 25 de febrero de 2014, 17:25
 */

#ifndef INPUTCONTROLLER_H
#define	INPUTCONTROLLER_H

#include "../Unnivelmas_conf.h"

namespace kaikai
{
    
class InputController {
public:
    InputController();
    virtual ~InputController();
    
    virtual GLvoid systemQuit(SDL_Event);
    virtual GLvoid mouseBotonUp(SDL_Event);
    virtual GLvoid mouseBotonDown(SDL_Event);
    virtual GLvoid mouseMotion(SDL_Event); 
    virtual GLvoid mouseWhell(SDL_Event);
    virtual GLvoid joyAxisMotion(SDL_Event);
    virtual GLvoid joyButtonUp(SDL_Event);
    virtual GLvoid joyDeviceAdded(SDL_Event);
    virtual GLvoid joyButtonDown(SDL_Event);
    virtual GLvoid keyDown(SDL_Event);
    virtual GLvoid keyUp(SDL_Event);
    virtual GLvoid keyKeppedPress(SDL_Event);
    
    };
}
#endif	/* INPUTCONTROLLER_H */

