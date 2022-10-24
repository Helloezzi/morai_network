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

// socket interface
namespace morainetwork {	
	// Socket class
	class ISocket
	{		
	public:
		virtual ~ISocket() {}
		//bool OnClose();
		virtual bool isOpen(int port) = 0;
		virtual bool isBind() = 0;
		virtual bool isListen() = 0;
		//virtual int Send(SOCKET client, const char* msg, const int size) = 0;
		//virtual int Receive(char* msg, const int size) = 0;	
#ifdef _WIN32
		SOCKET socket;
#else
		int socket;
#endif
	};
}

#endif	// SOCKET_H_