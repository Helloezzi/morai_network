#pragma once

#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#ifdef _WIN32
#else
#include <arpa/inet.h>
#endif

namespace Morai_Net_tcp {
    class tcp_server
    {
    private:
    #ifdef _WIN32
    #else    
        sockaddr_in m_server;
    #endif
        tcpsocket_t m_socketServer;
        bool m_isRunnig;
    public:
        tcp_server(/* args */);
        ~tcp_server();

        bool start(const unsigned int port);
        bool start(const unsigned int port, const unsigned int maxClients);

    };
}

#endif // TCP_SERVER_H