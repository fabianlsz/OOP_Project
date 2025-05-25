#include <iostream>
#include "../Repository/CustomerRepository.h"
#include "../Controller/CustomerManager.h"
#include "../Controller/CustomerValidator.h"
#include "../Controller/UserActions.h"
#include "../Repository/StartDataMK.h"

void teste_cezar() {
    CustomerRepository custRepo;
    // Startdaten (S_MK): Beispielkunden hinzufügen
    StartDataMK::initCustomers(custRepo);
    // K1 + K5: Neuer Kunde mit Validierung hinzufügen
    Customer newCustomer("Müller", "Lisa", "lisa@example.com", "x", "Bahnhofstr. 9", "");
    CustomerManager manager(custRepo);
    std::cout << "=== Kunde hinzufügen ===\n";
    try {
        CustomerValidator::validate(newCustomer, custRepo);
        manager.createCustomer(newCustomer);
        std::cout << "Kunde erfolgreich hinzugefügt.\n";
    } catch (const std::exception& e) {
        std::cerr << "Fehler bei Validierung: " << e.what() << "\n";
    }
    // K2: Kunde anonymisieren
    std::cout << "\n=== Kunde anonymisieren ===\n";
    manager.anonymizeCustomer("tom.schulz@example.com");
    for (const auto& c : custRepo.getAll()) {
        std::cout << "Kunde: " << c.getFirstName() << " " << c.getName()
 << " | E-Mail: " << c.getEmail()
 << " | GDPR: " << (c.isGdprDeleted() ? "Ja" : "Nein") << "\n";
    }
    // A3: Benutzeraktionen anzeigen
    std::cout << "\n=== Benutzeraktionen ===\n";
    std::cout << "Kunde darf: " << UserActions::getAvailableActionsForRole("Kunde") << "\n";
    std::cout << "Mitarbeiter darf: " << UserActions::getAvailableActionsForRole("Mitarbeiter") << "\n";
}