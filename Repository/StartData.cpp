#include "StartDataB.h"
#include <algorithm>


void StartData::initializeData(CustomerRepository& customerRepo,
                              EmployeeRepository& employeeRepo,
                              ProductRepository& productRepo,
                              OrderRepository& orderRepo) {
    initCustomers(customerRepo);
    initEmployees(employeeRepo);
    initProducts(productRepo);
    initOrders(orderRepo);
}

void StartData::initCustomers(CustomerRepository& repo) {
    repo.addCustomer(Customer("Meier", "Laura", "laura.meier@example.com", "pwd123",
                             "+49 123 456789", "Hauptstr. 5, 12345 Berlin", "Stammkunde"));
    repo.addCustomer(Customer("Schulz", "Tom", "tom.schulz@example.com", "pwd456",
                             "+49 987 654321", "Nebenweg 8, 54321 Hamburg", ""));
    repo.addCustomer(Customer("Wagner", "Anna", "anna.wagner@example.com", "pwd789",
                             "+49 555 123456", "Parkstr. 12, 67890 München", "VIP Kunde"));
    repo.addCustomer(Customer("Fischer", "Max", "max.fischer@example.com", "pwd321",
                             "+49 444 987654", "Waldweg 3, 98765 Köln", ""));
    repo.addCustomer(Customer("Weber", "Lisa", "lisa.weber@example.com", "pwd654",
                             "+49 333 456789", "Bergstr. 7, 13579 Frankfurt", "Neukunde"));
}

void StartData::initEmployees(EmployeeRepository& repo) {
    repo.addEmployee(Employee("Mustermann", "Max", "max@grocery.com", "admin123",
                             "Verkäufer", "1996-07-03", "MM", 2100.0, "Teamleiter", true));
    repo.addEmployee(Employee("Müller", "Anna", "anna@grocery.com", "emp456",
                             "Beraterin", "1988-11-12", "AM", 2700.0, "Kundenbetreuung", false));
    repo.addEmployee(Employee("Schmidt", "Peter", "peter@grocery.com", "emp789",
                             "Lagerarbeiter", "1992-03-15", "PS", 2000.0, "", false));
    repo.addEmployee(Employee("Klein", "Sarah", "sarah@grocery.com", "emp321",
                             "Kassiererin", "1995-09-22", "SK", 1800.0, "", false));
    repo.addEmployee(Employee("Bauer", "Michael", "michael@grocery.com", "emp654",
                             "Abteilungsleiter", "1985-01-08", "MB", 3200.0, "Obst & Gemüse", false));
}

void StartData::initProducts(ProductRepository& repo) {
    repo.addProduct(Product("MILK001", "Vollmilch 3.5%", "Milchprodukte", 1.29,
                           "2025-06-15", 50, "1L Packung"));
    repo.addProduct(Product("BREAD001", "Vollkornbrot", "Backwaren", 2.49,
                           "2025-06-05", 25, "500g Laib"));
    repo.addProduct(Product("APPLE001", "Äpfel Gala", "Obst", 2.99,
                           "2025-06-10", 100, "1kg Beutel"));
    repo.addProduct(Product("RICE001", "Basmati Reis", "Getreide", 3.99,
                           "2026-12-31", 75, "1kg Packung"));
    repo.addProduct(Product("CHEES001", "Gouda Käse", "Milchprodukte", 4.99,
                           "2025-07-20", 30, "200g Packung"));
    repo.addProduct(Product("TOMAT001", "Tomaten", "Gemüse", 3.49,
                           "2025-06-08", 80, "1kg"));
    repo.addProduct(Product("PASTA001", "Spaghetti", "Teigwaren", 1.99,
                           "2026-03-15", 60, "500g Packung"));
    repo.addProduct(Product("YOGUR001", "Naturjoghurt", "Milchprodukte", 0.89,
                           "2025-06-12", 40, "150g Becher"));
    repo.addProduct(Product("BANAN001", "Bananen", "Obst", 1.79,
                           "2025-06-07", 120, "1kg"));
    repo.addProduct(Product("CHICK001", "Hähnchenbrust", "Fleisch", 8.99,
                           "2025-06-03", 20, "500g"));
}

void StartData::initOrders(OrderRepository& repo) {
    // Add some sample orders/reservations
    repo.addOrder(Order("ORD001", "MILK001", "2025-06-01", "2025-06-03",
                       "laura.meier@example.com", "max@grocery.com", "Eilbestellung"));
    repo.addOrder(Order("ORD002", "BREAD001", "2025-06-02", "2025-06-04",
                       "tom.schulz@example.com", "", "Reservierung"));
    repo.addOrder(Order("ORD003", "APPLE001", "2025-06-01", "2025-06-02",
                       "anna.wagner@example.com", "anna@grocery.com", ""));
}
