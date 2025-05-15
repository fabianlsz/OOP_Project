#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include "User.h"
#include <vector>

using namespace std;

class Authenticator {
private:
    vector<User> users;

public:
    // Add a user to the system
    void addUser(const User& user);

    // login function
    const User* login(const string& email, const string& password) const;
};

#endif // AUTHENTICATOR_H