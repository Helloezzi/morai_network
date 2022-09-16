cmake_minimum_required(VERSION 3.0.0)

set(TCP_EXAMPLE "1.0.0" CACHE STRING "TCP Example")

include_directories(includes)
add_subdirectory(tcp_server)
add_subdirectory(tcp_client)
add_subdirectory(example)