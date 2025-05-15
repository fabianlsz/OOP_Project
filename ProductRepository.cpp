#include "ProductRepository.h"
#include <algorithm>

void ProductRepository::addProduct(const Product& product) {
    products.push_back(product);
}

std::vector<Product> ProductRepository::getAvailableSortedByPrice() const {
    std::vector<Product> result;
    for (const auto& p : products) {
        if (p.lagerbestand > 0) result.push_back(p);
    }
    std::sort(result.begin(), result.end(), [](const Product& a, const Product& b) {
        return a.preis < b.preis;
    });
    return result;
}

std::optional<Product> ProductRepository::findById(const std::string& id) const {
    for (const auto& p : products) {
        if (p.id == id) return p;
    }
    return std::nullopt;
}