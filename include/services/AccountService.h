#pragma once

#include <vector>

#include "models/Account.h"

class AccountService{
    private:
        std::vector<Account> accounts;
    
    public:
        long long createAccount(long long customerId, double balance);
        bool deposit(long long accountNumber, double amount);
        bool withdraw(long long accountNumber, double amount);
        bool transfer(long long sourceAccountNum, long long destAccountNum, double amount);
        const Account* getAccountByAccountNumber(long long accountNumber) const;
};