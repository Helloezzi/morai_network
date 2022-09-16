cmake_minimum_required(VERSION 3.0.0)
project(tcp_server VERSION 0.1.0)

add_library(tcp_server.so tcp_server.cpp)
# add_executable(tcp_server.exe tcp_server.cpp)
