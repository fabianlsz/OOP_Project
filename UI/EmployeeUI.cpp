#include "EmployeeUI.h"
#include "../Controller/OrderService.h"
#include <iostream>
#include <limits>

EmployeeUI::EmployeeUI(OrderService& service, const User& user)
    : orderService(service), currentUser(user) {}

void EmployeeUI::run() {
    while (true) {
        showMenu();
        int choice;
        std::cout << "Select option: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
            case 1: handleViewAllOrders(); break;
            case 2: handleConfirmOrder(); break;
            case 3: handleUpdateOrder(); break;
            case 4: handleSetOrderCompleted(); break;
            case 5: handleAdoptOrder(); break;
            case 0: std::cout << "Exiting...\n"; return;
            default: std::cout << "Invalid option\n";
        }
    }
}

void EmployeeUI::showMenu() {
    std::cout << "\n--- Employee Order Management ---\n";
    std::cout << "1. View all orders\n";
    std::cout << "2. Confirm order\n";
    std::cout << "3. Update order\n";
    std::cout << "4. Set order as completed\n";
    std::cout << "5. Adopt order\n";
    std::cout << "0. Exit\n";
}

void EmployeeUI::handleViewAllOrders() {
    auto orders = orderService.getAllOrders();
    std::cout << "--- Orders ---\n";
    for (const auto& order : orders) {
        order.print();
        std::cout << "---------------------\n";
    }
}

void EmployeeUI::handleConfirmOrder() {
    std::string customerId;
    std::vector<ProductQuantity> products;
    std::cout << "Enter customer ID: ";
    std::cin >> customerId;
    if (orderService.createOrConfirmOrder(currentUser, products, customerId)) {
        std::cout << "Order confirmed.\n";
    } else {
        std::cout << "Failed to confirm order.\n";
    }
}

void EmployeeUI::handleUpdateOrder() {
    std::string orderNumber;
    std::vector<ProductQuantity> newProducts;
    std::cout << "Enter order number: ";
    std::cin >> orderNumber;
    if (orderService.updateOrder(currentUser, orderNumber, newProducts)) {
        std::cout << "Order updated.\n";
    } else {
        std::cout << "Failed to update order.\n";
    }
}

void EmployeeUI::handleSetOrderCompleted() {
    std::string orderNumber;
    std::cout << "Enter order number: ";
    std::cin >> orderNumber;
    if (orderService.setOrderCompleted(currentUser, orderNumber)) {
        std::cout << "Order marked as completed.\n";
    } else {
        std::cout << "Failed to mark order as completed.\n";
    }
}

void EmployeeUI::handleAdoptOrder() {
    std::string orderNumber;
    std::cout << "Enter order number: ";
    std::cin >> orderNumber;
    if (orderService.adoptOrder(currentUser, orderNumber)) {
        std::cout << "Order adopted.\n";
    } else {
        std::cout << "Failed to adopt order.\n";
    }
}

void EmployeeUI::handleManageOrders() {
    std::cout << "Manage Orders Menu:\n";
    std::cout << "1. View all orders\n";
    std::cout << "2. Confirm order\n";
    std::cout << "3. Update order\n";
    std::cout << "4. Set order completed\n";
    std::cout << "5. Adopt order\n";
    std::cout << "0. Back\n";
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1: handleViewAllOrders(); break;
        case 2: handleConfirmOrder(); break;
        case 3: handleUpdateOrder(); break;
        case 4: handleSetOrderCompleted(); break;
        case 5: handleAdoptOrder(); break;
        case 0: std::cout << "Returning to previous menu.\n"; break;
        default: std::cout << "Invalid option.\n";
    }
}