/* 
 * File:   RectangleCommand.h
 * Author: francisco
 *
 * Created on 8 de enero de 2014, 19:19
 */

#ifndef RECTANGLECOMMAND_H
#define	RECTANGLECOMMAND_H

#include <Command/Command.h>

namespace unnivelmas
{
    class RectangleCommand : public Command{
    public:
        RectangleCommand();
        virtual ~RectangleCommand();
 
        GLvoid execute();
    private:

    };
}
#endif	/* RECTANGLECOMMAND_H */

