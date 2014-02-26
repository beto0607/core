/* 
 * File:   Cargar.cpp
 * Author: Francisco
 * 
 * Created on 1 de diciembre de 2013, 18:25
 */

#include <Command/Cargar.h>
#include <Command/Command.h>
#include <iostream>

using namespace kaikai;

Cargar::Cargar() {
}

Cargar::~Cargar() {
}

void Cargar::execute()
{
    std::cout << "Cargar";
}