/* 
 * File:   MouseInputHandler.h
 * Author: francisco
 *
 * Created on 12 de enero de 2014, 17:28
 */

#ifndef MOUSEINPUTHANDLER_H
#define	MOUSEINPUTHANDLER_H

#include "../Unnivelmas_conf.h"
#include <list>
#include <string>

namespace unnivelmas
{
    class MouseEventListener;    
    
    class MouseInputHandler {
    public:
        MouseInputHandler();
        virtual ~MouseInputHandler();

        GLvoid moveEvent(GLfloat, GLfloat);
        GLvoid keypresedEvent();
        GLvoid keyreleaseEvent();
        GLvoid whellEvent();
        
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

