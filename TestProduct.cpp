#include "ProductValidator.h"
#include "ProductRepository.h"
#include <iostream>

void runProductTests() {
    ProductRepository repo;
    try {
        ProductValidator::validate("P123", 10.0, 3);
        repo.addProduct(Product("P123", "Schokolade", 10.0, 3));
        std::cout << "Test 1 OK\n";
    } catch (...) {
        std::cout << "Test 1 Fehler\n";
    }

    try {
        ProductValidator::validate("", 5.0, 1);
        std::cout << "Test 2 Fehler\n";
    } catch (...) {
        std::cout << "Test 2 OK\n";
    }

    auto list = repo.getAvailableSortedByPrice();
    for (const auto& p : list) {
        std::cout << "Produkt: " << p.name << ", Preis: " << p.preis << "\n";
    }
}