#find_package(Check REQUIRED)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(program.exe tcp_server_example.cpp)

target_link_libraries(program.exe PUBLIC network)

