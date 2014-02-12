/* 
 * File:   Salir.cpp
 * Author: francisco
 * 
 * Created on 7 de enero de 2014, 21:14
 */

#include <Command/Command.h>
#include <Command/Salir.h>
#include <Core/Core.h>

using namespace unnivelmas;

Salir::Salir() {
}

Salir::~Salir() {
}

GLvoid Salir::execute()
{
    Core::getInstance()->~Core();
}