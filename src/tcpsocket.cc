
#include "tcpsocket.h"

namespace morainetwork {
TcpSocket::TcpSocket()
{
}

TcpSocket::~TcpSocket()
{
}

bool TcpSocket::Open()
{
    if ((m_socket = ::socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return false;
	}
	return true;
}

int TcpSocket::Send(const char* msg, const int size)
{
}

int TcpSocket::Receive(char* msg, const int size)
{    
}
}


