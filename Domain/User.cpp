#include "User.h"
#include <regex>

using namespace std;

// constructor
User::User(const string& email, const string& password, UserType userType)
    : email(email), password(password), userType(userType) {}

// getter
string User::getEmail() const {
    return email;
}

UserType User::getUserType() const {
    return userType;
}

//  autentificare
bool User::authenticate(const string& email, const string& password) const {
    return this->email == email && this->password == password;
}

// validarea pentru mail
bool User::isValidEmail(const string& email) {
    const regex emailRegex(R"((\w+)(\.{0,1})(\w*)@(\w+)\.(\w+))");
    return regex_match(email, emailRegex);
}