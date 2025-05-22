#include "Order.h"
#include <string>

Order::Order(const string& orderId, const string& customerId, const string& productId, std::time_t orderDate)
    : orderId(orderId), customerId(customerId), productId(productId), orderDate(orderDate) {}

string Order::getOrderId() const { return orderId; }
string Order::getCustomerId() const { return customerId; }
string Order::getProductId() const { return productId; }
std::time_t Order::getOrderDate() const { return orderDate; }