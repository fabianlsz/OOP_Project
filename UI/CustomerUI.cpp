#include "CustomerUI.h"
#include <iostream>
#include <limits>
#include <algorithm>

void CustomerUI::showMenu() {
    while (true) {
        std::cout << "\nCustomer Menu:\n"
                  << "1. View Products\n"
                  << "2. Place Order\n"
                  << "0. Exit\n";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            handleViewProducts();
        } else if (choice == 2) {
            handlePlaceOrder();
        } else if (choice == 0) {
            std::cout << "Bye!\n";
            break;
        } else {
            std::cout << "Invalid option. Please try again.\n";
        }
    }
}

void CustomerUI::handleViewProducts() {
    const auto& products = orderService.getAllProducts();
    if (products.empty()) {
        std::cout << "No products available.\n";
        return;
    }
    std::cout << "Available products:\n";
    for (const auto& product : products) {
        std::cout << "ID: " << product.getId()
                  << " | Name: " << product.getName()
                  << " | Price: " << product.getPrice() << "\n";
    }
}

void CustomerUI::handlePlaceOrder() {
    const auto& products = orderService.getAllProducts();
    if (products.empty()) {
        std::cout << "No products available to order.\n";
        return;
    }

    std::vector<ProductQuantity> selectedProducts;
    while (true) {
        std::string productId;
        int quantity;

        std::cout << "Enter product ID to add to order (or type 'done' to finish): ";
        std::cin >> productId;
        if (productId == "done") break;

        auto it = std::find_if(products.begin(), products.end(),
            [&](const Product& p) { return p.getId() == productId; });
        if (it == products.end()) {
            std::cout << "Product ID not found. Try again.\n";
            continue;
        }

        std::cout << "Enter quantity: ";
        std::cin >> quantity;
        if (std::cin.fail() || quantity <= 0) {
            std::cout << "Invalid quantity. Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        selectedProducts.push_back({productId, quantity});
    }

    if (selectedProducts.empty()) {
        std::cout << "No products selected. Order cancelled.\n";
        return;
    }

    bool success = orderService.createReservation(currentUser, selectedProducts);
    std::cout << (success ? "Order placed!\n" : "Order failed.\n");
}