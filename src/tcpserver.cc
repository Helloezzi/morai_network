#include <iostream>
#include <cstring>

#include "util.cc"
#include "tcpserver.h"

namespace morainetwork {
TcpServer::TcpServer()
{
    m_port = 7788;
}

TcpServer::~TcpServer() {
    if (m_isRunnig) {
        stop();
    }
}

bool TcpServer::start(int port) 
{
    std::cout << "tcp server start" << std::endl;
    // open
    if (!m_socket.isOpen(port)) {
        std::cout << "tcp socket open error" << std::endl;
        return false;
    }

    std::cout << "open ok" << std::endl;

    // bind
    if (!m_socket.isBind()) {
        std::cout << "tcp socket bind error" << std::endl;
        return false;
    }

    std::cout << "bind ok" << std::endl;
    
    // listen
    if (!m_socket.isListen()) {
        std::cout << "tcp socket listen error" << std::endl;
        return false;
    }

    std::cout << "here " << std::endl;
    int szClientAddr = sizeof(m_clientAddr);
    m_clientSocket.socket = accept(m_socket.socket, (SOCKADDR*)&m_clientAddr, &szClientAddr);

    std::cout << "client accept " << std::endl;
    if (m_clientSocket.socket == -1)
        std::cout << "accept error" << std::endl;

    char message[256] = { "hello ezzi tcp" };
    //send(client_socket, message, sizeof(message), 0);
    std::cout << "listen ok" << std::endl;

    return true;
}

bool TcpServer::stop()
{
    m_isRunnig = false;

    #ifdef _WIN32
    closesocket(m_clientSocket.socket);
    WSACleanup();    
    #else
    close(m_socketServer);
    #endif    
    return true;
}

bool TcpServer::send(const char* msg, const int size)
{    
    ::send(m_clientSocket.socket, msg, size, 0);
    //m_socket.Send()
    return true;
}

/*
bool TcpServer::receive(const Socket &socket, char* msg, const int size) {
    int msg_size = 0;
    return true;
}
*/

//Socket* TcpServer::waitForConnect() {
    //return new Socket(socketClient);
//}

bool TcpServer::running() {
    return m_isRunnig;
}
}

