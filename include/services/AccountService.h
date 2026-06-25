#pragma once

#include <vector>

#include "models/Account.h"

class AccountService{
    private:
        std::vector<Account> accounts;
    
    public:
        long createAccount(long long customerId, double balance);
        void deposit();
        void withdraw();
        void displayBalance() const;
        const Account* getAccountByAccountNumber(long accountNumber) const;
};