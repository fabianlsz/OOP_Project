#include "OrderService.h"
#include <stdexcept>

static std::string orderStatusToString(OrderStatus status) {
    switch (status) {
        case OrderStatus::Reservation: return "Reservation";
        case OrderStatus::Confirmed:   return "Confirmed";
        case OrderStatus::Completed:   return "Completed";
        case OrderStatus::Cancelled:   return "Cancelled";
        default:                       return "Unknown";
    }
}

std::string OrderService::generateOrderNumber() {
    return "ORD" + std::to_string(orderNumberCounter++);
}

double OrderService::calculateTotal(const std::vector<ProductQuantity>& pqVec) const {
    double total = 0.0;
    for (const auto& pq : pqVec) {
        for (const auto& prod : products) {
            if (prod.getId() == pq.productId) {
                total += prod.getPrice() * pq.quantity;
                break;
            }
        }
    }
    return total;
}

OrderService::OrderService(const std::vector<Product>& prods, const std::vector<Customer>& custs)
    : products(prods), customers(custs) {}


Order OrderService::createOrder(const User& employee, const std::vector<ProductQuantity>& pqVec, const std::string& customerEmail) {
    if (employee.getUserType() != UserType::EMPLOYEE)
        throw std::runtime_error("Only employees can create orders.");

    std::string orderNum = generateOrderNumber();
    double total = calculateTotal(pqVec);
    Order order(orderNum, orderStatusToString(OrderStatus::Confirmed), pqVec, customerEmail, total, OrderStatus::Confirmed);
    orders.push_back(order);
    return order;
}

bool OrderService::updateOrder(const User& employee, const std::string& orderNumber, const std::vector<ProductQuantity>& newProducts) {
    if (employee.getUserType() != UserType::EMPLOYEE)
        return false;

    for (auto& ord : orders) {
        if (ord.getOrderNumber() == orderNumber) {
            double total = calculateTotal(newProducts);
            ord = Order(orderNumber, ord.getStatus(), newProducts, ord.getCustomerId(), total, OrderStatus::Confirmed);
            return true;
        }
    }
    return false;
}

bool OrderService::setOrderCompleted(const User& employee, const std::string& orderNumber) {
    if (employee.getUserType() != UserType::EMPLOYEE)
        return false;

    for (auto& ord : orders) {
        if (ord.getOrderNumber() == orderNumber) {
            ord.setStatus(orderStatusToString(OrderStatus::Completed));
            return true;
        }
    }
    return false;
}

Order OrderService::createReservation(const Customer& customer, const std::vector<ProductQuantity>& pqVec) {
    std::string orderNum = generateOrderNumber();
    double total = calculateTotal(pqVec);
    Order order(orderNum, orderStatusToString(OrderStatus::Reservation), pqVec, customer.getEmail(), total, OrderStatus::Reservation);
    orders.push_back(order);
    return order;
}

std::vector<Order> OrderService::getOrdersForUser(const User& user, std::optional<OrderStatus> status) const {
    std::vector<Order> result;
    std::string email = user.getEmail();
    for (const auto& ord : orders) {
        if (user.getUserType() == UserType::EMPLOYEE || ord.getCustomerId() == email) {
            if (!status.has_value() || ord.getStatus() == orderStatusToString(status.value())) {
                result.push_back(ord);
            }
        }
    }
    return result;
}

bool OrderService::isOrderNumberUnique(const std::string& orderNumber) const {
    for (const auto& ord : orders) {
        if (ord.getOrderNumber() == orderNumber)
            return false;
    }
    return true;
}