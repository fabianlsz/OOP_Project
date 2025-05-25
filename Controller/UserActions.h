#ifndef USERACTIONS_H
#define USERACTIONS_H

#include <string>

class UserActions {
public:
    static std::string getAvailableActionsForRole(const std::string& role);
};

#endif