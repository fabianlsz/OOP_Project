#include "Customer.h"

// Constructor
Customer::Customer(const string& id, const string& name, const string& email, const string& password)
    : id(id), name(name), email(email), password(password) {}

// Getters
string Customer::getId() const {
    return id;
}

string Customer::getName() const {
    return name;
}

string Customer::getEmail() const {
    return email;
}

string Customer::getPassword() const {
    return password;
}

// Set new password
void Customer::setPassword(const string& newPassword) {
    password = newPassword;
}

// Serialize Customer to JSON
string Customer::toJSON() const {
    json j = {
        {"id", id},
        {"name", name},
        {"email", email},
        {"password", password}
    };
    return j.dump();
}

// Deserialize Customer from JSON
Customer Customer::fromJSON(const string& jsonString) {
    json j = json::parse(jsonString);
    return Customer(j["id"], j["name"], j["email"], j["password"]);
}