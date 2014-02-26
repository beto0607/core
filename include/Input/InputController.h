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
    
    virtual GLvoid systemQuit(SDL_Event,GLvoid*);
    virtual GLvoid mouseBotonUp(SDL_Event,GLvoid*);
    virtual GLvoid mouseBotonDown(SDL_Event,GLvoid*);
    virtual GLvoid mouseMotion(SDL_Event,GLvoid*); 
    virtual GLvoid mouseWhell(SDL_Event,GLvoid*);
    virtual GLvoid joyAxisMotion(SDL_Event,GLvoid*);
    virtual GLvoid joyButtonUp(SDL_Event,GLvoid*);
    virtual GLvoid joyDeviceAdded(SDL_Event,GLvoid*);
    virtual GLvoid joyButtonDown(SDL_Event,GLvoid*);
    virtual GLvoid keyDown(SDL_Event,GLvoid*);
    virtual GLvoid keyUp(SDL_Event,GLvoid*);
    virtual GLvoid keyKeppedPress(SDL_Event,GLvoid*);
    
    };
}
#endif	/* INPUTCONTROLLER_H */

