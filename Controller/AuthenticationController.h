#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include "../Domain/User.h"
#include "../Repository/CustomerRepository.h"
#include "../Domain/Customer.h"
#include <vector>

using namespace std;

class AuthenticationController {
private:
    // TODO use CustomerRepository
    CustomerRepository& customerRepo;
    // TODO also look in EmployeeRepository

public:
    explicit AuthenticationController(CustomerRepository& customerRepo): customerRepo(customerRepo) {}
    // login function
    const User* login(const string& email, const string& password) const;
};

#endif // AUTHENTICATOR_H