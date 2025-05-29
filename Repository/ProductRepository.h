#ifndef PRODUCTREPOSITORY_H
#define PRODUCTREPOSITORY_H

#include "../Domain/Product.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

class ProductRepository {
private:
    std::vector<Product> products;

public:
    // Add product with validation
    void addProduct(const Product& product) {
        // Check for duplicate product ID
        auto it = std::find_if(products.begin(), products.end(),
            [&product](const Product& p) {
                return p.getProductId() == product.getProductId();
            });

        if (it != products.end()) {
            throw std::invalid_argument("Product with this ID already exists");
        }

        products.push_back(product);
    }

    // Get all available products (with stock > 0) sorted by price ascending
    std::vector<Product> getAvailableProducts() const {
        std::vector<Product> availableProducts;

        // Filter products with stock > 0
        std::copy_if(products.begin(), products.end(), std::back_inserter(availableProducts),
            [](const Product& p) { return p.getStock() > 0; });

        // Sort by price ascending
        std::sort(availableProducts.begin(), availableProducts.end(),
            [](const Product& a, const Product& b) { return a.getPrice() < b.getPrice(); });

        return availableProducts;
    }

    // Find product by ID
    Product* findProductById(const std::string& productId) {
        auto it = std::find_if(products.begin(), products.end(),
            [&productId](const Product& p) {
                return p.getProductId() == productId;
            });

        return it != products.end() ? &(*it) : nullptr;
    }

    // Get all products (for testing purposes)
    const std::vector<Product>& getAllProducts() const {
        return products;
    }
};

#endif // PRODUCTREPOSITORY_H