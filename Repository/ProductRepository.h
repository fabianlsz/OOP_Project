#ifndef PRODUCTREPOSITORY_H
#define PRODUCTREPOSITORY_H

#include "../Domain/Product.h"
#include <vector>
#include <stdexcept>

class ProductRepository {
private:
    std::vector<Product> products;

public:
    void addProduct(const Product& product);
    std::vector<Product> getAvailableProducts() const;
    Product* findProductById(const std::string& productId);
    const std::vector<Product>& getAllProducts() const;
};

#endif // PRODUCTREPOSITORY_H