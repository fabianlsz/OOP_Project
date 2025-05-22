#include "Customer.h"

// Constructor
Customer::Customer(const string& name, const string& firstname, const string& email, const string& password, const string& notes)
    : firstName(firstname), name(name), email(email), password(password), notes(notes) {}


string Customer::getName() const {
    return name;
}

string Customer::getEmail() const {
    return email;
}

