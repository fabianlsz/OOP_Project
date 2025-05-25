#pragma once
#include <vector>
#include <string>
#include <optional>
#include <unordered_map>
#include <iostream>
#include "../Domain/Order.h"
#include "../Domain/User.h"
#include "../Domain/Customer.h"
#include "../Domain/Product.h"

class OrderService {
    std::vector<Order> orders;
    std::unordered_map<std::string, Product> products;
    std::vector<Customer> customers;
    int orderNumberCounter = 1;

    std::string generateOrderNumber();
    double calculateTotal(const std::vector<ProductQuantity>& products) const;
public:
    OrderService(const std::vector<Product>& products, const std::vector<Customer>& customers);

    Order createOrder(OrderStatus status, const std::vector<ProductQuantity>& products,
                      const std::string& customerId, std::optional<std::string> mitarbeiterId);

    // B2: Mitarbeiter
    bool createOrConfirmOrder(const User& user, const std::vector<ProductQuantity>& products, const std::string& customerId);
    bool updateOrder(const User& user, const std::string& orderNumber, const std::vector<ProductQuantity>& newProducts);
    bool setOrderCompleted(const User& user, const std::string& orderNumber);
    bool adoptOrder(const User& user, const std::string& orderNumber);

    // B3: Kunden
    bool createReservation(const User& user, const std::vector<ProductQuantity>& products);

    // B4: Queries
    std::vector<Order> getOrders(const User& user, std::optional<OrderStatus> status = std::nullopt) const;
    const std::vector<Order>& getAllOrders() const { return orders; }
    const std::vector<Customer>& getAllCustomers() const { return customers; }
    std::vector<Product> getAllProducts() const;

    // B5: Validations (enforced in above)
    bool isOrderNumberUnique(const std::string& orderNumber) const;
    bool isEmployeeFieldValid(const Order& order) const;

    // Print
    void printOrders() const;
    void printCustomers() const;
    void printProducts() const;
};