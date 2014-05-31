/* 
 * File:   EscalarY.h
 * Author: beto0607
 *
 * Created on 31 de mayo de 2014, 18:26
 */

#ifndef ESCALARY_H
#define	ESCALARY_H


#include<Command/Command.h>

namespace kaikai
{
    
    
    class EscalarY : public Command{
    public:
        EscalarY();
        virtual ~EscalarY();
        
        void execute();
    private:

    };
}

#endif	/* ESCALARY_H */

