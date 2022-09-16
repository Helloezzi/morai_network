cmake_minimum_required(VERSION 3.0.0)
project(tcp_server_example VERSION 0.1.0)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(TcpServerExample.exe tcp_server_example.cpp)