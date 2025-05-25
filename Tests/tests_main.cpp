#include <iostream>

void runProductValidationTests();
void runAuthTests();

int main() {
    runAuthTests();
    // T_P: Produktvalidierung testen
    std::cout << "\n=== Produkttests ===\n";
    runProductValidationTests();

    return 0;
}