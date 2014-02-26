/* 
 * File:   KeyBoardManager.cpp
 * Author: francisco
 * 
 * Created on 27 de enero de 2014, 18:53
 */

#include <Input/KeyBoardManager.h>
#include <Input/KeyBoardListener.h>
#include <iostream>
#include <map>

using namespace kaikai;

KeyBoardManager::KeyBoardManager() {
    keys_quewe_sem = SDL_CreateSemaphore(1);
}

KeyBoardManager::~KeyBoardManager() {
}

GLvoid KeyBoardManager::keyDown(SDL_Event _event,GLvoid*)
{
    SDL_SemWait(keys_quewe_sem);
    if((GLint)_event.key.repeat == 0)
    {
       keys_quewe.push_back((GLint)_event.key.keysym.sym);
       if(key_pressed.find(_event.key.keysym.sym) != key_pressed.end())
                (key_pressed.find(_event.key.keysym.sym))->second->keyPressed(_event.key.keysym.sym);
    }
    SDL_SemPost(keys_quewe_sem);
}

GLvoid KeyBoardManager::keyKeppedPress(SDL_Event _event,GLvoid*)
{

}

GLvoid KeyBoardManager::keyUp(SDL_Event _event,GLvoid*)
{
    SDL_SemWait(keys_quewe_sem);
    keys_quewe.remove((GLint)_event.key.keysym.sym);
    if(key_release.find(_event.key.keysym.sym) != key_release.end())
        key_release.find(_event.key.keysym.sym)->second->keyRelease(_event.key.keysym.sym);
    SDL_SemPost(keys_quewe_sem);
}

GLvoid KeyBoardManager::update()
{
   SDL_SemWait(keys_quewe_sem);
   for(std::list<GLint>::iterator it = keys_quewe.begin();keys_quewe.size() > 0 && it != keys_quewe.end(); it++)
   {
       if(key_release.find(*it) != key_release.end())
          key_pressed_yet.find(*it)->second->keyPressedYet(*it);
   }
   SDL_SemPost(keys_quewe_sem);
}

GLvoid KeyBoardManager::addAllKeyListener(GLint _key,KeyBoardListener* _listener)
{
    key_pressed.insert(std::pair<GLint,KeyBoardListener*>(_key,_listener));
    key_release.insert(std::pair<GLint,KeyBoardListener*>(_key,_listener));
    key_pressed_yet.insert(std::pair<GLint,KeyBoardListener*>(_key,_listener));
}

GLvoid KeyBoardManager::addKeyPressedListener(GLint _key,KeyBoardListener* _listener)
{
    key_pressed.insert(std::pair<GLint,KeyBoardListener*>(_key,_listener));
}

GLvoid KeyBoardManager::addKeyReleaseListener(GLint _key,KeyBoardListener* _listener)
{
    key_release.insert(std::pair<GLint,KeyBoardListener*>(_key,_listener));
}

GLvoid KeyBoardManager::addPressedKeyYetListener(GLint _key,KeyBoardListener* _listener)
{
    key_pressed_yet.insert(std::pair<GLint,KeyBoardListener*>(_key,_listener));
}