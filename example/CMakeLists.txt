SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(tcp_server tcp_server_example.cpp)
add_executable(udp_server udp_server_example.cpp)

target_link_libraries(tcp_server PUBLIC network)
target_link_libraries(udp_server PUBLIC network)

