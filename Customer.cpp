#include "Customer.h"

Customer::Customer(const std::string& name,
                   const std::string& firstName,
                   const std::string& email,
                   const std::string& address,
                   const std::string& bemerkungen,
                   bool gdprDeleted)
    : name(name), firstName(firstName), email(email), address(address), bemerkungen(bemerkungen), gdprDeleted(gdprDeleted) {}