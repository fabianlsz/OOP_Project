#include "User.h"

User::User(const std::string& name,
           const std::string& vorname,
           const std::string& email,
           const std::string& rolle)
    : name(name), vorname(vorname), email(email), rolle(rolle) {}