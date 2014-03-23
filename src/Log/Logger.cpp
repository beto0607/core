/* 
 * File:   Logger.cpp
 * Author: Francisco
 * 
 * Created on 10 de noviembre de 2013, 11:13
 */

#include <Log/Logger.h>
#include <iostream>
#include <string>

using namespace kaikai;

Logger::Logger() {
    creation_file.open("Log/creation_log");
    creation_file.close();
    workflow_file.open("Log/workflow_log");
    workflow_file.close();
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
    creation_file.open("Log/creation_log", std::fstream::app);
    creation_file << "INFORMATION: " << fmt << "\n";
    creation_file.close();
}

GLvoid Logger::warnningLog(std::string fmt)
{
    creation_file.open("Log/creation_log", std::fstream::app);
    creation_file << "WARNING: " << fmt << "\n";
    creation_file.close();
}

GLvoid Logger::criticalLog(std::string fmt)
{
    creation_file.open("Log/creation_log", std::fstream::app);
    creation_file << "ERROR: " << fmt << "\n";
    creation_file.close();
}

GLvoid Logger::workFlowinfoLog(std::string fmt)
{
    workflow_file.open("Log/workflow_log", std::fstream::app);
    workflow_file << "INFORMATION: " << fmt << "\n";
    workflow_file.close();
}

GLvoid Logger::workFlowwarnningLog(std::string fmt)
{
    workflow_file.open("Log/workflow_log", std::fstream::app);
    workflow_file << "WARNING: " << fmt << "\n";
    workflow_file.close();
}

GLvoid Logger::workFlowcriticalLog(std::string fmt)
{
    workflow_file.open("Log/workflow_log", std::fstream::app);
    workflow_file << "ERROR: " << fmt << "\n";
    workflow_file.close();
}