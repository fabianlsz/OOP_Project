//
// Created by ion on 5/25/25.
//

#ifndef EMPLOYEEUI_H
#define EMPLOYEEUI_H

class CustomerManager;

class EmployeeUI {
    CustomerManager& customerManager;
    public:
    explicit EmployeeUI(CustomerManager& customerManager): customerManager(customerManager) {};
    void showMenu();
    void run();

    void handleAddProduct();
    void handleSelectOrder();
};



#endif //EMPLOYEEUI_H
