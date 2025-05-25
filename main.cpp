#include <iostream>
#include "Controller/AuthenticationController.h"
#include "Repository/Repository.h"

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
    Repository<Customer> customerRepo;
    customerRepo.add({"Pop", "Ionut", "ionut.pop@secret.com", "x", "adresa", "y"});
    AuthenticationController authController(customerRepo);

    // Simulate user login
    string email, password;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    const User* user = authController.login(email, password);
    if (user) {
        cout << "Login successful!\n";
        showMenuForUserType(user->getUserType());
    } else {
        cout << "Invalid credentials!\n";
    }

    return 0;
}