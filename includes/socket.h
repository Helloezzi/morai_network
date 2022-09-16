#pragma	once

#ifndef	__SOCKET_H__
#define	__SOCKET_H__

// Socket class
class Socket {
	int	unixSocket;		// Unix socket handle type

public:
	Socket();
	template<typename T>
	explicit Socket(T&);
	~Socket();

	bool	open();
	bool	close();
	int	send(const char* msg, const int size) const;
	int	receive(char* msg, const int size) const;

	template<typename T>
	void	fromImpl(T&);
	template<typename T>
	T&	toImpl();
};

template<typename T>
Socket::Socket(T &soc) {
	fromImpl<T>(soc);
}

template<typename T>
void Socket::fromImpl(T &soc) {
	unixSocket = static_cast<int>(soc);
}

template<typename T>
T& Socket::toImpl() {
	return static_cast<T&>(unixSocket);
}
#endif	// __SOCKET_H__