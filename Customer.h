#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    std::string name;
    std::string firstName; // Renamed from vorname
    std::string email;
    std::string address;   // Renamed from adresse
    std::string bemerkungen;
    bool gdprDeleted;

    Customer(const std::string& name,
             const std::string& firstName,
             const std::string& email,
             const std::string& address,
             const std::string& bemerkungen,
             bool gdprDeleted = false);
};

#endif