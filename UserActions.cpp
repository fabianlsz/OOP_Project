#include "UserActions.h"

std::string UserActions::getAvailableActionsForRole(const std::string& role) {
    if (role == "Mitarbeiter") {
        return "Kunden verwalten, Bestellungen verwalten, Produkte verwalten";
    } else if (role == "Kunde") {
        return "Produkte ansehen, Reservierung erstellen, Profil anpassen";
    }
    return "Keine Aktionen verfügbar";
}