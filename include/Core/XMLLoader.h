/* 
 * File:   XMLLoader.h
 * Author: beto0607
 *
 * Created on 16 de mayo de 2014, 15:51
 */

#ifndef XMLLOADER_H
#define	XMLLOADER_H

#include "../Unnivelmas_conf.h"
#include <map>
#include <string>
#include <External/tinyxml2.h>
#include <Scene/Scene.h>

namespace kaikai{
    class XMLLoader {
        public:
            XMLLoader();
            XMLLoader(const char *);
            virtual ~XMLLoader();
            void setFile(const char *);
            float getFloat(const char *);
            int getInt(const char *);
            const char* getString(const char *);
            void saveScene(const char * _file, Scene* _scene);
            void loadScene(const char * _file, Scene* _scene);
        private:
            const char * file;
            std::map<std::string,std::string> data;
            void load();
        };
}
#endif	/* XMLLOADER_H */

