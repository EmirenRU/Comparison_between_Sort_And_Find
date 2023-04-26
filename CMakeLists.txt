cmake_minimum_required(VERSION 3.22)
project(SortAndFind)

set(CMAKE_CXX_STANDARD 14)

add_executable(SortAndFind src/main/main.cpp src/Double_Linked_List/Lists.cpp src/Double_Linked_List/Lists.h src/Emulator/Controller.h src/Emulator/Controller.cpp src/Double_Linked_List/Node.h)
