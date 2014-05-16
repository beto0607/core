/* 
 * File:   SaveScene.cpp
 * Author: beto0607
 * 
 * Created on 16 de mayo de 2014, 17:09
 */

#include <Command/SaveScene.h>
#include <string>
#include <Command/Command.h>
#include <Core/Core.h>
#include <Core/Clock.h>
#include <iostream>

using namespace kaikai;

SaveScene::SaveScene():Command() {
}


SaveScene::~SaveScene() {
}

GLvoid SaveScene::execute(){
    char* name;
    std::cin >> name; 
    Core::getInstance()->saveScene(name);
    std::cout<<"Scene saved.\n";
}
