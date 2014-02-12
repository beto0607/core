/* 
 * File:   SetFps.h
 * Author: fran
 *
 * Created on January 13, 2014, 11:29 PM
 */

#ifndef SETFPS_H
#define	SETFPS_H

#include <Command/Command.h>

namespace unnivelmas
{
    class SetFps : public Command{
    public:
        SetFps();
        virtual ~SetFps();
        
        GLvoid execute();

    private:

    };
}
#endif	/* SETFPS_H */

