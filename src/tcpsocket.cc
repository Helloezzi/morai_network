
#include "tcpsocket.h"

namespace morainetwork {
TcpSocket::TcpSocket() {        
}

TcpSocket::~TcpSocket() {
}

bool TcpSocket::isOpen(int port)
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

bool TcpSocket::isBind()
{
    #ifdef _WIN32
    if (bind(socket, (SOCKADDR*)&m_serverAddr, sizeof(m_serverAddr)) == -1)
        return false;
    #else
    if (bind(m_socketServer, (struct sockaddr*)&m_serverAddr, sizeof(m_serverAddr)) == -1)
        return false;
    #endif

    std::cout << "socket bind" << std::endl;
    return true;
}

bool TcpSocket::isListen()
{
    if (listen(socket, 5) == -1)
        return false;
    std::cout << "socket listen" << std::endl;
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



