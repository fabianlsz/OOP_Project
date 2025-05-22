#include <iostream>
#include "Services/AuthenticationService.h"

using namespace std;

void showMenuForUserType(UserType userType) {
    if (userType == UserType::EMPLOYEE) {
        cout << "1. Manage Orders\n";
        cout << "2. Manage Products\n";
    } else if (userType == UserType::CUSTOMER) {
        cout << "1. View Products\n";
        cout << "2. Place Order\n";
    }
}

int main() {
    UserRepository userRepo("data/users.json");
    AuthenticationService authService(userRepo);

    // Simulate user login
    string email, password;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    const User* user = authService.authenticate(email, password);
    if (user) {
        cout << "Login successful!\n";
        showMenuForUserType(user->getUserType());
    } else {
        cout << "Invalid credentials!\n";
    }

    return 0;
}