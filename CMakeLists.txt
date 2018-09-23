cmake_minimum_required(VERSION 3.12)
project(algoBowl)

set(CMAKE_CXX_STANDARD 14)

add_executable(algoBowl main.cpp Task.cpp Task.h Workstation.cpp Workstation.h InputImporter.cpp InputImporter.h)