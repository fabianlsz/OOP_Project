cmake_minimum_required(VERSION 3.30)
project(Lab5_OOP)

set(CMAKE_CXX_STANDARD 20)

add_library(store_lib
        Controller/AuthenticationController.cpp
        Controller/AuthenticationController.h
        Domain/Customer.cpp
        Domain/Customer.h
        Domain/User.cpp
        Domain/User.h
        Authentificator_Product_User/Authentication.cpp
        Authentificator_Product_User/ProductValidator.cpp
        Authentificator_Product_User/StartDataB.cpp
        Authentificator_Product_User/User.cpp
)

add_executable(tests
        Tests/tests_main.cpp
        Tests/TestProductValidation.cpp
        Tests/AuthTests.cpp
)
target_link_libraries(tests store_lib)

add_executable(OOP_Project main.cpp)

target_link_libraries(OOP_Project store_lib)