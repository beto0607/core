/* 
 * File:   TimeEventListener.h
 * Author: francisco
 *
 * Created on 13 de enero de 2014, 19:31
 */

#ifndef TIMEEVENTLISTENER_H
#define	TIMEEVENTLISTENER_H

#include "../Unnivelmas_conf.h"

namespace unnivelmas{
    
    class TimeEventListener {
    public:
        TimeEventListener();
        virtual ~TimeEventListener();
    
        virtual GLvoid update(GLfloat);
    private:

    };
}
#endif	/* TIMEEVENTLISTENER_H */

