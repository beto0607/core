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

using namespace unnivelmas;

MouseInputHandler::MouseInputHandler() {
    (Logger::getInstance())->infoLog("MouseInputHandler was create susefully");
}

MouseInputHandler::~MouseInputHandler() {
}

GLvoid MouseInputHandler::moveEvent(GLfloat x, GLfloat y)
{
    for(std::list<MouseEventListener*>::iterator it= move_liseners.begin(); it != move_liseners.end(); ++it)
       (*it)->mouseMoved(x,y);
}

GLvoid MouseInputHandler::keypresedEvent()
{
    for(std::list<MouseEventListener*>::iterator it= key_press_liseners.begin(); it != key_press_liseners.end(); ++it)
       (*it)->keyPressed();
}

GLvoid MouseInputHandler::keyreleaseEvent()
{
    
}

GLvoid MouseInputHandler::whellEvent()
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