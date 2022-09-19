#pragma once

#include "socket.h"

namespace morainetwork {
Socket::~Socket() {
	Close();
}

bool Socket::Close() {
	#ifdef _WIN32
	if (::closesocket(m_socket) < 0) {
		return false;
	}
	WSACleanup();
    #else
    if (::close(m_socket) < 0) {
		return false;
	}
    #endif
	return true;
}
}


