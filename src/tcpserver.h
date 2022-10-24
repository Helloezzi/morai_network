#pragma once

#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include "tcpsocket.h"

namespace morainetwork {
class TcpServer
{
private:
    int m_port;
    bool m_isRunnig;
    TcpSocket m_clientSocket;
    SOCKADDR_IN m_clientAddr;
public:
    TcpServer();
    ~TcpServer();
    
    TcpSocket m_socket;

    bool start(int port);
    bool stop();
    bool send(const char* msg, const int size);
    //bool receive(const Socket &id, char* msg, const int size);
    //Socket* waitForConnect();
    
    bool running();
};
#endif // TCP_SERVER_H
}