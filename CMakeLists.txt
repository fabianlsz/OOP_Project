cmake_minimum_required(VERSION 3.30)
project(Lab5_OOP)

set(CMAKE_CXX_STANDARD 20)

add_library(store_lib   Core/Auth.cpp
        Core/Auth.h
        Core/Customer.cpp
        Core/Customer.h
        Core/User.cpp
        Core/User.h
        Authentication.cpp
        ProductValidator.cpp
        StartDataB.cpp
        User.cpp
)

add_executable(tests
        tests_main.cpp
        TestProductValidation.cpp
)
target_link_libraries(tests store_lib)

add_executable(OOP_Project   main.cpp)
target_link_libraries(OOP_Project store_lib)