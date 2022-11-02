#include <iostream>
#include <cstring>

#include "util.cc"
#include "udpserver.h"

namespace morainetwork {
UdpServer::UdpServer()
{
    m_port = 7788;
}

UdpServer::~UdpServer() {
    if (m_isRunnig) {
        Stop();
    }
}

bool UdpServer::Bind()
{
    #ifdef _WIN32
    if (::bind(m_udp_socket.socket, (struct sockaddr*)&m_udp_socket.m_serverAddr, sizeof(m_udp_socket.m_serverAddr)) == -1)
        return false;
    #else
    if (bind(m_socketServer, (struct sockaddr*)&m_serverAddr, sizeof(m_serverAddr)) == -1)
        return false;
    #endif

    std::cout << "socket bind" << std::endl;
    return true;
}

bool UdpServer::Listen()
{
    if (::listen(m_udp_socket.socket, 5) == -1)
        return false;
    std::cout << "socket listen" << std::endl;
}

bool UdpServer::Start(char* port) 
{
    std::cout << "udp server start" << std::endl;
    // open
    if (!m_udp_socket.Open(port)) {
        std::cout << "udp socket open error" << std::endl;
        return false;
    }

    std::cout << "open ok" << std::endl;

    // bind
/*     if (!Bind()) {
        std::cout << "udp socket bind error" << std::endl;
        return false;
    }

    std::cout << "bind ok" << std::endl; */
    
    // listen
    /* if (!Listen()) {
        std::cout << "udp socket listen error" << std::endl;
        return false;
    } */

/*     std::cout << "here " << std::endl;
    int szClientAddr = sizeof(m_clientAddr);
    m_clientSocket.socket = accept(m_udp_socket.socket, (SOCKADDR*)&m_clientAddr, &szClientAddr);    

    std::cout << "client accept " << std::endl;
    if (m_clientSocket.socket == -1)
        std::cout << "accept error" << std::endl;

    char message[256] = { "hello ezzi tcp" };
    //send(client_socket, message, sizeof(message), 0);
    std::cout << "listen ok" << std::endl; */

    return true;
}

bool UdpServer::Stop()
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

bool UdpServer::Send(const char* msg, const int size, SOCKADDR_IN clientaddrin)
{    
    //::send(m_clientSocket.socket, msg, size, 0);
    //memset(&m_clientAddr, 0, sizeof(m_clientAddr));

    ::sendto(m_udp_socket.socket, msg, size, 0, (struct sockaddr*)&clientaddrin, sizeof(clientaddrin));
    //m_socket.Send()
    return true;
}

bool UdpServer::IsRunning() {
    return m_isRunnig;
}
}

