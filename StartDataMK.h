#ifndef STARTDATAMK_H
#define STARTDATAMK_H

#include "CustomerRepository.h"
#include "Employee.h"
#include <vector>

class StartDataMK {
public:
    static void initCustomers(CustomerRepository& repo);
    static std::vector<Employee> initEmployees();
};

#endif