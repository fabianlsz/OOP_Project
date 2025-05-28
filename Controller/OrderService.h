#pragma once

#include <vector>
#include <string>
#include <optional>
#include <unordered_map>
#include "../Domain/Order.h"
#include "../Domain/User.h"
#include "../Domain/Customer.h"
#include "../Domain/Product.h"

class OrderService {
private:
    std::vector<Order> orders;
    std::vector<Customer> customers;
    std::vector<Product> products;
    int orderNumberCounter = 1;

    std::string generateOrderNumber();
    double calculateTotal(const std::vector<ProductQuantity>& products) const;

public:
    OrderService(const std::vector<Product>& products, const std::vector<Customer>& customers);

    // Create a new order (by employee)
    Order createOrder(const User& employee, const std::vector<ProductQuantity>& products, const std::string& customerEmail);

    // Update products in an existing order (by employee)
    bool updateOrder(const User& employee, const std::string& orderNumber, const std::vector<ProductQuantity>& newProducts);

    // Mark an order as completed (by employee)
    bool setOrderCompleted(const User& employee, const std::string& orderNumber);

    // Customer creates a reservation (pre-order)
    Order createReservation(const Customer& customer, const std::vector<ProductQuantity>& products);

    // Get all orders for a given user
    std::vector<Order> getOrdersForUser(const User& user, std::optional<OrderStatus> status = std::nullopt) const;

    // Get all orders
    const std::vector<Order>& getAllOrders() const { return orders; }

    // Get all customers
    const std::vector<Customer>& getAllCustomers() const { return customers; }

    // Get all products
    const std::vector<Product>& getAllProducts() const { return products; }

    // Utility: Check order number uniqueness
    bool isOrderNumberUnique(const std::string& orderNumber) const;
};