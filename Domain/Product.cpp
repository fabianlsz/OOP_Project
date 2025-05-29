#include "Product.h"
#include <algorithm>
#include <cctype>

Product::Product(const std::string& productId, const std::string& name,
                 const std::string& category, double price,
                 const std::string& expirationDate, int stock,
                 const std::string& notes)
    : name(name), category(category), price(price), expirationDate(expirationDate),
      stock(stock), notes(notes), active(true) {
    // Convert productId to uppercase
    this->productId = productId;
    std::transform(this->productId.begin(), this->productId.end(),
                   this->productId.begin(), ::toupper);
}

std::string Product::getProductId() const {
    return productId;
}

std::string Product::getName() const {
    return name;
}

std::string Product::getCategory() const {
    return category;
}

double Product::getPrice() const {
    return price;
}

std::string Product::getExpirationDate() const {
    return expirationDate;
}

int Product::getStock() const {
    return stock;
}

std::string Product::getNotes() const {
    return notes;
}

bool Product::isActive() const {
    return active;
}

void Product::setName(const std::string& name) {
    this->name = name;
}

void Product::setCategory(const std::string& category) {
    this->category = category;
}

void Product::setPrice(double price) {
    this->price = price;
}

void Product::setExpirationDate(const std::string& expirationDate) {
    this->expirationDate = expirationDate;
}

void Product::setStock(int stock) {
    this->stock = stock;
}

void Product::setNotes(const std::string& notes) {
    this->notes = notes;
}

void Product::setActive(bool active) {
    this->active = active;
}

void Product::increaseStock(int amount) {
    if (amount > 0) {
        stock += amount;
    }
}

void Product::decreaseStock(int amount) {
    if (amount > 0 && amount <= stock) {
        stock -= amount;
    }
}

bool Product::isAvailable() const {
    return active && stock > 0 && !isExpired();
}

bool Product::isExpired() const {
    // Simplified expiration check - in real implementation would compare with current date
    return false; // Placeholder
}
