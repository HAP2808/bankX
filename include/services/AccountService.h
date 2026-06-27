#pragma once

#include <vector>
#include <memory>

#include "models/Account.h"

class AccountService{
    private:
        std::vector<std::unique_ptr<Account>> accounts;
    
    public:
        long long createAccount(long long customerId, double balance, const std::string& accountType);
        bool deposit(long long accountNumber, double amount);
        bool withdraw(long long accountNumber, double amount);
        bool transfer(long long sourceAccountNum, long long destAccountNum, double amount);
        void listAccounts() const;
        const Account* getAccountByAccountNumber(long long accountNumber) const;
};