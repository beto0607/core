/* 
 * File:   EscalarZ.h
 * Author: beto0607
 *
 * Created on 31 de mayo de 2014, 18:26
 */

#ifndef ESCALARZ_H
#define	ESCALARZ_H

#include<Command/Command.h>

namespace kaikai
{
    
    
    class EscalarZ : public Command{
    public:
        EscalarZ();
        virtual ~EscalarZ();
        
        void execute();
    private:

    };
}

#endif	/* ESCALARZ_H */

