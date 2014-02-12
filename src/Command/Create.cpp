/* 
 * File:   Create.cpp
 * Author: francisco
 * 
 * Created on 7 de enero de 2014, 21:58
 */

#include <Command/Command.h>
#include <Command/Create.h>
#include <Command/RectangleCommand.h>
#include <Core/Core.h>
#include <iostream>
#include <string>
#include <map>

using namespace unnivelmas;

Create::Create():Command(){
    functions.insert(std::pair<std::string,Command*>("rectangle", new RectangleCommand()));
}

Create::~Create() {
}

GLvoid Create::execute()
{
    std::string figure;
    std::cin >> figure; 
    if(functions.find(figure) == functions.end())
            std::cout << "Create Error: " << figure << " wasn't a function in create\n";
        else
            functions[figure]->execute();
}

