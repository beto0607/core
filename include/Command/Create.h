/* 
 * File:   Create.h
 * Author: francisco
 *
 * Created on 7 de enero de 2014, 21:58
 */

#ifndef CREATE_H
#define	CREATE_H

#include <Command/Command.h>
#include <map>
#include <string>

namespace unnivelmas
{
    class Create : public Command{
    public:
        Create();
        virtual ~Create();
        
        GLvoid execute();
    private:
        std::map<std::string, Command*> functions;
    };
}
#endif	/* CREATE_H */

