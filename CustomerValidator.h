#ifndef CUSTOMERVALIDATOR_H
#define CUSTOMERVALIDATOR_H

#include "Customer.h"
#include "CustomerRepository.h"
#include <string>

class CustomerValidator {
public:
    static void validate(const Customer& customer, const CustomerRepository& repo);
};

#endif