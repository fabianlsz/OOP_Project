cmake_minimum_required(VERSION 3.30)
project(OOP_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(Core)
include_directories(Repository)
include_directories(service)
include_directories(tests)
include_directories(Utilities)

add_executable(OOP_Project
    Core/Auth.cpp
    Core/Auth.h
    Core/Customer.cpp
    Core/Customer.h
        Core/User.cpp
    Core/User.h
        main.cpp)
