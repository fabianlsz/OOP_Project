#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string name;
    std::string vorname;
    std::string email;
    std::string rolle;

public:
    User(const std::string& name,
         const std::string& vorname,
         const std::string& email,
         const std::string& rolle);

    virtual ~User() = default;
    virtual std::string getInfo() const = 0;
};

#endif