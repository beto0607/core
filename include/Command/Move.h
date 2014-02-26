/* 
 * File:   Move.h
 * Author: francisco
 *
 * Created on 23 de diciembre de 2013, 19:50
 */

#ifndef MOVE_H
#define	MOVE_H

#include <Command/Command.h>

namespace kaikai
{
    class Move : public Command{
    public:
        Move();
        virtual ~Move();
        
        void execute();
    private:

    };
}
#endif	/* MOVE_H */

