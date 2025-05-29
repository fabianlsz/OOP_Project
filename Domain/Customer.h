#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "User.h"

class Customer : public User {
private:
    std::string name;
    std::string firstName;
    std::string address;
    std::string notes;
    bool gdprDeleted;
public:
    Customer(const std::string& name, const std::string& firstName, const std::string& email, const std::string& password, const std::string& address, const std::string& notes)
        : User(email, password, UserType::CUSTOMER), name(name), firstName(firstName), address(address), notes(notes), gdprDeleted(false) {}

    // GDPR anonymize
    void anonymize() {
        name = "Kunde-" + getEmail();
        firstName = "Unbekannt";
        setEmail("");
        address = "";
        notes = "";
        gdprDeleted = true;
    }

    // Getters
    std::string getName() const { return name; }
    std::string getFirstName() const { return firstName; }
    std::string getAddress() const { return address; }
    std::string getNotes() const { return notes; }
    bool isGdprDeleted() const { return gdprDeleted; }

    // Setters
    void setName(const std::string& n) { name = n; }
    void setFirstName(const std::string& fn) { firstName = fn; }
    void setAddress(const std::string& a) { address = a; }
    void setNotes(const std::string& n) { notes = n; }
    void setEmail(const std::string& e) { User::email = e; }
};

#endif 