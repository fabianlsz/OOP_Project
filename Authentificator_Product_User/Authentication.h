#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include <unordered_map>

class Authentication {
private:
    std::unordered_map<std::string, std::string> credentials;

public:
    void addUser(const std::string& email, const std::string& password);
    bool authenticate(const std::string& email, const std::string& password) const;
};

#endif