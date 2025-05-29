#include "AuthController.h"
#include <algorithm>

AuthController::AuthController(CustomerRepository& customerRepo, EmployeeRepository& employeeRepo)
    : customerRepo(customerRepo), employeeRepo(employeeRepo) {}

std::shared_ptr<User> AuthController::login(const std::string& email, const std::string& password) {
    // Try to find customer first
    auto customer = customerRepo.findByEmail(email);
    if (customer.has_value() && customer->authenticate(email, password)) {
        return std::make_shared<Customer>(customer.value());
    }

    // Try to find employee
    auto employee = employeeRepo.findByEmail(email);
    if (employee.has_value() && employee->authenticate(email, password)) {
        return std::make_shared<Employee>(employee.value());
    }

    return nullptr;
}

std::vector<std::string> AuthController::getAvailableActions(UserType userType) const {
    switch (userType) {
        case UserType::CUSTOMER:
            return {
                "View Products",
                "Create Reservation",
                "View My Orders",
                "Manage Favorites",
                "Update Profile"
            };
        case UserType::EMPLOYEE:
            return {
                "Manage Customers",
                "Manage Products",
                "Manage Orders",
                "View All Orders",
                "Update Profile"
            };
        case UserType::ADMIN:
            return {
                "Manage Customers",
                "Manage Products",
                "Manage Orders",
                "Manage Employees",
                "View All Orders",
                "View Employee Salaries",
                "Update Profile"
            };
        default:
            return {};
    }
}

bool AuthController::hasPermission(UserType userType, const std::string& action) const {
    auto actions = getAvailableActions(userType);
    return std::find(actions.begin(), actions.end(), action) != actions.end();
}
