cmake_minimum_required(VERSION 3.0.0)
project(network_c VERSION 0.1.0)

add_library(network SHARED tcp_server.cpp tcp_client.cpp)
