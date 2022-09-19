SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(tcp_server.exe tcp_server_example.cpp)

target_link_libraries(tcp_server.exe PUBLIC network.so)

