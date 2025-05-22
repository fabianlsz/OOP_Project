#include "CustomerRepository.h"

void CustomerRepository::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

#include "CustomerRepository.h"

void CustomerRepository::anonymizeCustomer(const std::string& email) {
    for (auto& c : customers) {
        if (c.email == email) {
            c.name = "Kunde-" + email;
            c.firstName = "Unbekannt"; // Updated
            c.email = "";
            c.address = "";           // Updated
            c.bemerkungen = "";
            c.gdprDeleted = true;
        }
    }
}

std::optional<Customer> CustomerRepository::findByEmail(const std::string& email) const {
    for (const auto& c : customers) {
        if (c.email == email) return c;
    }
    return std::nullopt;
}

const std::vector<Customer>& CustomerRepository::getAll() const {
    return customers;
}