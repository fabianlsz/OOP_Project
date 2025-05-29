#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include <vector>

class Customer : public User {
private:
    std::string name;
    std::string firstName;
    std::string phone;
    std::string address;
    std::string notes;
    bool gdprDeleted;
    std::vector<std::string> favoriteProducts;

public:
    Customer(const std::string& name, const std::string& firstName,
             const std::string& email, const std::string& password,
             const std::string& phone, const std::string& address,
             const std::string& notes = "");

    // Getters
    std::string getName() const;
    std::string getFirstName() const;
    std::string getPhone() const;
    std::string getAddress() const;
    std::string getNotes() const;
    bool isGdprDeleted() const;
    const std::vector<std::string>& getFavoriteProducts() const;

    // Setters
    void setNotes(const std::string& notes);

    // Favorite products management
    void addFavoriteProduct(const std::string& productId);
    void removeFavoriteProduct(const std::string& productId);

    // GDPR anonymization
    void anonymize(const std::string& customerId);

    // Update profile
    void updateProfile(const std::string& name, const std::string& firstName,
                      const std::string& phone, const std::string& address);
};

#endif
