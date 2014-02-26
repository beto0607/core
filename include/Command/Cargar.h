/* 
 * File:   Cargar.h
 * Author: Francisco
 *
 * Created on 1 de diciembre de 2013, 18:25
 */

#ifndef CARGAR_H
#define	CARGAR_H

#include<Command/Command.h>

namespace kaikai
{
    class Cargar : public Command{
    public:
        Cargar();
        virtual ~Cargar();
        
        void execute();
    private:

    };
}
#endif	/* CARGAR_H */

