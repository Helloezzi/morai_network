#include <iostream>
#include <thread>
#include <cstring>
#include <memory>

#include "define.h"
#include "../network/tcp_server.h"

void connectionHandler(tcp_server &server, Socket* id)
{

}

int main(int argc, const char* argv[])
{
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(BUFFER_SIZE));

    tcp_server server(PORT);

    if (server.start()) {
        std::cout << "server started " << std::endl;        
    }

    while(server.running()) {
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

    return 0;
}