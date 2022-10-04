
#include "tcpsocket.h"

namespace morainetwork {
TcpSocket::TcpSocket() {
    std::cout << "tcpsocket() " << std::endl;
}

TcpSocket::~TcpSocket() {
    std::cout << "~tcpsocket()" << std::endl;
}

bool TcpSocket::Open()
{
    printf("open tcpsocket");

    if ((m_socket = ::socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return false;
	}
	return true;
}

int TcpSocket::Send(const char* msg, const int size)
{
    printf("tcpsocket send");
}

int TcpSocket::Receive(char* msg, const int size)
{    
    printf("tcpsocket receive");
}
}


