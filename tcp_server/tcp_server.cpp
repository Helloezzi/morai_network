/*
helloworld_server.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#endif

#include "util.cpp"

int main(int argc, char **argv)
{
    printf("tcp server start\n");

#ifdef _WIN32
    WSADATA wsadata;    
    SOCKET server_socket;
    SOCKET client_socket;    
    SOCKADDR_IN serverAddr;
    SOCKADDR_IN clientAddr;
#else
    int server_socket;
    int client_socket;
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
#endif 

    int szClientAddr;
    char message[] = "Hello world\n";

    if (argc != 2){
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    /* Load Winsock 2.2 DLL */
    #ifdef _WIN32
    if (WSAStartup(MAKEWORD(2,2), &wsadata) != 0)
        error_handling("WSAStartup() error!");
    #endif

    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
        error_handling("socket() error!");
    
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    #ifdef _WIN32
    serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    #else
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    #endif  
    serverAddr.sin_port = htons(atoi(argv[1]));    
    
    #ifdef _WIN32
    if (bind(server_socket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == -1)
        error_handling("bind() error!");
    #else
    if (bind(server_socket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1)
        error_handling("bind() error!");
    #endif
    
    if (listen(server_socket, 5) == -1)
        error_handling("listen() error!");
    
    szClientAddr = sizeof(clientAddr);

    #ifdef _WIN32
    client_socket = accept(server_socket, (SOCKADDR*)&clientAddr, &szClientAddr);
    #else
    client_socket = accept(server_socket, (struct sockaddr*)&clientAddr, &szClientAddr);
    #endif

    if (client_socket == -1)
        error_handling("accept() error!");
    
    send(client_socket, message, sizeof(message), 0);

    #ifdef _WIN32
    closesocket(client_socket);
    WSACleanup();
    #else
    close(client_socket);
    #endif  
    
    printf("terminate test program");
    return 0;
}