/*
#pragma once

#include <iostream>
#include "socket.h"

namespace morainetwork {
	Socket::~Socket() {
		std::cout << "socket close" << std::endl;
	}
	
	bool Socket::OnClose() {
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
}*/


