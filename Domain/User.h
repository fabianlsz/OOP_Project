#ifndef USER_H
#define USER_H

#include <string>

enum class UserType {
    CUSTOMER,
    EMPLOYEE,
    ADMIN
};

class User {
protected:
    std::string email;
    std::string password;
    UserType userType;
    bool active;

public:
    User(const std::string& email, const std::string& password, UserType userType);
    virtual ~User() = default;

    std::string getEmail() const;
    UserType getUserType() const;
    bool isActive() const;
    void setActive(bool active);

    bool authenticate(const std::string& email, const std::string& password) const;
    static bool isValidEmail(const std::string& email);

    virtual void changePassword(const std::string& newPassword);
};

#endif
