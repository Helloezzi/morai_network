cmake_minimum_required(VERSION 3.11)

project(Network VERSION 1.0.0)

#set(NETWORK "1.0.0" CACHE STRING "Network")

include_directories(includes)

add_subdirectory(test)
add_subdirectory(src)

