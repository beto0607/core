/* 
 * File:   Input.h
 * Author: Francisco
 *
 * Created on 27 de octubre de 2013, 20:39
 */

#ifndef INPUT_H
#define	INPUT_H

#include "../Unnivelmas_conf.h"
#include <Input/JostickManager.h>

namespace unnivelmas
{
    class MouseInputHandler;
    class MouseEventListener;
    class JostickManager;
    class KeyBoardManager;
    class Clock;
    
        class Input {
        public:
            Input();
            virtual ~Input();

            GLboolean checkInput();
            GLvoid addMouseKeyPressedListener(MouseEventListener*);
            GLvoid addMouseMovedListener(MouseEventListener*);
            
            JostickManager* getJoystickManager();
            KeyBoardManager* getKeyBoardManager();
            MouseInputHandler* getMouseInputHandler();
            
        private:
            Clock* clock;
            GLboolean resu;
            MouseInputHandler* mouse;
            JostickManager* jostick;
            KeyBoardManager* keyboard;
            SDL_Event event_handler;
        };
}; // Namespace
#endif	/* INPUT_H */

