#include <iostream>
#include "Authentication.h"
#include "StartDataB.h"
#include "ProductValidator.h"

void runProductValidationTests();

int main() {
    // A2: Authentifizierung
    Authentication auth;
    for (const auto& user : StartDataB::getUsers()) {
        auth.addUser(user.first, user.second);
    }

    std::cout << "=== Authentifizierung ===\n";
    std::cout << (auth.authenticate("max@test.de", "pass123") ? "Erfolg" : "Fehlgeschlagen") << "\n";
    std::cout << (auth.authenticate("max@test.de", "wrong") ? "Erfolg" : "Fehlgeschlagen") << "\n";

    // T_P: Produktvalidierung testen
    std::cout << "\n=== Produkttests ===\n";
    runProductValidationTests();

    return 0;
}