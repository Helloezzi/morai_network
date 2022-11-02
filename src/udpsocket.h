#ifndef	UDPSOCKET_H_
#define	UDPSOCKET_H_

#include "socket.h"

namespace morainetwork {
class UdpSocket : public ISocket
{
public:
    UdpSocket();
    ~UdpSocket();
    bool Open(char* port);
    void Close();
public:
    #ifdef _WIN32
    SOCKADDR_IN m_serverAddr;
    #else
    struct sockaddr_in m_serverAddr;
    #endif
};
}

#endif // UDPSOCKET_H_