#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <ctime>

enum class OrderStatus {
    RESERVATION,
    ORDER,
    COMPLETED
};

class Order {
private:
    std::string orderNumber;
    std::string orderDate;
    OrderStatus status;
    std::string productId;
    std::string startDate;
    std::string endDate;
    std::string customerId;
    std::string employeeId;
    double totalAmount;
    std::string notes;

public:
    Order(const std::string& orderNumber, const std::string& productId,
          const std::string& startDate, const std::string& endDate,
          const std::string& customerId, const std::string& employeeId = "",
          const std::string& notes = "");

    // Getters
    std::string getOrderNumber() const;
    std::string getOrderDate() const;
    OrderStatus getStatus() const;
    std::string getProductId() const;
    std::string getStartDate() const;
    std::string getEndDate() const;
    std::string getCustomerId() const;
    std::string getEmployeeId() const;
    double getTotalAmount() const;
    std::string getNotes() const;

    // Setters
    void setStatus(OrderStatus status);
    void setEmployeeId(const std::string& employeeId);
    void setTotalAmount(double amount);
    void setNotes(const std::string& notes);

    // Status management
    void convertToOrder();
    void complete(double productPrice);
    bool canBeModified() const;

    // Date calculations
    int getDurationInDays() const;
    bool isValidDateRange() const;
};

#endif
