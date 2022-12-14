#pragma once

#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include "tcpsocket.h"

namespace morainetwork {
class TcpServer : private IServer
{
private:
    int m_port;
    bool m_isRunnig;
    TcpSocket m_clientSocket;
    SOCKADDR_IN m_clientAddr;
    bool Bind();
    bool Listen();    
public:
    TcpServer();
    ~TcpServer();
    
    TcpSocket m_tcp_socket;

    bool start(char* port);
    bool stop();
    bool send(const char* msg, const int size);
    //bool receive(const Socket &id, char* msg, const int size);
    //Socket* waitForConnect();    
    bool IsRunning();
};
#endif // TCP_SERVER_H
}