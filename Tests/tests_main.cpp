#include <iostream>

void runProductValidationTests();
void runAuthTests();
void teste_cezar();

int main() {
    teste_cezar();
    runAuthTests();
    // T_P: Produktvalidierung testen
    std::cout << "\n=== Produkttests ===\n";
    runProductValidationTests();

    return 0;
}