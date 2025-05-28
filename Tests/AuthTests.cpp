#include "../Domain/Customer.h"
#include "../Domain/Employee.h"
#include "../Repository/CustomerRepository.h"
#include "../Repository/EmployeeRepository.h"
#include "../Controller/AuthenticationController.h"
#include <iostream>
#include <cassert>

void testCustomerAuthentication() {
CustomerRepository customerRepo;
EmployeeRepository employeeRepo;

// Add a test customer (using full constructor)
Customer customer("Smith", "Alice", "alice@example.com", "pass123", "123 Main St", "Test Customer");
customerRepo.addCustomer(customer);

AuthenticationController auth(customerRepo, employeeRepo);

// Successful login
const User* user = auth.login("alice@example.com", "pass123");
assert(user != nullptr);
assert(user->getEmail() == "alice@example.com");
assert(user->getUserType() == UserType::CUSTOMER);

// Failed login (wrong password)
const User* fail1 = auth.login("alice@example.com", "wrongpass");
assert(fail1 == nullptr);

// Failed login (unknown email)
const User* fail2 = auth.login("notfound@example.com", "pass123");
assert(fail2 == nullptr);

std::cout << "✅ Customer authentication tests passed.\n";
}

void testEmployeeAuthentication() {
CustomerRepository customerRepo;
EmployeeRepository employeeRepo;

// Add a test employee (using full constructor)
Employee employee("Johnson", "Bob", "bob@company.com", "Developer", "1990-01-01", 50000.0);
employeeRepo.addEmployee(employee);

AuthenticationController auth(customerRepo, employeeRepo);

// Successful login
const User* user = auth.login("bob@company.com", "secure456");
assert(user != nullptr);
assert(user->getEmail() == "bob@company.com");
assert(user->getUserType() == UserType::EMPLOYEE);

// Failed login (wrong password)
const User* fail1 = auth.login("bob@company.com", "wrongpass");
assert(fail1 == nullptr);

// Failed login (unknown email)
const User* fail2 = auth.login("unknown@company.com", "secure456");
assert(fail2 == nullptr);

std::cout << "✅ Employee authentication tests passed.\n";

}

int runAuthTest() {
testCustomerAuthentication();
testEmployeeAuthentication();
std::cout << "🎉 All authentication tests passed.\n";
return 0;
}
