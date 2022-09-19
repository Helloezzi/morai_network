
#ifndef	TCPSOCKET_H_
#define	TCPSOCKET_H_

#include "socket.h"

namespace morainetwork {
class TcpSocket : public Socket
{
public:
    TcpSocket();
    ~TcpSocket();
    virtual bool Open();
    virtual int Send(const char* msg, const int size);
	virtual int Receive(char* msg, const int size);
public:
    #ifdef _WIN32
    SOCKADDR_IN m_serverAddr;
    #else
    sockaddr_in m_serverAddr;
    #endif
};
}

#endif // TCPSOCKET_H_