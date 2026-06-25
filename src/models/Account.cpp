#include "models/Account.h"

#include <iostream>

long Account::getAccountNumber() const {
    return accountNumber;
}

long long Account::getCustomerId() const {
    return customerId;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount > balance) {
        return false;
    }
    balance -= amount;
    return true;
}
