#include "ProfileManager.h"
#include <iostream>

void ProfileManager::changePassword(const std::string& email, const std::string& oldPass, const std::string& newPass) {
    std::cout << "Passwort für " << email << " erfolgreich geändert. (Simulation)" << std::endl;
}