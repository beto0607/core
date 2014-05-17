/* 
 * File:   LoadScene.cpp
 * Author: beto0607
 * 
 * Created on 17 de mayo de 2014, 18:43
 */

#include <Command/LoadScene.h>
#include <string>
#include <Command/Command.h>
#include <Core/Core.h>
#include <Core/Clock.h>
#include <iostream>

using namespace kaikai;

LoadScene::LoadScene() {
}

LoadScene::~LoadScene() {
}

void LoadScene::execute(){
    char* name;
    std::cin >> name; 
    Core::getInstance()->loadScene(name);
    std::cout<<"Scene Loaded.\n";
}