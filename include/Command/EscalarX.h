/* 
 * File:   EscalarX.h
 * Author: beto0607
 *
 * Created on 31 de mayo de 2014, 18:26
 */

#ifndef ESCALARX_H
#define	ESCALARX_H

#include<Command/Command.h>

namespace kaikai
{
    
    
    class EscalarX : public Command{
    public:
        EscalarX();
        virtual ~EscalarX();
        
        void execute();
    private:

    };
}
#endif	/* ESCALARX_H */

