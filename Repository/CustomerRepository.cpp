#include "CustomerRepository.h"
#include <algorithm>

void CustomerRepository::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

void CustomerRepository::updateCustomer(const std::string& email, const Customer& updatedCustomer) {
    auto it = std::find_if(customers.begin(), customers.end(),
        [&email](const Customer& c) { return c.getEmail() == email; });

    if (it != customers.end()) {
        *it = updatedCustomer;
    }
}

void CustomerRepository::deleteCustomer(const std::string& email) {
    customers.erase(
        std::remove_if(customers.begin(), customers.end(),
            [&email](const Customer& c) { return c.getEmail() == email; }),
        customers.end()
    );
}

void CustomerRepository::anonymizeCustomer(const std::string& email) {
    auto it = std::find_if(customers.begin(), customers.end(),
        [&email](Customer& c) { return c.getEmail() == email; });

    if (it != customers.end()) {
        it->anonymize(email); // Using email as customer ID for simplicity
    }
}

std::optional<Customer> CustomerRepository::findByEmail(const std::string& email) const {
    auto it = std::find_if(customers.begin(), customers.end(),
        [&email](const Customer& c) { return c.getEmail() == email; });

    return (it != customers.end()) ? std::optional<Customer>(*it) : std::nullopt;
}

std::optional<Customer> CustomerRepository::findByPhone(const std::string& phone) const {
    auto it = std::find_if(customers.begin(), customers.end(),
        [&phone](const Customer& c) { return c.getPhone() == phone; });

    return (it != customers.end()) ? std::optional<Customer>(*it) : std::nullopt;
}

std::vector<Customer> CustomerRepository::findByName(const std::string& name, const std::string& firstName) const {
    std::vector<Customer> result;
    std::copy_if(customers.begin(), customers.end(), std::back_inserter(result),
        [&name, &firstName](const Customer& c) {
            return c.getName() == name && c.getFirstName() == firstName;
        });
    return result;
}

std::vector<Customer> CustomerRepository::findByProduct(const std::string& productId) const {
    // This would require integration with OrderRepository to find customers who ordered a product
    std::vector<Customer> result;
    return result; // Placeholder
}

const std::vector<Customer>& CustomerRepository::getAll() const {
    return customers;
}

std::vector<Customer> CustomerRepository::getAllSorted() const {
    std::vector<Customer> sorted = customers;
    std::sort(sorted.begin(), sorted.end(),
        [](const Customer& a, const Customer& b) {
            if (a.getName() != b.getName()) {
                return a.getName() < b.getName();
            }
            return a.getFirstName() < b.getFirstName();
        });
    return sorted;
}
