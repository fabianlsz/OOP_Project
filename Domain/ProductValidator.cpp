#include "ProductValidator.h"

void ProductValidator::validate(const std::string& id, double price, int stock) {
    if (id.empty())
        throw std::runtime_error("Produkt-ID darf nicht leer sein.");
    if (!std::regex_match(id, std::regex("^[A-Za-z0-9]+$")))
        throw std::runtime_error("Produkt-ID darf nur Buchstaben und Zahlen enthalten.");
    if (price < 0 || stock < 0)
        throw std::runtime_error("Preis und Lagerbestand dürfen nicht negativ sein.");
}