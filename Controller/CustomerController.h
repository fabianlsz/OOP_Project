#pragma once
#include <vector>
#include "../Domain/Customer.h"
#include "../Domain/Order.h"
// TODO: merge this class with CustomerManager
class CustomerController {
    std::vector<Customer> customers;
    std::vector<Order> orders;
public:
    CustomerController(const std::vector<Customer>& customers, const std::vector<Order>& orders);

    std::vector<Customer> getAllCustomersSorted() const;

    std::vector<Customer> findCustomersByEmail(const std::string& email) const;
};