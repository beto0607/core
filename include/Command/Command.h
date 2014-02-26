/* 
 * File:   Command.h
 * Author: Francisco
 *
 * Created on 1 de diciembre de 2013, 17:11
 */

#ifndef COMMAND_H
#define	COMMAND_H

#include "../Unnivelmas_conf.h"
#include <string>

namespace kaikai
{
    class Command {
        protected: 
            std::string command_id;
        public:
            Command();
            virtual ~Command();

            virtual void execute()=0;
    };
}

#endif	/* COMMAND_H */

