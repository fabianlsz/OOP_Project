#include <iostream>
#include "Controller/AuthenticationController.h"
#include "Controller/CustomerManager.h"
#include "Controller/OrderService.h"
#include "Repository/CustomerRepository.h"
#include "Repository/StartDataMK.h"
#include "UI/EmployeeUI.h"
#include "UI/CustomerUI.h"
#include "Domain/User.h"

int main() {
    CustomerRepository customerRepo;
    StartDataMK::initCustomers(customerRepo);
    std::vector<Customer> customers = customerRepo.getAll();
    std::vector<Product> products;

    OrderService orderService(products, customers);
    AuthenticationController authController(customerRepo);

    std::string email, password;
    std::cout << "Enter email: ";
    std::cin >> email;
    std::cout << "Enter password: ";
    std::cin >> password;

    const User* user = authController.login(email, password);
    if (!user) {
        std::cout << "Invalid credentials!\n";
        return 1;
    }

    std::cout << "Login successful!\n";
    if (user->getUserType() == UserType::EMPLOYEE) {
        EmployeeUI employeeUI(orderService, *user);
        employeeUI.run();
    } else if (user->getUserType() == UserType::CUSTOMER) {
        CustomerUI customerUI(orderService, *user);
        customerUI.showMenu();
    } else {
        std::cout << "Unknown user type.\n";
    }

    return 0;
}