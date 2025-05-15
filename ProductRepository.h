#ifndef PRODUCTREPOSITORY_H
#define PRODUCTREPOSITORY_H

#include "Product.h"
#include <vector>
#include <optional>

class ProductRepository {
private:
    std::vector<Product> products;

public:
    void addProduct(const Product& product);
    std::vector<Product> getAvailableSortedByPrice() const;
    std::optional<Product> findById(const std::string& id) const;
};

#endif