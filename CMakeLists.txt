cmake_minimum_required(VERSION 3.30)
project(Lab5_OOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(tests
        tests_main.cpp
        Authentication.cpp
        ProductValidator.cpp
        StartDataB.cpp
        TestProductValidation.cpp
        User.cpp
)

add_executable(OOP_Project
        Core/Auth.cpp
        Core/Auth.h
        Core/Customer.cpp
        Core/Customer.h
        Core/User.cpp
        Core/User.h
        main.cpp)