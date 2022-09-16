#pragma once

#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#ifdef _WIN32
#else
#include <arpa/inet.h>
#endif

#include "socket.h"

class tcp_server
{
private:
    int m_port;
    sockaddr_in m_server;
    Socket m_socketServer;
    bool m_isRunnig;
public:
    tcp_server();
    tcp_server(const unsigned int port);
    ~tcp_server();

    bool start();
    bool stop();

    bool send(const Socket &id, const char* msg, const int size);
    bool receive(const Socket &id, const char* msg, const int size);

    Socket* waitForConnect();
    bool running();
};

#endif // TCP_SERVER_H