#include <iostream>
#include <cstring>

#include "tcp_server.h"

tcp_server::tcp_server() : 
    m_server(), 
    m_socketServer(), 
    m_isRunnig(false) {
        m_port = 7788;
}

tcp_server::tcp_server(const unsigned int port) : 
    m_server(),
    m_socketServer(),
    m_isRunnig(false) {
        m_port = port;
    }

tcp_server::~tcp_server() {
    if (m_isRunnig) {
        stop();
    }
}

bool tcp_server::start() {        

    int maxClient = 10;

    // create tcp socket
    if (!m_socketServer.open()) {
        return false;
    }

    // Enable multiclient connect
    int multiclient = 1;
    if (::setsockopt(m_socketServer.toImpl<int>(), SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
         &multiclient, sizeof(int)) < 0) {
        return false;
    }
    
    memset(&m_server, 0, sizeof(sockaddr_in));
    m_server.sin_family = AF_INET;
    m_server.sin_addr.s_addr = INADDR_ANY;
    m_server.sin_port = htons(m_port);

    if (::listen(m_socketServer.toImpl<int>(), maxClient) < 0) {
        return false;
    }
    m_isRunnig = true;
    return true;
}

bool tcp_server::stop()
{
    m_isRunnig = false;
    if (!m_socketServer.close()) {
        return false;
    }
    return true;
}

bool tcp_server::send(const Socket &id, const char* msg, const int size)
{
    if (id.send(msg, size) < 0) {
        return false;
    }
    return true;
}

bool tcp_server::receive(const Socket &socket, char* msg, const int size) {
    int msg_size = 0;
    if ((msg_size = socket.receive(msg, size)) < 0) {
        return false;
    }
    else if (msg_size == 0)
    {
        // no client
        return false;
    }
    return true;
}

Socket* tcp_server::waitForConnect() {
    int socketClient = -1;
    sockaddr_in clientAddr;
    socklen_t length = sizeof(sockaddr_in);

    int temp = ::accept(m_socketServer.toImpl<int>(), reinterpret_cast<sockaddr*>(&clientAddr), static_cast<socklen_t*>(&length));
    if (socketClient = temp) {
        std::cout << "New client connected" << std::endl;
    }
    return new Socket(socketClient);
}

bool tcp_server::running() {
    return m_isRunnig;
}