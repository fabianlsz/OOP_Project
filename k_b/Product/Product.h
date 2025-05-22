#pragma once
#include <string>
#include <iostream>
class Product {
    std::string id;
    std::string name;
    double price;
public:
    Product(const std::string& id, const std::string& name, double price)
        : id(id), name(name), price(price) {}
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    void print() const {
        std::cout << "Product: " << id << " | Name: " << name << " | Price: " << price << "\n";
    }
};