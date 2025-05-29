#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <ctime>

class Product {
private:
    std::string productId;
    std::string name;
    std::string category;
    double price;
    std::string expirationDate;
    int stock;
    std::string notes;
    bool active;

public:
    Product(const std::string& productId, const std::string& name,
            const std::string& category, double price,
            const std::string& expirationDate, int stock,
            const std::string& notes = "");

    // Getters
    std::string getProductId() const;
    std::string getName() const;
    std::string getCategory() const;
    double getPrice() const;
    std::string getExpirationDate() const;
    int getStock() const;
    std::string getNotes() const;
    bool isActive() const;

    // Setters
    void setName(const std::string& name);
    void setCategory(const std::string& category);
    void setPrice(double price);
    void setExpirationDate(const std::string& expirationDate);
    void setStock(int stock);
    void setNotes(const std::string& notes);
    void setActive(bool active);

    // Stock management
    void increaseStock(int amount);
    void decreaseStock(int amount);
    bool isAvailable() const;
    bool isExpired() const;
};

#endif
