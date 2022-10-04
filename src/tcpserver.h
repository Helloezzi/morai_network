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
public:
    TcpServer();
    ~TcpServer();
    
    TcpSocket m_socket;

    bool start();
    bool stop();
    bool send(const Socket &id, const char* msg, const int size);
    bool receive(const Socket &id, char* msg, const int size);
    //Socket* waitForConnect();
    
    bool running();
};
#endif // TCP_SERVER_H
}