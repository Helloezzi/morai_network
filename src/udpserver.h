#pragma once

#ifndef UDP_SERVER_H
#define UDP_SERVER_H

#include "udpsocket.h"

namespace morainetwork {
class UdpServer : private IServer
{
private:
    int m_port;
    bool m_isRunnig;
    UdpSocket m_clientSocket;
    SOCKADDR_IN m_clientAddr;
    bool Bind();
    bool Listen();    
public:
    UdpServer();
    ~UdpServer();
    
    UdpSocket m_udp_socket;

    bool Start(char* port);
    bool Stop();
    bool Send(const char* msg, const int size, SOCKADDR_IN clientaddrin);
    //bool receive(const Socket &id, char* msg, const int size);
    //Socket* waitForConnect();    
    bool IsRunning();
};
#endif // UDP_SERVER_H
}