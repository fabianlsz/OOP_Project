#ifndef EMPLOYEEREPOSITORY_H
#define EMPLOYEEREPOSITORY_H

#include "../Domain/Employee.h"
#include <vector>
#include <optional>
#include <algorithm>

class EmployeeRepository {
private:
    std::vector<Employee> employees;
public:
    void addEmployee(const Employee& employee) {
        employees.push_back(employee);
    }

    bool updateEmployee(const std::string& email, const Employee& updated) {
        for (auto& e : employees) {
            if (e.email == email) {
                e = updated;
                return true;
            }
        }
        return false;
    }

    bool deleteEmployee(const std::string& email) {
        auto it = std::remove_if(employees.begin(), employees.end(),
                                 [&](const Employee& e) { return e.email == email; });
        if (it != employees.end()) {
            employees.erase(it, employees.end());
            return true;
        }
        return false;
    }

    std::optional<Employee> findByEmail(const std::string& email) const {
        for (const auto& e : employees) {
            if (e.email == email) return e;
        }
        return std::nullopt;
    }

    const std::vector<Employee>& getAll() const { return employees; }
};

#endif 