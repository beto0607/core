/* 
 * File:   TextManager.cpp
 * Author: fran
 * 
 * Created on February 1, 2014, 1:31 PM
 */

#include <Texture/TextManager.h>

using namespace unnivelmas;

TextManager::TextManager() {
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
}

TextManager::~TextManager() {
}

