#pragma once

#include <stdio.h>
#include <stdlib.h>

void function1()
{
    printf("test functions1");
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}