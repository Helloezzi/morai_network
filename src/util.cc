#pragma once

#include "util.h"
/*
void error_handling(const char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}*/

namespace morainetwork {
    void Util::Log(const char* msg)
    {
        // something code
        std::cout << msg << std::endl;
    }
}

