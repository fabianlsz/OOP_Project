#include "Employee.h"
#include <sstream>
#include <iomanip>

Employee::Employee(const std::string& name, const std::string& firstName,
                   const std::string& email, const std::string& password,
                   const std::string& position, const std::string& birthDate,
                   const std::string& shortCode, double salary,
                   const std::string& notes, bool isAdmin)
    : User(email, password, isAdmin ? UserType::ADMIN : UserType::EMPLOYEE),
      name(name), firstName(firstName), position(position), birthDate(birthDate),
      shortCode(shortCode), salary(salary), notes(notes), isAdmin(isAdmin) {}

std::string Employee::getName() const {
    return name;
}

std::string Employee::getFirstName() const {
    return firstName;
}

std::string Employee::getPosition() const {
    return position;
}

std::string Employee::getBirthDate() const {
    return birthDate;
}

std::string Employee::getShortCode() const {
    return shortCode;
}

double Employee::getSalary() const {
    return salary;
}

std::string Employee::getNotes() const {
    return notes;
}

bool Employee::getIsAdmin() const {
    return isAdmin;
}

void Employee::setPosition(const std::string& position) {
    this->position = position;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

void Employee::setNotes(const std::string& notes) {
    this->notes = notes;
}

void Employee::setIsAdmin(bool isAdmin) {
    this->isAdmin = isAdmin;
    userType = isAdmin ? UserType::ADMIN : UserType::EMPLOYEE;
}

int Employee::getAge() const {
    // Simplified age calculation - in real implementation would parse birthDate properly
    return 30; // Placeholder
}

void Employee::updateProfile(const std::string& position, const std::string& notes) {
    this->position = position;
    this->notes = notes;
}
