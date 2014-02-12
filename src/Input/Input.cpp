/* 
 * File:   Input.cpp
 * Author: Francisco
 * 
 * Created on 27 de octubre de 2013, 20:39
 */

#include <Input/Input.h>
#include <Input/MouseInputHandler.h>
#include <Input/JostickManager.h>
#include <Input/KeyBoardManager.h>
#include <Input/MouseEventListener.h>
#include <Core/Core.h>
#include <Log/Logger.h>
#include <iostream>

using namespace unnivelmas;

Input::Input() {
    resu = true;
    mouse = new MouseInputHandler();
    jostick = new JostickManager();
    keyboard = new KeyBoardManager();
}

Input::~Input() {
    Logger::getInstance()->infoLog(std::string("Input destructor..."));
}

GLvoid Input::addMouseKeyPressedListener(MouseEventListener* _mel)
{
    mouse->addKeyPressedLisener(_mel);
}

GLvoid Input::addMouseMovedListener(MouseEventListener* _mel)
{
    mouse->addMotionLisener(_mel);
}

JostickManager* Input::getJoystickManager()
{
    return jostick;
}

KeyBoardManager* Input::getKeyBoardManager()
{
    return keyboard;
}

MouseInputHandler* Input::getMouseInputHandler()
{
    return mouse;
}

GLboolean Input::checkInput()
{
   if(SDL_PollEvent(&event_handler))
   {
       switch (event_handler.type)
        {
            case SDL_QUIT:
                resu = false;
                break;;
            case SDL_MOUSEBUTTONDOWN:
                mouse->keypresedEvent();
                break;;
            case SDL_MOUSEMOTION:
                mouse->moveEvent(event_handler.motion.x, event_handler.motion.y);
                break;;
            case SDL_MOUSEWHEEL:
                mouse->whellEvent();
                break;;
            case SDL_JOYAXISMOTION:
                jostick->axisMove(event_handler.jaxis);
                break;;
            case SDL_JOYBUTTONUP:
                jostick->buttonUp(event_handler.jbutton);
                break;;
            case SDL_JOYDEVICEADDED:
                jostick->createJoystick();
                break;;
            case SDL_JOYBUTTONDOWN:
                jostick->buttonDown(event_handler.jbutton);
                break;;    
            case SDL_KEYDOWN:
                keyboard->buttonDown(event_handler.key);
                break;;
            case SDL_KEYUP:
                keyboard->buttonUp(event_handler.key);
                break;;    
            default:
            break;
        }
    }
   keyboard->update();
   return resu;
}
