#include "CustomerRepository.h"

void CustomerRepository::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

void CustomerRepository::anonymizeCustomer(const std::string& email) {
    for (auto& c : customers) {
        if (c.email == email) {
            c.name = "Kunde-" + email;
            c.vorname = "Unbekannt";
            c.email = "";
            c.adresse = "";
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