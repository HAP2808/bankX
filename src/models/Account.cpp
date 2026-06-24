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
    balance = balance + amount;
    std::cout << "Amount " << amount << " credited to account number: " << accountNumber << std::endl;
}

void Account::withdraw(double amount) {
    if (amount < balance)
    {
        balance = balance - amount;
        return;
    }
    std::cout << "NOT ENOUGH BALANCE" << std::endl;
}
