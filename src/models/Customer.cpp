#include "models/Customer.h"

long long Customer::getCustomerId() const {
    return customerId;
}

std::string Customer::getName() const {
    return customerName;
}

std::string Customer::getEmail() const {
    return customerEmail;
}
