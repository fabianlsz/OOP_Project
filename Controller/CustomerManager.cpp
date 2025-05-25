#include "CustomerManager.h"
#include <stdexcept>

CustomerManager::CustomerManager(CustomerRepository& repository) : repo(repository) {}

void CustomerManager::createCustomer(const Customer& customer) {
    repo.addCustomer(customer);
}

void CustomerManager::updateCustomer(const std::string& email, const Customer& updated) {
    repo.anonymizeCustomer(email); // Placeholder for update logic
    repo.addCustomer(updated);     // Simplified replacement
}

void CustomerManager::deleteCustomer(const std::string& email) {
    // Simulated deletion check; assume no orders exist
    repo.anonymizeCustomer(email);
}

void CustomerManager::anonymizeCustomer(const std::string& email) {
    repo.anonymizeCustomer(email);
}