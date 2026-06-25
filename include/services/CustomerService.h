#pragma once

#include <vector>

#include "models/Customer.h"

class CustomerService{
    private:
        std::vector<Customer> customers;
    
    public:
        long long createCustomer();
        std::vector<Customer> getAllCustomers() const;
        const Customer* getCustomerById(long long customerId) const;
        void listCustomers() const;
        bool isCustomerExist(long long customerId) const;
};