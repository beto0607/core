/* 
 * File:   Command.cpp
 * Author: Francisco
 * 
 * Created on 27 de octubre de 2013, 22:35
 */

#include <Command/CommandManager.h>
#include <Command/Command.h>
#include <Command/Escalar.h>
#include <Command/Cargar.h>
#include <Command/Move.h>
#include <Command/Salir.h>
#include <Command/SetFps.h>
#include <Command/MostrarFPS.h>
#include <Command/Create.h>
#include <Log/Logger.h>
#include <iostream>
#include <string>
#include <map>

using namespace unnivelmas;

CommandManager::CommandManager() {
    end_flag=true;
    commands.insert(std::pair<std::string,Command*>("cargar",new Cargar()));
    commands.insert(std::pair<std::string,Command*>("scale",new Escalar()));
    commands.insert(std::pair<std::string,Command*>("move",new Move()));
    commands.insert(std::pair<std::string,Command*>("exit",new Salir()));
    commands.insert(std::pair<std::string,Command*>("fps",new MostrarFPS()));
    commands.insert(std::pair<std::string,Command*>("create",new Create()));
    commands.insert(std::pair<std::string,Command*>("setfps",new SetFps()));
}

CommandManager::~CommandManager() {
    for(std::map<std::string, Command*>::iterator it = commands.begin();it!=commands.end();++it)
        it->second->~Command();
    Logger::getInstance()->infoLog("Command Manager shutdown...");
}

void CommandManager::waitForCommand()
{
    while(end_flag)
    {
        std::string command;
        std::cout << "Command: ";
        std::cin >> command;
        if(commands.find(command) == commands.end())
            std::cout << "Command " << command << " wasn't found\n";
        else
            commands[command]->execute();
    }
    std::cout << "Closing Command Console Manager\n";
}

void CommandManager::stop()
{
    end_flag = false;
}