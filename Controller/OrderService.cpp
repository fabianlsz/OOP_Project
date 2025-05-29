#include "OrderService.h"
#include <stdexcept>
#include <algorithm>

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

double OrderService_calculateTotal(const std::vector<ProductQuantity>& products, const std::vector<Product>& allProducts) {
    double total = 0.0;
    for (const auto& pq : products) {
        auto it = std::find_if(allProducts.begin(), allProducts.end(),
            [&](const Product& p) { return p.getId() == pq.productId; });
        if (it != allProducts.end())
            total += it->getPrice() * pq.quantity;
    }
    return total;
}

bool OrderService::createReservation(const User& user, const std::vector<ProductQuantity>& products) {
    double total = OrderService_calculateTotal(products, this->products);
    std::string orderNumber = std::to_string(orderNumberCounter++);
    orders.emplace_back(orderNumber, orderStatusToString(OrderStatus::Reservation), products, user.getEmail(), total, OrderStatus::Reservation);
    std::cout << "Reservation created. Order number: " << orderNumber << "\n";
    return true;
}

bool OrderService::adoptOrder(const User& user, const std::string& orderNumber) {
    auto it = std::find_if(orders.begin(), orders.end(),
        [&](const Order& o) { return o.getOrderNumber() == orderNumber; });
    if (it != orders.end()) {
        std::cout << "Employee " << user.getEmail() << " adopted order " << orderNumber << "\n";
        return true;
    }
    std::cout << "Order not found.\n";
    return false;
}

bool OrderService::createOrConfirmOrder(const User& user, const std::vector<ProductQuantity>& products, const std::string& customerId) {
    double total = OrderService_calculateTotal(products, this->products);
    std::string orderNumber = std::to_string(orderNumberCounter++);
    orders.emplace_back(orderNumber, orderStatusToString(OrderStatus::Confirmed), products, customerId, total, OrderStatus::Confirmed);
    std::cout << "Order confirmed. Order number: " << orderNumber << "\n";
    return true;
}