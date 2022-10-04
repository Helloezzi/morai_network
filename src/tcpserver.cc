#include <iostream>
#include <cstring>

#include "util.cpp"
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

bool TcpServer::start() 
{   
    printf("tcp server start");
    /*
    if (!m_socket.Open()) {
        std::cout << "socket open error" << std::endl;
        return false;
    }    

    //Load Winsock 2.2 DLL
    #ifdef _WIN32
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2,2), &wsadata) != 0)
        error_handling("WSAStartup() error!");
    #endif

    //m_socketServer = socket(PF_INET, SOCK_STREAM, 0);
    //if (m_socketServer == -1)
        //error_handling("socket() error!");
    
    memset(&m_socket.m_serverAddr, 0, sizeof(m_socket.m_serverAddr));    

    m_socket.m_serverAddr.sin_family = AF_INET;
    #ifdef _WIN32
    m_socket.m_serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    #else
    m_socket.m_serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    #endif  
    m_socket.m_serverAddr.sin_port = m_port;
    
    #ifdef _WIN32
    if (bind((TcpSocket)m_socket, (SOCKADDR*)&m_serverAddr, sizeof(m_serverAddr)) == -1)
        error_handling("bind() error!");
    #else
    if (bind(m_socketServer, (struct sockaddr*)&m_serverAddr, sizeof(m_serverAddr)) == -1)
        error_handling("bind() error!");
    #endif
    
    if (listen(m_socketServer, 5) == -1)
        error_handling("listen() error!");
    */

    return true;
}

bool TcpServer::stop()
{
    m_isRunnig = false;

    #ifdef _WIN32
    //closesocket(m_socketServer);
    //WSACleanup();
    //m_socket.Close();
    #else
    //close(m_socketServer);
    #endif
    
    return true;
}

bool TcpServer::send(const Socket &id, const char* msg, const int size)
{
    //m_socket.Send()

    return true;
}

bool TcpServer::receive(const Socket &socket, char* msg, const int size) {
    int msg_size = 0;
    return true;
}

//Socket* TcpServer::waitForConnect() {
    //return new Socket(socketClient);
//}

bool TcpServer::running() {
    return m_isRunnig;
}
}

