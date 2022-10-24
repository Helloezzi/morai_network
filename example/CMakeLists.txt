SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(tcp_server tcp_server_example.cpp)
add_executable(tcpclient tcpclient.cpp)
add_executable(tcpserver_test tcpserver_test.cpp)

target_link_libraries(tcp_server PUBLIC network)

