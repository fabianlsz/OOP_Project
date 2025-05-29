#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {
public:
    std::string id;
    std::string name;
    double price;

    Product(const std::string& id, const std::string& name, double price)
        : id(id), name(name), price(price) {}
    Product() : price(0.0) {}

    void print() const {
        std::cout << "Product: " << id << " | Name: " << name << " | Price: " << price << std::endl;
    }
};

#endif 