#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct ProductQuantity {
    string productId;
    int quantity;
};

class Order {
    string orderNumber;
    string status;
    vector<ProductQuantity> products;
    string customerId;
    double totalPrice;
public:
    Order(string orderNumber, string status, vector<ProductQuantity> products, string customerId, double totalPrice)
        : orderNumber(orderNumber), status(status), products(products), customerId(customerId), totalPrice(totalPrice) {}

    string getOrderNumber() const { return orderNumber; }
    string getStatus() const { return status; }
    vector<ProductQuantity> getProducts() const { return products; }
    string getCustomerId() const { return customerId; }
    double getTotalPrice() const { return totalPrice; }
    void setStatus(string newStatus) { status = newStatus; }

    void print() const {
        cout << "Order Number: " << orderNumber << endl;
        cout << "Status: ";
        if (status == "Reservation") cout << "Reservation";
        else if (status == "Confirmed") cout << "Confirmed";
        else if (status == "Completed") cout << "Completed";
        else cout << status;
        cout << endl;
        cout << "Customer: " << customerId << endl;
        cout << "Total Price: " << totalPrice << endl;
        cout << "Products: " << endl;
        for (const auto& product : products) {
            cout << "  Product ID: " << product.productId << ", Quantity: " << product.quantity << endl;
        }
    }
};