#include "Product.h"

Product::Product(const std::string& id, const std::string& name, double price)
    : id(id), name(name), price(price) {}

std::string Product::getId() const {
    return id;
}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

void Product::print() const {
    std::cout << "Product: " << id << " | Name: " << name << " | Price: " << price << "\n";
}