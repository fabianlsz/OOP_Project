#include "Authentication.h"

void Authentication::addUser(const std::string& email, const std::string& password) {
    credentials[email] = password;
}

bool Authentication::authenticate(const std::string& email, const std::string& password) const {
    auto it = credentials.find(email);
    return it != credentials.end() && it->second == password;
}