#ifndef START_DATA_H
#define START_DATA_H

#include "../repository/CustomerRepository.h"
#include "../repository/EmployeeRepository.h"
#include "../repository/ProductRepository.h"
#include "../repository/OrderRepository.h"

class StartData {
public:
    static void initializeData(CustomerRepository& customerRepo,
                              EmployeeRepository& employeeRepo,
                              ProductRepository& productRepo,
                              OrderRepository& orderRepo);

private:
    static void initCustomers(CustomerRepository& repo);
    static void initEmployees(EmployeeRepository& repo);
    static void initProducts(ProductRepository& repo);
    static void initOrders(OrderRepository& repo);
};

#endif
