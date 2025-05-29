#pragma once

#include "../Controller/OrderService.h"
#include "../Domain/User.h"

class EmployeeUI {
    OrderService& orderService;
    const User& currentUser;

public:
    EmployeeUI(OrderService& service, const User& user);

    void run();
    static void showMenu();
    void handleManageOrders();
    void handleConfirmOrder();
    void handleUpdateOrder();
    void handleSetOrderCompleted();
    void handleAdoptOrder();
    void handleViewAllOrders();
};