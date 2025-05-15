cmake_minimum_required(VERSION 3.30)
project(Lab_OOP_grupa_X)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab_OOP_grupa_X RunTests.cpp Product.cpp ProductRepository.cpp ProductValidator.cpp TestProduct.cpp ProfileManager.cpp)
