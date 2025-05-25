#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum OrderStatus {
  // TODO
};

struct ProductQuantity{
  std::string productId;
  int quantity;
};

class Order{
  string orderNumber;
  OrderStatus status;
  vector<ProductQuantity> products;
  string customerId;
  double totalPrice;
  public:
  Order(string orderNumber, OrderStatus status, vector<ProductQuantity> products, string customerId, double totalPrice)
    : orderNumber(orderNumber), status(status), products(products), customerId(customerId), totalPrice(totalPrice) {}
  string getOrderNumber() const { return orderNumber; }
  OrderStatus getStatus() const { return status; }
  vector<ProductQuantity> getProducts() const { return products; }
  string getCustomerId() const { return customerId; }
  double getTotalPrice() const { return totalPrice; }
  void setStatus(OrderStatus newStatus) { status = newStatus; }
  void setProducts(const std::vector<ProductQuantity>& newProducts, double newTotal) {
    //TODO
    // products = newProducts; totalAmount = newTotal;
  }
  void print() const{
    cout <<"Order Number: " << orderNumber << endl;
    // TODO
    // cout << "Status: " << (status == OrderStatus::Reservation ? "Reservation" : status == OrderStatus::Confirmed ? "Confirmed" : "Completed") << endl;
    cout << "Customer " << customerId << endl;
    cout<< "Toatal Price: " << totalPrice << endl;
    cout << "Products: " << endl;
    for (const auto& product : products) {
      cout << "Product ID: " << product.productId << ", Quantity: " << product.quantity << endl;
    }

  }
};