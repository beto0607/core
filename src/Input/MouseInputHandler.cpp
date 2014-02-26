/* 
 * File:   MouseInputHandler.cpp
 * Author: francisco
 * 
 * Created on 12 de enero de 2014, 17:28
 */
#include <Log/Logger.h>
#include <Input/MouseInputHandler.h>
#include <Input/MouseEventListener.h>
#include <list>

using namespace kaikai;

MouseInputHandler::MouseInputHandler() {
    (Logger::getInstance())->infoLog("MouseInputHandler was create susefully");
}

MouseInputHandler::~MouseInputHandler() {
}

GLvoid MouseInputHandler::mouseMotion(SDL_Event _event,GLvoid*)
{
    for(std::list<MouseEventListener*>::iterator it= move_liseners.begin(); it != move_liseners.end(); ++it)
       (*it)->mouseMoved(_event.motion.x,_event.motion.y);
}

GLvoid MouseInputHandler::mouseBotonDown(SDL_Event _event,GLvoid*)
{
    for(std::list<MouseEventListener*>::iterator it= key_press_liseners.begin(); it != key_press_liseners.end(); ++it)
       (*it)->keyPressed();
}

GLvoid MouseInputHandler::mouseBotonUp(SDL_Event _event,GLvoid*)
{
    for(std::list<MouseEventListener*>::iterator it= key_press_liseners.begin(); it != key_press_liseners.end(); ++it)
       (*it)->keyRelease();
}

GLvoid MouseInputHandler::mouseWhell(SDL_Event _event,GLvoid*)
{

}

GLvoid MouseInputHandler::addKeyPressedLisener(MouseEventListener* _mel)
{
    key_press_liseners.push_back(_mel);
}

GLvoid MouseInputHandler::addKeyReleaseLisener(MouseEventListener*)
{

}

GLvoid MouseInputHandler::addWhellLisener(MouseEventListener*)
{

}

GLvoid MouseInputHandler::addMotionLisener(MouseEventListener* _mel)
{
    move_liseners.push_back(_mel);
}