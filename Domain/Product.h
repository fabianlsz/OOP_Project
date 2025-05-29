#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <stdexcept>

class Product {
private:
    std::string productId;
    std::string name;
    double price;
    int stock;

public:
    Product(const std::string& id, const std::string& name, double price, int stock);

    // Getters
    std::string getProductId() const;
    std::string getName() const;
    double getPrice() const;
    int getStock() const;

    // Setters
    void setName(const std::string& newName);
    void setPrice(double newPrice);
    void setStock(int newStock);

    void validate() const;
    std::string toString() const;
};

#endif // PRODUCT_H