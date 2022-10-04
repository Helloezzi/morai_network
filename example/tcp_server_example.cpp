#include <iostream>
#include <thread>
#include <cstring>
#include <memory>

#include "define.h"
#include "../src/tcpserver.h"
//#include "../src/tcpsocket.h"

using namespace morainetwork;

int main(int argc, const char* argv[])
{
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(BUFFER_SIZE));
    printf("aaa");
    
    TcpServer server;
    if (server.start()) {
        std::cout << "server started " << std::endl;        
    }

    /*
    
    while(server.running()) {
        std::cout << "wait for connect" << std::endl;
        Socket* client = server.waitForConnect();

        std::thread t1 = std::thread(connectionHandler, std::ref(server), client);

        if (t1.joinable())

        {
            t1.detach();
        }
    }

    if (server.stop())
    {
        std::cout << "server stopped" << std::endl;
    }
    */

    return 0;
}