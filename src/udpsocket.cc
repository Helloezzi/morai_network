
#include "udpsocket.h"
#include <iostream>

namespace morainetwork {
    UdpSocket::UdpSocket() {        
    }

    UdpSocket::~UdpSocket() {
    }

    bool UdpSocket::Open(char* port)
    {    
        #ifdef _WIN32
        WSADATA wsadata;
        if (WSAStartup(MAKEWORD(2,2), &wsadata) != 0)
            std::cout << "WSAStartip error" << std::endl;
        #else    
        #endif

        // socket open
        socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
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
        short s_port = 61557;
        m_serverAddr.sin_port = htons(s_port);
        std::cout << "s_port :  " << s_port << std::endl;
        std::cout << "sin port :  " << m_serverAddr.sin_port << std::endl;
            
        return true;
    } 

    void UdpSocket::Close()
    {
        std::cout << "socket close" << std::endl;
    }
}



