#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "User.h"

class Employee : public User {
public:
    std::string name;
    std::string vorname;
    std::string email;
    std::string position;
    std::string geburtsdatum;
    double gehalt;

    Employee(const std::string& name,
             const std::string& vorname,
             const std::string& email,
             const std::string& position,
             const std::string& geburtsdatum,
             double gehalt);
};

#endif