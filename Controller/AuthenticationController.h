#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include "../Domain/User.h"
#include "../Repository/CustomerRepository.h"
#include "../Repository/EmployeeRepository.h"
#include "../Domain/Customer.h"
#include <vector>
#include <string>

using namespace std;

class AuthenticationController {
private:
    // TODO use CustomerRepository
    CustomerRepository& customerRepo;
    // TODO also look in EmployeeRepository
    EmployeeRepository& employeeRepo;

public:
    explicit AuthenticationController(CustomerRepository& customerRepo, EmployeeRepository& employeeRepo): customerRepo(customerRepo), employeeRepo(employeeRepo) {}
    // login function
    const User* login(const string& email, const string& password) const;
};

#endif // AUTHENTICATOR_H