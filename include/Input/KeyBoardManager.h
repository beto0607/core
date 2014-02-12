/* 
 * File:   KeyBoardManager.h
 * Author: francisco
 *
 * Created on 27 de enero de 2014, 18:53
 */

#ifndef KEYBOARDMANAGER_H
#define	KEYBOARDMANAGER_H

#include "../Unnivelmas_conf.h"
#include <list>
#include <map>

namespace unnivelmas
{
    class KeyBoardListener;
    
    class KeyBoardManager {
    public:
        KeyBoardManager();
        virtual ~KeyBoardManager();
        
        GLvoid buttonDown(SDL_KeyboardEvent);
        GLvoid buttonUp(SDL_KeyboardEvent);
        GLvoid buttonPressed(SDL_KeyboardEvent);
        
        GLvoid addPressedKeyYetListener(GLint,KeyBoardListener*);
        GLvoid addKeyReleaseListener(GLint,KeyBoardListener*);
        GLvoid addKeyPressedListener(GLint,KeyBoardListener*);
        GLvoid addAllKeyListener(GLint,KeyBoardListener*);
        GLvoid update();
        
    private:
        SDL_sem* keys_quewe_sem;
        std::map<GLint,KeyBoardListener*> key_pressed;
        std::map<GLint,KeyBoardListener*> key_release;
        std::map<GLint,KeyBoardListener*> key_pressed_yet;
        std::list<GLint> keys_quewe;
    };
}
#endif	/* KEYBOARDMANAGER_H */

