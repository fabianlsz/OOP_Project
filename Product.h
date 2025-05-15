#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    std::string id;
    std::string name;
    double preis;
    int lagerbestand;

    Product(const std::string& id,
            const std::string& name,
            double preis,
            int lagerbestand);
};

#endif