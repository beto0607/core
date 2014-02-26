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

using namespace kaikai;

Input::Input() {
    resu = true;
    mouse = new MouseInputHandler();
    jostick = new JostickManager();
    keyboard = new KeyBoardManager();
    controllers.insert(std::pair<GLint,InputController*>(SDL_MOUSEBUTTONDOWN,mouse));
    controllers.insert(std::pair<GLint,InputController*>(SDL_MOUSEMOTION,mouse));
    controllers.insert(std::pair<GLint,InputController*>(SDL_MOUSEWHEEL,mouse));
    controllers.insert(std::pair<GLint,InputController*>(SDL_JOYAXISMOTION,jostick));
    controllers.insert(std::pair<GLint,InputController*>(SDL_JOYBUTTONUP,jostick));
    controllers.insert(std::pair<GLint,InputController*>(SDL_JOYDEVICEADDED,jostick));
    controllers.insert(std::pair<GLint,InputController*>(SDL_JOYBUTTONDOWN,jostick));
    controllers.insert(std::pair<GLint,InputController*>(SDL_KEYDOWN,keyboard));
    controllers.insert(std::pair<GLint,InputController*>(SDL_KEYUP,keyboard));
    functions.insert(std::pair<GLint,InputControllerFunctionPointer>(SDL_MOUSEBUTTONDOWN,&InputController::mouseBotonDown));
    functions.insert(std::pair<GLint,InputControllerFunctionPointer>(SDL_MOUSEMOTION,&InputController::mouseMotion));
    functions.insert(std::pair<GLint,InputControllerFunctionPointer>(SDL_MOUSEWHEEL,&InputController::mouseWhell));
    functions.insert(std::pair<GLint,InputControllerFunctionPointer>(SDL_JOYAXISMOTION,&InputController::joyAxisMotion));
    functions.insert(std::pair<GLint,InputControllerFunctionPointer>(SDL_JOYBUTTONUP,&InputController::joyButtonUp));
    functions.insert(std::pair<GLint,InputControllerFunctionPointer>(SDL_JOYDEVICEADDED,&InputController::joyDeviceAdded));
    functions.insert(std::pair<GLint,InputControllerFunctionPointer>(SDL_JOYBUTTONDOWN,&InputController::joyButtonDown));
    functions.insert(std::pair<GLint,InputControllerFunctionPointer>(SDL_KEYDOWN,&InputController::keyDown));
    functions.insert(std::pair<GLint,InputControllerFunctionPointer>(SDL_KEYUP,&InputController::keyUp));
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
       if(event_handler.type == SDL_QUIT)
       {
           resu = false;
       }
       else
       {
           std::map<GLint,InputControllerFunctionPointer>::iterator it = functions.find(event_handler.type);
           if(it != functions.end())
           {
               ((InputController*)(controllers.find(event_handler.type)->second)->*functions.find(event_handler.type)->second)(event_handler,(GLvoid*)mouse); 
           }
       }
   }
       keyboard->update();
       return resu;
}
