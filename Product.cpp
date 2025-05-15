#include "Product.h"

Product::Product(const std::string& id,
                 const std::string& name,
                 double preis,
                 int lagerbestand)
    : id(id), name(name), preis(preis), lagerbestand(lagerbestand) {}