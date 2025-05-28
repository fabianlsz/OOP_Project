#include "Employee.h"

Employee::Employee(const std::string& name,
                   const std::string& vorname,
                   const std::string& email,
                   const std::string& position,
                   const std::string& geburtsdatum,
                   double gehalt)
    : User(email, password, UserType::EMPLOYEE),name(name), vorname(vorname), email(email), position(position),
      geburtsdatum(geburtsdatum), gehalt(gehalt) {}