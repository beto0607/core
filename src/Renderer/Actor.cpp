/* 
 * File:   Actor.cpp
 * Author: francisco
 * 
 * Created on 5 de marzo de 2014, 23:54
 */

#include <Renderer/Actor.h>
#include <iostream>
#include <fstream>

using namespace kaikai;

Actor::Actor(const GLchar* _filename) {
    std::ofstream myfile;
    myfile.open(_filename, std::ios::in);
    if(myfile.is_open())
    {
        std::cout << "abierto\n";
    }
    else
    {
        std::cout << "no abierto\n";
    }        
}

Actor::~Actor() {
}

GLvoid Actor::draw(Scene*)
{

}