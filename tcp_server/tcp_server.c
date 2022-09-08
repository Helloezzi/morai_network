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
#endif

void error_handling(char *message);

int main(int argc, char **argv)
{
    printf("tcp server start\n");

    WSADATA wsadata;
    
    SOCKET server_socket;
    SOCKET client_socket;    
    SOCKADDR_IN serverAddr;
    SOCKADDR_IN clientAddr;

    int szClientAddr;
    char message[] = "Hello world\n";

    if (argc != 2){
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    /* Load Winsock 2.2 DLL */
    if (WSAStartup(MAKEWORD(2,2), &wsadata) != 0)
        error_handling("WSAStartup() error!");

    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket == INVALID_SOCKET)
        error_handling("socket() error!");
    
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(atoi(argv[1]));
    
    if (bind(server_socket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
        error_handling("bind() error!");
    
    if (listen(server_socket, 5)==SOCKET_ERROR)
        error_handling("listen() error!");
    
    szClientAddr = sizeof(clientAddr);
    client_socket = accept(server_socket, (SOCKADDR*)&clientAddr, &szClientAddr);

    if (client_socket == INVALID_SOCKET)
        error_handling("accept() error!");
    
    send(client_socket, message, sizeof(message), 0);

    closesocket(client_socket);
    WSACleanup();

    printf("terminate test program");

    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
