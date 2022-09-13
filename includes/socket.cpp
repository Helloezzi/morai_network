#include <unistd.h>	
#include <sys/socket.h>	
#include <arpa/inet.h>

#include "socket.h"

namespace Morai_Net {
	Socket::Socket()
		: unixSocket(-1) {}

	Socket::~Socket() {
		close();
	}

	bool Socket::open() {
		if ((unixSocket = ::socket(AF_INET, SOCK_STREAM, 0)) < 0) {
			return false;
		}
		return true;
	}

	bool Socket::close() {
		if (::close(unixSocket) < 0) {
			return false;
		}
		return true;
	}

	int Socket::send(const char* msg, const int size) const {
		return ::write(unixSocket, msg, size);
	}

	int Socket::receive(char* msg, const int size) const {
		return ::read(unixSocket, msg, size);
	}
}


