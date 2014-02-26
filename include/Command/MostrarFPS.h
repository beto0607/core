/* 
 * File:   MostrarFPS.h
 * Author: francisco
 *
 * Created on 7 de enero de 2014, 21:35
 */

#ifndef MOSTRARFPS_H
#define	MOSTRARFPS_H

#include <Command/Command.h>

namespace kaikai{
    
    class MostrarFPS : public Command{
    public:
        MostrarFPS();
        virtual ~MostrarFPS();
        
        GLvoid execute();
    private:

    };
}
#endif	/* MOSTRARFPS_H */

