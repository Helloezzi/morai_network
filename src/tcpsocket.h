
#ifndef	TCPSOCKET_H_
#define	TCPSOCKET_H_

#include "socket.h"

namespace morainetwork {
class TcpSocket : public ISocket
{
public:
    TcpSocket();
    ~TcpSocket();
    bool isOpen(int port);
    bool isBind();
    bool isListen();
    //int Send(SOCKET client, const char* msg, const int size);
	//virtual int Receive(char* msg, const int size);
public:
    #ifdef _WIN32
    SOCKADDR_IN m_serverAddr;
    #else
    struct sockaddr_in m_serverAddr;
    #endif
};
}

#endif // TCPSOCKET_H_