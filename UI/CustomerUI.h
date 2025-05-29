#ifndef CUSTOMERUI_H
#define CUSTOMERUI_H

#pragma once
#include "../Controller/OrderService.h"

class CustomerUI {
    OrderService& orderService;
    const User& currentUser;
public:
    CustomerUI(OrderService& service, const User& user) : orderService(service), currentUser(user) {}
    void showMenu();
    void handlePlaceOrder();
    void handleViewProducts();
};


#endif //CUSTOMERUI_H
