#ifndef EMPLOYEEREPOSITORY_H
#define EMPLOYEEREPOSITORY_H

#include "../Domain/Employee.h"
#include <vector>
#include <optional>

class EmployeeRepository {
private:
    std::vector<Employee> employees;

public:
    void addEmployee(const Employee& employee);
    std::optional<Employee> findByEmail(const std::string& email) const;
    const std::vector<Employee>& getAll() const;
};

#endif
