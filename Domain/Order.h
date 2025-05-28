#pragma once
#include <string>
#include <vector>
#include <iostream>

enum class OrderStatus {
  Reservation,
  Confirmed,
  Completed,
  Cancelled
};

struct ProductQuantity {
  std::string productId;
  int quantity;
};

class Order {
  std::string orderNumber;
  std::string status;
  std::vector<ProductQuantity> products;
  std::string customerId;
  double totalPrice;
public:
  Order(std::string orderNumber, std::string status, std::vector<ProductQuantity> products, std::string customerId, double totalPrice, OrderStatus order_status);

  std::string getOrderNumber() const;
  std::string getStatus() const;
  std::vector<ProductQuantity> getProducts() const;
  std::string getCustomerId() const;
  double getTotalPrice() const;
  void setStatus(std::string newStatus);

  void print() const;
};

