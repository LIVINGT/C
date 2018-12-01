cmake_minimum_required(VERSION 2.6)
project(dada)

add_executable(dada main.cpp)

install(TARGETS dada RUNTIME DESTINATION bin)
