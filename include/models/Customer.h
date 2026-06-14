#pragma once

#include <string>

class Customer
{
private:
    int customerId;
    std::string customerName;
    std::string customerEmail;

public:
    Customer(int id, const std::string &name, const std::string &email) : customerId(id), customerName(name), customerEmail(email) {}

    int getCustomerId() const;
    std::string getName() const;
    std::string getEmail() const;
};