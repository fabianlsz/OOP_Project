cmake_minimum_required(VERSION 3.30)
project(Lab5_OOP)

set(CMAKE_CXX_STANDARD 20)

add_library(store_lib
        Controller/AuthenticationController.cpp
        Controller/CustomerController.cpp
        Controller/CustomerController.h
        Controller/OrderService.cpp
        Controller/OrderService.h
        Domain/Customer.cpp
        Domain/Customer.h
        Domain/User.cpp
        Domain/User.h
        Domain/ProductValidator.cpp
        Domain/ProductValidator.h
        Domain/Product.cpp
        Domain/Product.h
        Domain/Order.cpp
        Domain/Order.h
        Repository/StartDataB.cpp
        Repository/StartDataB.h
)

add_executable(tests
        Tests/tests_main.cpp
        Tests/TestProductValidation.cpp
        Tests/AuthTests.cpp
)
target_link_libraries(tests store_lib)

add_executable(OOP_Project main.cpp)

target_link_libraries(OOP_Project store_lib)