#include "User.h"
#include <regex>

User::User(const std::string& email, const std::string& password, UserType userType)
    : email(email), password(password), userType(userType), active(true) {}

std::string User::getEmail() const {
    return email;
}

UserType User::getUserType() const {
    return userType;
}

bool User::isActive() const {
    return active;
}

void User::setActive(bool active) {
    this->active = active;
}

bool User::authenticate(const std::string& email, const std::string& password) const {
    return this->email == email && this->password == password && active;
}

bool User::isValidEmail(const std::string& email) {
    const std::regex emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return std::regex_match(email, emailRegex);
}

void User::changePassword(const std::string& newPassword) {
    password = newPassword;
}
