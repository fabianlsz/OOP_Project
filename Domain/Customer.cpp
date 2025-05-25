#include "Customer.h"

// Constructor
Customer::Customer(const string &name, const string &firstname, const string &email, const string &password,
                   const string &address, const string &notes)
    : User(email, password, UserType::CUSTOMER), firstName(firstname), name(name), email(email), password(password),
      notes(notes), address(address) {
}


string Customer::getName() const {
    return name;
}

string Customer::getEmail() const {
    return email;
}
