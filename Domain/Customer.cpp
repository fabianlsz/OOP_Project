#include "Customer.h"
#include <algorithm>

Customer::Customer(const std::string& name, const std::string& firstName,
                   const std::string& email, const std::string& password,
                   const std::string& phone, const std::string& address,
                   const std::string& notes)
    : User(email, password, UserType::CUSTOMER), name(name), firstName(firstName),
      phone(phone), address(address), notes(notes), gdprDeleted(false) {}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getFirstName() const {
    return firstName;
}

std::string Customer::getPhone() const {
    return phone;
}

std::string Customer::getAddress() const {
    return address;
}

std::string Customer::getNotes() const {
    return notes;
}

bool Customer::isGdprDeleted() const {
    return gdprDeleted;
}

const std::vector<std::string>& Customer::getFavoriteProducts() const {
    return favoriteProducts;
}

void Customer::setNotes(const std::string& notes) {
    this->notes = notes;
}

void Customer::addFavoriteProduct(const std::string& productId) {
    if (std::find(favoriteProducts.begin(), favoriteProducts.end(), productId) == favoriteProducts.end()) {
        favoriteProducts.push_back(productId);
    }
}

void Customer::removeFavoriteProduct(const std::string& productId) {
    favoriteProducts.erase(
        std::remove(favoriteProducts.begin(), favoriteProducts.end(), productId),
        favoriteProducts.end()
    );
}

void Customer::anonymize(const std::string& customerId) {
    name = "Kunde-" + customerId;
    firstName = "Unbekannt";
    email = "";
    phone = "";
    address = "";
    notes = "";
    gdprDeleted = true;
    favoriteProducts.clear();
}

void Customer::updateProfile(const std::string& name, const std::string& firstName,
                            const std::string& phone, const std::string& address) {
    if (!gdprDeleted) {
        this->name = name;
        this->firstName = firstName;
        this->phone = phone;
        this->address = address;
    }
}
