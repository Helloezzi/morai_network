#pragma once

#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#ifdef _WIN32
#else
#include <arpa/inet.h>
#endif

#include "socket.h"

namespace Morai_Net {
    class tcp_server
    {
    private:
        sockaddr_in m_server;
        Socket m_socketServer;
        bool m_isRunnig;
    public:
        tcp_server(/* args */);
        ~tcp_server();

        bool start(const unsigned int port);
        bool start(const unsigned int port, const unsigned int maxClients);

    };
}

#endif // TCP_SERVER_H