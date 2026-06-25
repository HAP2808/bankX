#pragma once

#include <vector>

#include "models/Account.h"

class AccountService{
    private:
        std::vector<Account> accounts;
    
    public:
        long createAccount(long long customerId, double balance);
        bool deposit(long accountNumber, double amount);
        bool withdraw(long accountNumber, double amount);
        const Account* getAccountByAccountNumber(long accountNumber) const;
};