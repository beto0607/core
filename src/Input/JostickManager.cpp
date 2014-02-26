/* 
 * File:   JostickManager.cpp
 * Author: fran
 * 
 * Created on January 23, 2014, 8:36 PM
 */

#include <Input/JostickManager.h>
#include <Input/JoystickListener.h>
#include <Log/Logger.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace kaikai;

JostickManager::JostickManager() {
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    jostick_id=0;
    cant_jostiks = SDL_NumJoysticks();
    std::string mesage = std::string("JostickManager was create susefully whit: ");
    std::stringstream number;
    number << cant_jostiks;
    mesage.append(number.str());
    mesage.append(" Joysticks");
    (Logger::getInstance())->infoLog(mesage.c_str());
}

JostickManager::~JostickManager() {
}

GLvoid JostickManager::joyDeviceAdded(SDL_Event _event,GLvoid*)
{
    SDL_Joystick* joy = SDL_JoystickOpen(jostick_id);
    if (joy) {
        std::cout << "Opened Joystick " << jostick_id << "\n";
    } else {
        std::cout << "Couldn't open Joystick\n";
    }
    jostick_id++;
}

GLvoid JostickManager::joyButtonDown(SDL_Event _event,GLvoid*)
{
    for(std::list<JoystickListener*>::iterator it= button_down_listeners.begin(); it != button_down_listeners.end(); ++it)
       (*it)->buttonDown((GLint)_event.jbutton.button);
}

GLvoid JostickManager::joyButtonUp(SDL_Event _event,GLvoid*)
{
    for(std::list<JoystickListener*>::iterator it= button_up_listeners.begin(); it != button_up_listeners.end(); ++it)
       (*it)->buttonUp((GLint)_event.jbutton.button);
}

GLvoid JostickManager::joyAxisMotion(SDL_Event _event,GLvoid*)
{
    for(std::list<JoystickListener*>::iterator it= button_axis_listeners.begin(); it != button_axis_listeners.end(); ++it)
       (*it)->axisMove((GLint)_event.jaxis.axis, _event.jaxis.value);
}

GLvoid JostickManager::addButtonDownListener(JoystickListener* _listener)
{
    button_down_listeners.push_back(_listener);
}

GLvoid JostickManager::addButtonUpListener(JoystickListener* _listener)
{
    button_up_listeners.push_back(_listener);
}

GLvoid JostickManager::addAxisListener(JoystickListener* _listener)
{
    button_axis_listeners.push_back(_listener);
}