// socketbase.h

#ifndef SOCKETBASE_H_
#define SOCKETBASE_H_

namespace morainetwork {
// interface socket
class SocketBase
{
    public:
        virtual ~SocketBase() {}
        virtual bool Open() = 0;
        virtual bool Close() = 0;
        virtual int Send(const char* msg, const int size) = 0;
        virtual int Receive(char* msg, const int size) = 0;
};
}

#endif // SOCKETBASE_H_