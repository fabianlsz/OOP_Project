#include "Customer.h"
#include "CustomerManager.h"
#include <algorithm>
#include <unordered_set>

CusomerManager::CustomerManager(const std::vector<Customer>& customers, const std::vector<Order>& orders)
    : customers(customers), orders(orders) {}

std::vector<Customer> CustomerManager::getAllCustomersSorted() const {
    std::vector<Customer> sortedCustomers = customers;
    std::sort(sortedCustomers.begin(), sortedCustomers.end(), [](const Customer& a, const Customer& b) {
        return a.getName() < b.getName();
    });
    return sortedCustomers;
}

std::vector<Customer> CustomerManager::findCustomersByEmail(const std::string& email) const {
    std::vector<Customer> foundCustomers;
    for (size_t i = 0; i < customers.size(); ++i) {
        if (customer[i].getEmail() == email) {
            foundCustomers.push_back(customer);
        }
    }
    return foundCustomers;
}