/* 
 * File:   TextManager.cpp
 * Author: fran
 * 
 * Created on February 1, 2014, 1:31 PM
 */

#include <Texture/TextManager.h>
#include <Log/Logger.h>

using namespace kaikai;

TextManager::TextManager() {
    if(TTF_Init()==-1) {
        std::string mesage = std::string("TextManager has a problem: ");
        mesage.append(TTF_GetError());
        (Logger::getInstance())->criticalLog(mesage.c_str());
        exit(2);
    }
    (Logger::getInstance())->infoLog("TextManager was load Susefully");
}

TextManager::~TextManager() {
}

