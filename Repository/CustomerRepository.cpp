#include "CustomerRepository.h"

void CustomerRepository::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

void CustomerRepository::anonymizeCustomer(const std::string& email) {
    for (auto& c : customers) {
        if (c.getEmail() == email) {
            c.anonymize();
        }
    }
}

std::optional<Customer> CustomerRepository::findByEmail(const std::string& email) const {
    for (const auto& c : customers) {
        if (c.getEmail() == email) return c;
    }
    return std::nullopt;
}

const std::vector<Customer>& CustomerRepository::getAll() const {
    return customers;
}