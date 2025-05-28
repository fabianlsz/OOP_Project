#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

#include "User.h"

using namespace std;

class Customer : public User {
private:
    string name;
    string firstName;
    string email;
    string address;
    string notes;
    //string password; //TODO remove password field already inherited from User
    string id;
    bool gdprDeleted;

public:
    // Constructor
    Customer(const string &name, const string &firstName, const string &email, const string &password,
             const string &address, const string &notes);

    // GDPR anonymize
    void anonymize();

    // Getters
    string getName() const;

    string getFirstName() const { return firstName;}

    string getEmail() const;

    string getAddress() const {return address;}
    // Setters
    void setName(const string &name);

    void setEmail(const string &email);

    bool isGdprDeleted() const {return gdprDeleted;}

    // Validation
    static bool isValidEmail(const string &email);
};

#endif // CUSTOMER_H
