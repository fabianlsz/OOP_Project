#ifndef CUSTOMER_REPOSITORY_H
#define CUSTOMER_REPOSITORY_H

#include "../domain/Customer.h"
#include <vector>
#include <optional>

class CustomerRepository {
private:
    std::vector<Customer> customers;

public:
    void addCustomer(const Customer& customer);
    void updateCustomer(const std::string& email, const Customer& updatedCustomer);
    void deleteCustomer(const std::string& email);
    void anonymizeCustomer(const std::string& email);

    std::optional<Customer> findByEmail(const std::string& email) const;
    std::optional<Customer> findByPhone(const std::string& phone) const;
    std::vector<Customer> findByName(const std::string& name, const std::string& firstName) const;
    std::vector<Customer> findByProduct(const std::string& productId) const;

    const std::vector<Customer>& getAll() const;
    std::vector<Customer> getAllSorted() const;
};

#endif
