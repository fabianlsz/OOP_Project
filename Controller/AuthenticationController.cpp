#include "AuthenticationController.h"
#include <memory>

using namespace std;

// functie login
const User* AuthenticationController::login(const string& email, const string& password) const {
    for (const auto& user : customerRepo.getData()) {
        if (user.authenticate(email, password)) {
            return &user;
        }
    }
    return nullptr; // null daca auth fails
}