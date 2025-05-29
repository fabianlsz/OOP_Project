#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <iostream>

class Order {
public:
    std::string orderId;
    std::string customerEmail;
    std::string productId;
    int quantity;

    Order(const std::string& orderId, const std::string& customerEmail, const std::string& productId, int quantity)
        : orderId(orderId), customerEmail(customerEmail), productId(productId), quantity(quantity) {}
    Order() : quantity(0) {}

    void print() const {
        std::cout << "Order: " << orderId << " | Customer: " << customerEmail << " | Product: " << productId << " | Quantity: " << quantity << std::endl;
    }
};

#endif 