#include "C:\Users\oli\CLionProjects\OOPLab_712_1\Lab5_OOP_fixed\Lab5_OOP\Authentificator_Product_User/ProductValidator.h"
#include <iostream>

void runProductValidationTests() {
    try {
        ProductValidator::validate("P123", 10.0, 5);
        std::cout << "Test 1 passed\n";
    } catch (...) {
        std::cout << "Test 1 failed\n";
    }

    try {
        ProductValidator::validate("", 10.0, 5);
        std::cout << "Test 2 failed\n";
    } catch (...) {
        std::cout << "Test 2 passed\n";
    }

    try {
        ProductValidator::validate("P*#12", 10.0, 5);
        std::cout << "Test 3 failed\n";
    } catch (...) {
        std::cout << "Test 3 passed\n";
    }
}