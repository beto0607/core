/* 
 * File:   Escalar.h
 * Author: francisco
 *
 * Created on 22 de diciembre de 2013, 19:03
 */

#ifndef ESCALAR_H
#define	ESCALAR_H

#include<Command/Command.h>

namespace kaikai
{
    
    
    class Escalar : public Command{
    public:
        Escalar();
        virtual ~Escalar();
        
        void execute();
    private:

    };
}
#endif	/* ESCALAR_H */

