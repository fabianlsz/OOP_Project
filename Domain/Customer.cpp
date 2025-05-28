#include "Customer.h"

// Constructor
Customer::Customer(const string &name, const string &firstname, const string &email, const string &password,
                   const string &address, const string &notes)
    : User(email, password, UserType::CUSTOMER), firstName(firstname), name(name), email(email),
      notes(notes), address(address) {
}


string Customer::getName() const {
    return name;
}

string Customer::getEmail() const {
    return email;
}

void Customer::anonymize() {
    // TODO adapt this to the english fields
    // c.name = "Kunde-" + email;
    // c.vorname = "Unbekannt";
    // c.email = "";
    // c.adresse = "";
    // c.bemerkungen = "";
    // c.gdprDeleted = true;
}
