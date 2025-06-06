#include <iostream>
#include "Controller/AuthenticationController.h"
#include "Controller/CustomerManager.h"
#include "Repository/Repository.h"
#include "UI/EmployeeUI.h"

using namespace std;

void showMenuForUserType(UserType userType) {
}

int main() {
    CustomerRepository customerRepo;
    customerRepo.addCustomer({"Pop", "Ionut", "ionut.pop@secret.com", "x", "adresa", "y"});
    AuthenticationController authController(customerRepo);
    // TODO
    CustomerManager customerController(customerRepo);
    //
    EmployeeUI employeeUI(customerController);

    // Simulate user login
    string email, password;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    const User* user = authController.login(email, password);
    if (user->getUserType() == UserType::EMPLOYEE) {
        employeeUI.run();
        cout << "1. Manage Orders\n";
        cout << "2. Manage Products\n";
    } else if (user->getUserType() == UserType::CUSTOMER) {
        cout << "1. View Products\n";
        cout << "2. Place Order\n";
    }
    if (user) {
        cout << "Login successful!\n";
        showMenuForUserType(user->getUserType());
    } else {
        cout << "Invalid credentials!\n";
    }

    return 0;
}