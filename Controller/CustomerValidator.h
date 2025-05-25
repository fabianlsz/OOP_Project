#ifndef CUSTOMERVALIDATOR_H
#define CUSTOMERVALIDATOR_H

#include "../Domain/Customer.h"
#include "../Repository/CustomerRepository.h"
#include <string>

class CustomerValidator {
public:
    static void validate(const Customer& customer, const CustomerRepository& repo);
};

#endif