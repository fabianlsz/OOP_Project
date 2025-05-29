#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"
#include <string>
#include <ctime>

class Employee : public User {
private:
    std::string name;
    std::string firstName;
    std::string position;
    std::string birthDate;
    std::string shortCode;
    double salary;
    std::string notes;
    bool isAdmin;

public:
    Employee(const std::string& name, const std::string& firstName,
             const std::string& email, const std::string& password,
             const std::string& position, const std::string& birthDate,
             const std::string& shortCode, double salary,
             const std::string& notes = "", bool isAdmin = false);

    // Getters
    std::string getName() const;
    std::string getFirstName() const;
    std::string getPosition() const;
    std::string getBirthDate() const;
    std::string getShortCode() const;
    double getSalary() const;
    std::string getNotes() const;
    bool getIsAdmin() const;

    // Setters
    void setPosition(const std::string& position);
    void setSalary(double salary);
    void setNotes(const std::string& notes);
    void setIsAdmin(bool isAdmin);

    // Age calculation
    int getAge() const;

    // Profile update
    void updateProfile(const std::string& position, const std::string& notes);
};

#endif
