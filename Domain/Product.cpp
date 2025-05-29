#include "Product.h"

Product::Product(const std::string& id, const std::string& name, double price, int stock)
    : productId(id), name(name), price(price), stock(stock) {
    validate();
}

// Getters
std::string Product::getProductId() const { return productId; }
std::string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getStock() const { return stock; }

// Setters
void Product::setName(const std::string& newName) {
    if (newName.empty()) throw std::invalid_argument("Name cannot be empty");
    name = newName;
}

void Product::setPrice(double newPrice) {
    if (newPrice < 0) throw std::invalid_argument("Price cannot be negative");
    price = newPrice;
}

void Product::setStock(int newStock) {
    if (newStock < 0) throw std::invalid_argument("Stock cannot be negative");
    stock = newStock;
}

void Product::validate() const {
    if (productId.empty()) throw std::invalid_argument("Product ID cannot be empty");
    for (char c : productId) {
        if (!isalnum(c)) throw std::invalid_argument("Product ID must be alphanumeric");
    }
    if (name.empty()) throw std::invalid_argument("Name cannot be empty");
    if (price < 0) throw std::invalid_argument("Price cannot be negative");
    if (stock < 0) throw std::invalid_argument("Stock cannot be negative");
}

std::string Product::toString() const {
    return "ID: " + productId + ", Name: " + name + ", Price: " + std::to_string(price) + ", Stock: " + std::to_string(stock);
}