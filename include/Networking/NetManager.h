/* 
 * File:   NetManager.h
 * Author: francisco
 *
 * Created on 23 de enero de 2014, 19:19
 */

#ifndef NETMANAGER_H
#define	NETMANAGER_H

#include "../Unnivelmas_conf.h"
#include <map>
#include <string>

namespace kaikai
{
    class Conection;
    
    class NetManager {
    public:
        NetManager();
        virtual ~NetManager();
 
    private:
        std::map<std::string,Conection*> conections;
    };
}
#endif	/* NETMANAGER_H */

