#ifndef PRODUCTVALIDATOR_H
#define PRODUCTVALIDATOR_H

#include <string>
#include <regex>
#include <stdexcept>

class ProductValidator {
public:
    static void validate(const std::string& id, double preis, int lagerbestand);
};

#endif