#pragma once

#include <vector>

#include "models/Customer.h"

class CustomerService{
    private:
        std::vector<Customer> customers;
    
    public:
        void createCustomer();
        void listCustomers() const;
};