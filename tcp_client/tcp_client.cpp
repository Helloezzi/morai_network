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
    int sock;
    struct sockaddr_in server_addr;
    char message[30];
    int str_len;

    if (argc != 3)
    {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket() error");
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    #ifdef _WIN32
    server_addr.sin_addr.S_un.S_addr = inet_addr(argv[1]);    
    #else
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    #endif
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
        error_handling("connect() error");
    
    #ifdef _WIN32
    #else
    str_len = read(sock, message, sizeof(message)-1);
    #endif
    if (str_len == -1)
        error_handling("read() error!");
    
    message[str_len] = 0;
    printf("Message from server : %s \n", message);

    #ifdef _WIN32
    #else
    close(sock);
    #endif
    
    return 0;
}