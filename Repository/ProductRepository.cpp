#include "ProductRepository.h"
#include <algorithm>

void ProductRepository::addProduct(const Product& product) {
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

std::vector<Product> ProductRepository::getAvailableProducts() const {
    std::vector<Product> availableProducts;

    // Filter products with stock > 0
    std::copy_if(products.begin(), products.end(), std::back_inserter(availableProducts),
        [](const Product& p) { return p.getStock() > 0; });

    // Sort by price ascending
    std::sort(availableProducts.begin(), availableProducts.end(),
        [](const Product& a, const Product& b) { return a.getPrice() < b.getPrice(); });

    return availableProducts;
}

Product* ProductRepository::findProductById(const std::string& productId) {
    auto it = std::find_if(products.begin(), products.end(),
        [&productId](const Product& p) {
            return p.getProductId() == productId;
        });

    return it != products.end() ? &(*it) : nullptr;
}

const std::vector<Product>& ProductRepository::getAllProducts() const {
    return products;
}