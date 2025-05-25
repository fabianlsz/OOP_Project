#include "Customer.h"

Customer::Customer(const std::string& name,
                   const std::string& vorname,
                   const std::string& email,
                   const std::string& adresse,
                   const std::string& bemerkungen,
                   bool gdprDeleted)
    : name(name), vorname(vorname), email(email), adresse(adresse),
      bemerkungen(bemerkungen), gdprDeleted(gdprDeleted) {}