#include "Customer.h"
#include <regex>

using namespace std;

// constructor
Customer::Customer(const string& name, const string& firstName, const string& email, const string& address, const string& notes)
    : name(name), firstName(firstName), email(email), address(address), notes(notes), gdprDeleted(false) {}

// GDPR ???
void Customer::anonymize() {
    name = "Customer";
    firstName = "Unknown";
    email = "";
    address = "";
    notes = "";
    gdprDeleted = true;
}

// getter
string Customer::getName() const {
    return name;
}

string Customer::getEmail() const {
    return email;
}

// setters
void Customer::setName(const string& name) {
    this->name = name;
}

void Customer::setEmail(const string& email) {
    this->email = email;
}

// validare
bool Customer::isValidEmail(const string& email) {
    const regex emailRegex(R"((\w+)(\.{0,1})(\w*)@(\w+)\.(\w+))");
    return regex_match(email, emailRegex);
}