#pragma once

#include <string>

class Customer
{
private:
    long long customerId;
    std::string customerName;
    std::string customerEmail;

public:
    Customer(long long id, const std::string &name, const std::string &email) : customerId(id), customerName(name), customerEmail(email) {}

    long long getCustomerId() const;
    std::string getName() const;
    std::string getEmail() const;
};