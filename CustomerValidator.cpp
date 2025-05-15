#include "CustomerValidator.h"
#include <regex>
#include <stdexcept>

void CustomerValidator::validate(const Customer& c, const CustomerRepository& repo) {
    if (!c.gdprDeleted) {
        if (c.name.empty() || c.vorname.empty() || c.email.empty() || c.adresse.empty())
            throw std::runtime_error("Alle Felder außer 'Bemerkungen' müssen ausgefüllt sein, wenn der Kunde nicht anonymisiert ist.");
    } else {
        if (c.name.empty() || c.vorname.empty())
            throw std::runtime_error("Name und Vorname sind erforderlich, wenn der Kunde anonymisiert wurde (GDPR).");
    }

    std::regex emailRegex(R"(^\S+@\S+\.\S+$)");
    if (!std::regex_match(c.email, emailRegex))
        throw std::runtime_error("Ungültiges E-Mail-Format.");

    if (repo.findByEmail(c.email).has_value())
        throw std::runtime_error("Die E-Mail-Adresse ist bereits vergeben.");
}