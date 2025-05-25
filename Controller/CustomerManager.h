#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include "CustomerRepository.h"

class CustomerManager {
private:
    CustomerRepository& repo;

public:
    CustomerManager(CustomerRepository& repository);

    void createCustomer(const Customer& customer);
    void updateCustomer(const std::string& email, const Customer& updated);
    void deleteCustomer(const std::string& email);  // checks for orders (not implemented here)
    void anonymizeCustomer(const std::string& email);
};

#endif