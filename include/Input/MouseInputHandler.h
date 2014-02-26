/* 
 * File:   MouseInputHandler.h
 * Author: francisco
 *
 * Created on 12 de enero de 2014, 17:28
 */

#ifndef MOUSEINPUTHANDLER_H
#define	MOUSEINPUTHANDLER_H

#include "../Unnivelmas_conf.h"
#include <Input/InputController.h>
#include <list>
#include <string>

namespace kaikai
{
    class MouseEventListener;    
    
    class MouseInputHandler : public InputController{
    public:
        MouseInputHandler();
        virtual ~MouseInputHandler();

        GLvoid mouseBotonDown(SDL_Event,GLvoid*);
        GLvoid mouseBotonUp(SDL_Event,GLvoid*);
        GLvoid mouseMotion(SDL_Event,GLvoid*); 
        GLvoid mouseWhell(SDL_Event,GLvoid*);
        
        GLvoid addKeyPressedLisener(MouseEventListener*);
        GLvoid addKeyReleaseLisener(MouseEventListener*);
        GLvoid addWhellLisener(MouseEventListener*);
        GLvoid addMotionLisener(MouseEventListener*);
        
    private:
        std::list<MouseEventListener*> move_liseners;
        std::list<MouseEventListener*> key_press_liseners;
        std::list<MouseEventListener*> key_release_liseners;
        std::list<MouseEventListener*> whell_liseners;
    };
}
#endif	/* MOUSEINPUTHANDLER_H */

