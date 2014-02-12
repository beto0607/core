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

using namespace unnivelmas;

KeyBoardManager::KeyBoardManager() {
    keys_quewe_sem = SDL_CreateSemaphore(1);
}

KeyBoardManager::~KeyBoardManager() {
}

GLvoid KeyBoardManager::buttonDown(SDL_KeyboardEvent _key)
{
    SDL_SemWait(keys_quewe_sem);
    if((GLint)_key.repeat == 0)
    {
       keys_quewe.push_back((GLint)_key.keysym.sym);
       if(key_pressed.find(_key.keysym.sym) != key_pressed.end())
                (key_pressed.find(_key.keysym.sym))->second->keyPressed(_key.keysym.sym);
    }
    SDL_SemPost(keys_quewe_sem);
}

GLvoid KeyBoardManager::buttonUp(SDL_KeyboardEvent _key)
{
    SDL_SemWait(keys_quewe_sem);
    keys_quewe.remove((GLint)_key.keysym.sym);
    if(key_release.find(_key.keysym.sym) != key_release.end())
        key_release.find(_key.keysym.sym)->second->keyRelease(_key.keysym.sym);
    SDL_SemPost(keys_quewe_sem);
}

GLvoid KeyBoardManager::buttonPressed(SDL_KeyboardEvent _key)
{
    
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