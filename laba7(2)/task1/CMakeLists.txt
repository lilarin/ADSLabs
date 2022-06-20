cmake_minimum_required(VERSION 3.20)
project(task1)

set(CMAKE_CXX_STANDARD 17)

add_executable(task1 main.cpp HashList.cpp HashList.h HashTable_Separate_Chaining.cpp HashTable_Separate_Chaining.h HashTable_Linear_Probing.cpp HashTable_Linear_Probing.h)
