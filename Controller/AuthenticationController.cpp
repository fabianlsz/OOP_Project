#include "AuthenticationController.h"
#include "../Domain/User.h"

const User* AuthenticationController::login(const std::string& email, const std::string& password) const {
    // Check customers
    auto customerOpt = customerRepo.findByEmail(email);
    if (customerOpt.has_value()) {
        const Customer& customer = customerOpt.value();
        if (customer.authenticate(email, password)) {
            return &customer;
        }
    }

    // Check employees
    auto employeeOpt = employeeRepo.findByEmail(email);
    if (employeeOpt.has_value()) {
        const Employee& employee = employeeOpt.value();
        if (employee.authenticate(email, password)) {
            return &employee;
        }
    }

    return nullptr; // Login failed
}
