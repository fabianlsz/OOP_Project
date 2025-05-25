#include <iostream>
#include "C:\Users\oli\CLionProjects\OOPLab_712_1\Lab5_OOP_fixed\Lab5_OOP\Authentificator_Product_User/Authentication.h"
#include "C:\Users\oli\CLionProjects\OOPLab_712_1\Lab5_OOP_fixed\Lab5_OOP\Authentificator_Product_User/StartDataB.h"
#include "C:\Users\oli\CLionProjects\OOPLab_712_1\Lab5_OOP_fixed\Lab5_OOP\Authentificator_Product_User/ProductValidator.h"

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