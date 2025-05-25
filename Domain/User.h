#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using namespace std;

enum class UserType {
    EMPLOYEE,
    CUSTOMER
};

class User {
private:
    string email;
    string password;
    UserType userType;

public:
    // Constructor
    User(const string& email, const string& password, UserType userType);

    // getter
    string getEmail() const;
    UserType getUserType() const;

    // auth
    bool authenticate(const string& email, const string& password) const;

    // validare
    static bool isValidEmail(const string& email);
};

#endif // USER_H