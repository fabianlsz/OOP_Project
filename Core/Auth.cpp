#include "Auth.h"

using namespace std;

// adaugare user
void Authenticator::addUser(const User& user) {
    users.push_back(user);
}

// functie login
const User* Authenticator::login(const string& email, const string& password) const {
    for (const auto& user : users) {
        if (user.authenticate(email, password)) {
            return &user;
        }
    }
    return nullptr; // null daca auth fails
}