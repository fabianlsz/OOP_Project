#pragma once
#include <vector>
#include "Customer.h"
#include "Order.h"

class CustomerManager {
    std::vector<Customer> customers;
    std::vector<Order> orders;
public:
    CustomerManager(const std::vector<Customer>& customers, const std::vector<Order>& orders);

    std::vector<Customer> getAllCustomersSorted() const;

    std::vector<Customer> findCustomersByEmail(const std::string& email) const;
};