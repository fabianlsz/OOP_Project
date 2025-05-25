//
// Created by ion on 5/25/25.
//

#ifndef EMPLOYEEUI_H
#define EMPLOYEEUI_H

class CustomerController;

class EmployeeUI {
    CustomerController& customerController;
    public:
    explicit EmployeeUI(CustomerController& customerController);
    void showMenu();

    void handleAddProduct();
    void handleSelectOrder();
};



#endif //EMPLOYEEUI_H
