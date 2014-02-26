/* 
 * File:   Conection.cpp
 * Author: francisco
 * 
 * Created on 23 de enero de 2014, 19:23
 */

#include <Networking/Conection.h>
#include <Log/Logger.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace kaikai;

Conection::Conection() {
    if (!(packet = SDLNet_AllocPacket(64)))
    {
        std::stringstream number;
        number << "SDLNet_AllocPacket: " << SDLNet_GetError();
        (Logger::getInstance())->warnningLog(number.str().c_str());
    }
}

Conection::~Conection() {
    SDLNet_FreePacket(packet);
}

int listen_port(void* ptr)
{
    GLboolean resu = true;
    Conection* con = (Conection*) ptr;
    while(resu)
    {
        if (SDLNet_UDP_Recv(con->getSocket(), con->getPacket()))
        {
                std::cout << "Entro: " << con->getPacket()->data <<"\n";
        }
    }
    return 15;
}

GLvoid Conection::openServerSocket(GLint _port)
{
    udpsock=SDLNet_UDP_Open(_port);
    if(!udpsock) {
        std::string mesage = std::string("SDLNet_UDP_Open: ");
        mesage.append(SDLNet_GetError());
        (Logger::getInstance())->warnningLog(mesage.c_str());
    }
    else
    {
        std::stringstream number;
        number << "Socket UDP open - Port: " <<_port;
        (Logger::getInstance())->infoLog(number.str().c_str());
    }
    SDL_Thread* socket_thread   = SDL_CreateThread(listen_port,"socket",(void*)this);
}

GLvoid Conection::openClientSocket(GLint _port,const GLchar* _ipserver)
{
    udpsock=SDLNet_UDP_Open(0);
    if(!udpsock) {
        std::string mesage = std::string("SDLNet_UDP_Open: ");
        mesage.append(SDLNet_GetError());
        (Logger::getInstance())->warnningLog(mesage.c_str());
    }
    if (SDLNet_ResolveHost(&address, _ipserver, _port) == -1)
    {
        std::stringstream number;
        number << "Socket UDP Fail: " << SDLNet_GetError();
        (Logger::getInstance())->infoLog(number.str().c_str());
    }
    packet->address.host = address.host;
    packet->address.port = address.port;
}

GLvoid Conection::sendData(GLbyte _data)
{
    packet->len = sizeof(_data) + 1;
    packet->data = (Uint8*)&_data;
    SDLNet_UDP_Send(udpsock, -1, packet);
}

UDPsocket Conection::getSocket()
{
    return this->udpsock;
}

UDPpacket* Conection::getPacket()
{
    return this->packet;
}