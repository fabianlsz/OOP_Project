#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {
private:
    string name;
    string firstName;
    string email;
    string address;
    string notes;
    string password;
    string id;
    bool gdprDeleted;

public:
    // Constructor
    Customer(const string& name, const string& firstName, const string& email, const string& address, const string& notes);

    // GDPR anonymize
    void anonymize();

    // Getters
    string getName() const;
    string getEmail() const;

    // Setters
    void setName(const string& name);
    void setEmail(const string& email);

    // Validation
    static bool isValidEmail(const string& email);
};

#endif // CUSTOMER_H