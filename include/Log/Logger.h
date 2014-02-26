/* 
 * File:   Logger.h
 * Author: Francisco
 *
 * Created on 10 de noviembre de 2013, 11:13
 */

#ifndef LOGGER_H
#define	LOGGER_H

#include "../Unnivelmas_conf.h"
#include <iostream>
#include <fstream>
#include <string>

namespace kaikai
{
    class Logger {
    public:
        virtual ~Logger();
        
        GLvoid infoLog(std::string);
        GLvoid warnningLog(std::string);
        GLvoid criticalLog(std::string);
        
        static Logger* getInstance();
        
    private:
        Logger();
        static Logger* self;
        std::ofstream log_file;
    };
}; // namespace ENGINE_NMESPACE
#endif	/* LOGGER_H */

