/* 
 * File:   Command.h
 * Author: Francisco
 *
 * Created on 27 de octubre de 2013, 22:35
 */

#ifndef COMMANDMANAGER_H
#define	COMMANDMANAGER_H

#include <map>
#include <string>

namespace unnivelmas
{   
    class Command;
    
    class CommandManager {
    public:
        CommandManager();
        virtual ~CommandManager();
        
        void waitForCommand();
        void stop();
    private:
        std::map<std::string,Command*> commands;
        bool end_flag;
    };
};
#endif	/* COMMANDMANAGER_H */

