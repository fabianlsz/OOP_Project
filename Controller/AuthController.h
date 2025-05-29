#ifndef AUTH_CONTROLLER_H
#define AUTH_CONTROLLER_H

#include "../domain/User.h"
#include "../repository/CustomerRepository.h"
#include "../repository/EmployeeRepository.h"
#include <memory>

class AuthController {
private:
    CustomerRepository& customerRepo;
    EmployeeRepository& employeeRepo;

public:
    AuthController(CustomerRepository& customerRepo, EmployeeRepository& employeeRepo);

    std::shared_ptr<User> login(const std::string& email, const std::string& password);
    std::vector<std::string> getAvailableActions(UserType userType) const;
    bool hasPermission(UserType userType, const std::string& action) const;
};

#endif
