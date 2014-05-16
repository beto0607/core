/* 
 * File:   SaveScene.h
 * Author: beto0607
 *
 * Created on 16 de mayo de 2014, 17:09
 */

#ifndef SAVESCENE_H
#define	SAVESCENE_H

#include<Command/Command.h>

namespace kaikai
{
    class SaveScene : public Command{
    public:
        SaveScene();
        virtual ~SaveScene();
                
        void execute();
    private:

    };
}
#endif	/* SAVESCENE_H */

