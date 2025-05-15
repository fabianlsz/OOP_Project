#include <iostream>
#include "Product.h"
#include "ProductRepository.h"
#include "ProductValidator.h"
#include "ProfileManager.h"

extern void runProductTests();

int main() {
    std::cout << "=== Produkt-Tests ===\n";
    runProductTests();

    std::cout << "\n=== Profiländerung ===\n";
    ProfileManager::changePassword("kunde@test.de", "alt123", "neu456");

    return 0;
}