
#include "tcpsocket.h"
#include <iostream>

namespace morainetwork {
TcpSocket::TcpSocket() {        
}

TcpSocket::~TcpSocket() {
}

bool TcpSocket::Open(int port)
{    
    #ifdef _WIN32
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2,2), &wsadata) != 0)
        std::cout << "WSAStartip error" << std::endl;
    #else    
    #endif

    // socket open
    socket = ::socket(PF_INET, SOCK_STREAM, 0);
    if (socket == -1) {
        return false;
	}
    std::cout << "tcp socket open <port> : " << port << std::endl;

    // addr settting
    memset(&m_serverAddr, 0, sizeof(m_serverAddr));
    m_serverAddr.sin_family = AF_INET;
    #ifdef _WIN32    
    m_serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    std::cout << "addr any : " << m_serverAddr.sin_addr.S_un.S_addr << std::endl;
    #else
    m_serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    #endif  
    m_serverAddr.sin_port = htons(port);
    std::cout << "port :  " << m_serverAddr.sin_port << std::endl;
        
	return true;
}

void TcpSocket::Close()
{
    std::cout << "socket close" << std::endl;
}

/*
int TcpSocket::Send(SOCKET client, const char* msg, const int size)
{
    ::send(client, msg, size, 0);
    printf("tcpsocket send");
    return 0;
}


int TcpSocket::Receive(char* msg, const int size)
{    
    printf("tcpsocket receive");
    return 0;
}
*/
}



