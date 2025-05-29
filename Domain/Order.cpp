#include "Order.h"
#include <ctime>
#include <sstream>
#include <iomanip>

Order::Order(const std::string& orderNumber, const std::string& productId,
             const std::string& startDate, const std::string& endDate,
             const std::string& customerId, const std::string& employeeId,
             const std::string& notes)
    : orderNumber(orderNumber), productId(productId), startDate(startDate),
      endDate(endDate), customerId(customerId), employeeId(employeeId),
      notes(notes), status(OrderStatus::RESERVATION), totalAmount(0.0) {

    // Set current date as order date
    auto now = std::time(nullptr);
    auto tm = *std::localtime(&now);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");
    orderDate = oss.str();
}

std::string Order::getOrderNumber() const {
    return orderNumber;
}

std::string Order::getOrderDate() const {
    return orderDate;
}

OrderStatus Order::getStatus() const {
    return status;
}

std::string Order::getProductId() const {
    return productId;
}

std::string Order::getStartDate() const {
    return startDate;
}

std::string Order::getEndDate() const {
    return endDate;
}

std::string Order::getCustomerId() const {
    return customerId;
}

std::string Order::getEmployeeId() const {
    return employeeId;
}

double Order::getTotalAmount() const {
    return totalAmount;
}

std::string Order::getNotes() const {
    return notes;
}

void Order::setStatus(OrderStatus status) {
    this->status = status;
}

void Order::setEmployeeId(const std::string& employeeId) {
    this->employeeId = employeeId;
}

void Order::setTotalAmount(double amount) {
    this->totalAmount = amount;
}

void Order::setNotes(const std::string& notes) {
    this->notes = notes;
}

void Order::convertToOrder() {
    if (status == OrderStatus::RESERVATION) {
        status = OrderStatus::ORDER;
    }
}

void Order::complete(double productPrice) {
    if (status != OrderStatus::COMPLETED) {
        status = OrderStatus::COMPLETED;
        totalAmount = productPrice * getDurationInDays();
    }
}

bool Order::canBeModified() const {
    return status != OrderStatus::COMPLETED;
}

int Order::getDurationInDays() const {
    // Simplified calculation - in real implementation would parse dates properly
    return 1; // Placeholder
}

bool Order::isValidDateRange() const {
    // Simplified validation - in real implementation would parse and compare dates
    return startDate <= endDate;
}
