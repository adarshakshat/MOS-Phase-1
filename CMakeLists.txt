cmake_minimum_required(VERSION 3.19)
project(phase1)

set(CMAKE_CXX_STANDARD 14)

add_executable(phase1 main.cpp Storage.cpp Storage.h VirtualMachine.cpp VirtualMachine.h global.h)