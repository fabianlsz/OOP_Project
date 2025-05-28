#include "Order.h"

Order::Order(std::string orderNumber, std::string status, std::vector<ProductQuantity> products, std::string customerId, double totalPrice, OrderStatus order_status)
: orderNumber(std::move(orderNumber)),
  status(order_status == OrderStatus::Reservation ? "Reservation" :
         order_status == OrderStatus::Confirmed ? "Confirmed" :
         order_status == OrderStatus::Completed ? "Completed" : std::move(status)),
  products(std::move(products)),
  customerId(std::move(customerId)),
  totalPrice(totalPrice) {}

std::string Order::getOrderNumber() const { return orderNumber; }
std::string Order::getStatus() const { return status; }
std::vector<ProductQuantity> Order::getProducts() const { return products; }
std::string Order::getCustomerId() const { return customerId; }
double Order::getTotalPrice() const { return totalPrice; }
void Order::setStatus(std::string newStatus) { status = std::move(newStatus); }

void Order::print() const {
    std::cout << "Order Number: " << orderNumber << std::endl;
    std::cout << "Status: ";
    if (status == "Reservation") std::cout << "Reservation";
    else if (status == "Confirmed") std::cout << "Confirmed";
    else if (status == "Completed") std::cout << "Completed";
    else std::cout << status;
    std::cout << std::endl;
    std::cout << "Customer: " << customerId << std::endl;
    std::cout << "Total Price: " << totalPrice << std::endl;
    std::cout << "Products: " << std::endl;
    for (const auto& product : products) {
        std::cout << "  Product ID: " << product.productId << ", Quantity: " << product.quantity << std::endl;
    }
}