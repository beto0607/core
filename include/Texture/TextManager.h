/* 
 * File:   TextManager.h
 * Author: fran
 *
 * Created on February 1, 2014, 1:31 PM
 */

#ifndef TEXTMANAGER_H
#define	TEXTMANAGER_H

#include "../Unnivelmas_conf.h"
#include <map>
#include <string>

namespace unnivelmas
{
    class Font;
    
    class TextManager {
    public:
        TextManager();
        virtual ~TextManager();
    private:
        std::map<std::string, Font*> fonts;
    };
}
#endif	/* TEXTMANAGER_H */

