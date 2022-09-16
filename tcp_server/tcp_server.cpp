
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
    if (::setsockopt(m_socketServer.toImple<int>(), SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &1, sizeof(int)) < 0) {
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

bool tcp_server::receive(const Socket &id, const char* msg, const int size) {
    if (id.receive(msg, size) < 0) {
        return false;
    }
    return true;
}

Socket* tcp_server::waitForConnect() {
    int socketClient = -1;
    sockaddr_in clientAddr;
    socklen_t length = sizeof(sockaddr_in);
    socketClient = ::accept(m_socketServer.toImpl<int>(), 
            reinterpret_cast<sockaddr*>(&clientAddr), static_cast<socklen_t*>(&length);
    if (socketClient > 0) {
        std::cout << "New client connected" << std::endl;
    }
    return new Socket(socketClient);
}

bool tcp_server::running() {
    return m_isRunnig;
}