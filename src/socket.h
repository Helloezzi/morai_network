// socket.h file
#ifndef	SOCKET_H_
#define	SOCKET_H_

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
		virtual bool Open(int port) = 0;
		virtual void Close();
	public:
#ifdef _WIN32
		SOCKET m_socket;
#else
		int m_socket;
#endif
	};

	class IServer
	{
		public:			
			virtual bool Bind() = 0;
			virtual bool Listen() = 0;
	};

	class IClient
	{
		public:
			virtual bool Connect() = 0;
			virtual bool Disconnect() = 0;
	};
}

#endif	// SOCKET_H_