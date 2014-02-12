/* 
 * File:   KeyBoardListener.h
 * Author: francisco
 *
 * Created on 30 de enero de 2014, 18:10
 */

#ifndef KEYBOARDLISTENER_H
#define	KEYBOARDLISTENER_H

#include "../Unnivelmas_conf.h"

namespace unnivelmas
{
    class KeyBoardListener {
    public:
        KeyBoardListener();
        virtual ~KeyBoardListener();

        virtual GLvoid keyPressed(GLint);
        virtual GLvoid keyRelease(GLint);
        virtual GLvoid keyPressedYet(GLint);
        
    private:
        
    };
}
#endif	/* KEYBOARDLISTENER_H */

