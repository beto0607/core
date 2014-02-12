/* 
 * File:   Logger.cpp
 * Author: Francisco
 * 
 * Created on 10 de noviembre de 2013, 11:13
 */

#include <Log/Logger.h>
#include <iostream>
#include <string>

using namespace unnivelmas;

Logger::Logger() {
    log_file.open("log");
    log_file.close();
}

Logger::~Logger() {
    this->infoLog(std::string("Logger Manager shutdown..."));
}

Logger* Logger::self = 0;

Logger* Logger::getInstance()
{
    if(!self)
        self = new Logger();
    return self;    
}

GLvoid Logger::infoLog(std::string fmt)
{
    log_file.open("log", std::fstream::app);
    log_file << "INFORMATION: " << fmt << "\n";
    log_file.close();
}

GLvoid Logger::warnningLog(std::string fmt)
{
    log_file.open("log", std::fstream::app);
    log_file << "WARNING: " << fmt << "\n";
    log_file.close();
}

GLvoid Logger::criticalLog(std::string fmt)
{
    log_file.open("log", std::fstream::app);
    log_file << "ERROR: " << fmt << "\n";
    log_file.close();
}