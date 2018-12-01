cmake_minimum_required(VERSION 2.6)
project(algrim)

add_executable(algrim main.cpp)

install(TARGETS algrim RUNTIME DESTINATION bin)
