/* 
 * File:   MouseEventListener.h
 * Author: francisco
 *
 * Created on 12 de enero de 2014, 18:25
 */

#ifndef MOUSEEVENTLISTENER_H
#define	MOUSEEVENTLISTENER_H

#include "../Unnivelmas_conf.h"

namespace unnivelmas{
    
    class MouseEventListener {
    public:
        MouseEventListener();
        virtual ~MouseEventListener();

        virtual GLvoid mouseMoved(GLfloat, GLfloat);
        virtual GLvoid keyPressed();
        
    protected:

    };
}
#endif	/* MOUSEEVENTLISTENER_H */

