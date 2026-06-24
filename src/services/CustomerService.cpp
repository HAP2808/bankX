#include "services/CustomerService.h"
#include "utils/RandomUtils.h"

#include <algorithm>
#include <iostream>

void CustomerService::createCustomer() {
    std::string customerName, customerEmail;
    long long customerId = generateNDigitID(8);
    
    std::cout << "Please enter your name:: \n";
    std::cin >> customerName;

    std::cout << "Please enter your email ID:: \n";
    std::cin >> customerEmail;

    Customer customer = Customer(customerId, customerName, customerEmail);
    customers.push_back(customer);
}

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

std::vector<Customer> CustomerService::getAllCustomers() const {
    return customers;
}

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
