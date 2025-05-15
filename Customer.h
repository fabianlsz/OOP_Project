#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    std::string name;
    std::string vorname;
    std::string email;
    std::string adresse;
    std::string bemerkungen;
    bool gdprDeleted;

    Customer(const std::string& name,
             const std::string& vorname,
             const std::string& email,
             const std::string& adresse,
             const std::string& bemerkungen,
             bool gdprDeleted = false);
};

#endif