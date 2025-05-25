#ifndef CUSTOMERREPOSITORY_H
#define CUSTOMERREPOSITORY_H

#include "../Domain/Customer.h"
#include <vector>
#include <optional>

class CustomerRepository {
private:
    std::vector<Customer> customers;

public:
    void addCustomer(const Customer& customer);
    void anonymizeCustomer(const std::string& email);
    std::optional<Customer> findByEmail(const std::string& email) const;
    const std::vector<Customer>& getAll() const;
};

#endif