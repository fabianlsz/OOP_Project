#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

#include <string>

class ProfileManager {
public:
    static void changePassword(const std::string& email, const std::string& oldPass, const std::string& newPass);
};

#endif