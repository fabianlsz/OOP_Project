#include <iostream>
#include "Controller/AuthenticationController.h"
#include "Controller/CustomerManager.h"
#include "Controller/OrderService.h"
#include "Repository/CustomerRepository.h"
#include "Repository/StartDataMK.h"
#include "UI/EmployeeUI.h"
#include "UI/CustomerUI.h"
#include "Domain/User.h"

int main() {
    CustomerRepository customerRepo;
    StartDataMK::initCustomers(customerRepo);
    std::vector<Customer> customers = customerRepo.getAll();
    std::vector<Product> products;

    OrderService orderService(products, customers);
    AuthenticationController authController(customerRepo);

    User mockuser{"a", "b", UserType::EMPLOYEE};
        EmployeeUI employeeUI(orderService, mockuser);
        employeeUI.run();

    return 0;
}