/* 
 * File:   Conection.h
 * Author: francisco
 *
 * Created on 23 de enero de 2014, 19:23
 */

#ifndef CONECTION_H
#define	CONECTION_H

#include "../Unnivelmas_conf.h"

namespace kaikai
{
    class Conection {
    public:
        Conection();
        virtual ~Conection();
                
        GLvoid openServerSocket(GLint);
        GLvoid openClientSocket(GLint,const GLchar*);
        GLvoid sendData(GLbyte);
        
        UDPsocket getSocket();
        UDPpacket* getPacket();
    private:
        UDPsocket udpsock;
        UDPpacket* packet;
        IPaddress address;
    };
}
#endif	/* CONECTION_H */

