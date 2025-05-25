#include "StartDataB.h"

std::vector<std::pair<std::string, std::string>> StartDataB::getUsers() {
    return {
        {"max@test.de", "pass123"},
        {"anna@test.de", "secure456"}
    };
}