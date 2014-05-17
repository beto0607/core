/* 
 * File:   LoadScene.h
 * Author: beto0607
 *
 * Created on 17 de mayo de 2014, 18:43
 */

#ifndef LOADSCENE_H
#define	LOADSCENE_H

#include<Command/Command.h>

namespace kaikai
{
    class LoadScene : public Command{
    public:
        LoadScene();
        virtual ~LoadScene();
        
        void execute();
    private:

    };
}
#endif	/* LOADSCENE_H */

