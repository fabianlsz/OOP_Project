//
// Created by oli on 5/28/2025.
//
#include "EmployeeRepository.h"

void EmployeeRepository::addEmployee(const Employee& employee) {
    employees.push_back(employee);
}

std::optional<Employee> EmployeeRepository::findByEmail(const std::string& email) const {
    for (const auto& e : employees) {
        if (e.getEmail() == email) {
            return e;
        }
    }
    return std::nullopt;
}

const std::vector<Employee>& EmployeeRepository::getAll() const {
    return employees;
}
