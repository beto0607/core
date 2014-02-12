/* 
 * File:   Salir.h
 * Author: francisco
 *
 * Created on 7 de enero de 2014, 21:14
 */

#ifndef SALIR_H
#define	SALIR_H

#include <Command/Command.h>

namespace unnivelmas{
    
    class Salir : public Command{
    public:
        Salir();
        virtual ~Salir();
        
        GLvoid execute();
    private:

        };
}
#endif	/* SALIR_H */

