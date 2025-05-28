#pragma once
#include <string>
#include <iostream>

class Product {
    std::string id;
    std::string name;
    double price;

public:
    Product(const std::string& id, const std::string& name, double price);

    std::string getId() const;
    std::string getName() const;
    double getPrice() const;
    void print() const;
};