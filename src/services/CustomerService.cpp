#include "services/CustomerService.h"
#include "utils/RandomUtils.h"

#include <algorithm>
#include <iostream>

/// @brief Create a new customer with Name, Email and 8 digit random customer ID.
///
/// @return Customer ID of newly generated customer. 
long long CustomerService::createCustomer() {
    std::string customerName, customerEmail;
    // Generate 8 digit random customer ID.
    long long customerId = generateNDigitID(8);
    
    std::cout << "Please enter your name:: \n";
    std::cin >> customerName;

    std::cout << "Please enter your email ID:: \n";
    std::cin >> customerEmail;

    // Create customer object and add it to the list.
    Customer customer = Customer(customerId, customerName, customerEmail);
    customers.push_back(customer);

    return customerId;
}

/// @brief List Name, Email and customer ID of all customers.
void CustomerService::listCustomers() const {
    std::cout << "Customers:: " << std::endl;
    for (const Customer& customer : customers)
    {
        std::cout << "Name:: " << customer.getName() << std::endl;
        std::cout << "EmailID:: " << customer.getEmail() << std::endl;
        std::cout << "CustomerID:: " << customer.getCustomerId() << std::endl;
    }
    std::cout << std::endl;
}

/// @brief Get all customers.
///
/// @return Return all existing customers.
std::vector<Customer> CustomerService::getAllCustomers() const {
    return customers;
}

/// @brief  Get customer by customerId.
/// @param customerId 
/// @return Return associated customer.
const Customer* CustomerService::getCustomerById(long long customerId) const {
    auto it = std::find_if(customers.cbegin(), customers.cend(),
        [customerId](const Customer& customer) {
            return customer.getCustomerId() == customerId;
        });

    if (it == customers.cend()) {
        return nullptr;
    }

    return &(*it);
}
