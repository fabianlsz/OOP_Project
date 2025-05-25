#include "StartDataMK.h"

void StartDataMK::initCustomers(CustomerRepository& repo) {
    repo.addCustomer(Customer("Meier", "Laura", "laura.meier@example.com", "pwd", "Hauptstr. 5", "Stammkunde"));
    repo.addCustomer(Customer("Schulz", "Tom", "tom.schulz@example.com", "pwd", "Nebenweg 8", ""));
}

std::vector<Employee> StartDataMK::initEmployees() {
    return {
        Employee("Mustermann", "Max", "max@test.de", "Verkäufer", "03.07.1996", 2100.0),
        Employee("Müller", "Anna", "anna@test.de", "Beraterin", "12.11.1988", 2700.0)
    };
}