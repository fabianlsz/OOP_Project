#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
public:
    std::string name;
    std::string firstName;
    std::string email;
    std::string position;
    std::string birthDate;
    double salary;

    Employee(const std::string& name,
             const std::string& firstName,
             const std::string& email,
             const std::string& position,
             const std::string& birthDate,
             double salary)
        : name(name), firstName(firstName), email(email), position(position), birthDate(birthDate), salary(salary) {}

    Employee() : salary(0.0) {}
};

#endif 