#pragma once

#include <iostream>
#include <thread>
#include <cstring>
#include <memory>

#include "define.h"
#include "../src/tcpserver.h"
//#include "../src/util.cc"
#include "../src/util.h"

using namespace morainetwork;

int main(int argc, const char* argv[])
{
    Util::Log("test message");

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(BUFFER_SIZE));

    TcpServer server;
    if (server.start(7789)) {
        std::cout << "server started " << std::endl;
    }

    std::cout << "please enter any message" << std::endl;
    char input[256];
    while(1)
    {        
        memset(input, 0, 256);
        std::cout << ">> ";
        std::cin >> input;
        server.send(input, sizeof(input));        
    }

    server.stop();
    return 0;

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
   
}