/* 
 * File:   MostrarFPS.cpp
 * Author: francisco
 * 
 * Created on 7 de enero de 2014, 21:35
 */

#include <Command/Command.h>
#include <Command/MostrarFPS.h>
#include <Core/Core.h>
#include <Core/Clock.h>

using namespace kaikai;

MostrarFPS::MostrarFPS() {
}

MostrarFPS::~MostrarFPS() {
}

GLvoid MostrarFPS::execute()
{
    (Core::getInstance())->getClock()->showFPS();
}

