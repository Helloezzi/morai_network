// socket.h file
#pragma	once

#ifndef	SOCKET_H_
#define	SOCKET_H_

#include <iostream>

#ifdef _WIN32
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <unistd.h>	
#include <sys/socket.h>	
#include <arpa/inet.h>
#endif

namespace morainetwork {	
// Socket class
class Socket
{		
public:
	~Socket();
	virtual bool Open() = 0;
	bool Close() { std::cout << "socket close" << std::endl; return true; }
	virtual int Send(const char* msg, const int size) = 0;
	virtual int Receive(char* msg, const int size) = 0;
protected:
	int m_socket;	
};
}

#endif	// SOCKET_H_