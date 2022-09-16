cmake_minimum_required(VERSION 3.0.0)
project(tcp_client VERSION 0.1.0)

#add_executable(tcp_client.exe tcp_client.cpp)
add_library(tcp_client.so tcp_client.cpp)