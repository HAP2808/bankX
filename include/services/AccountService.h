#pragma once

#include <vector>

#include "models/Account.h"

class AccountService{
    private:
        std::vector<Account> accounts;
    
    public:
        bool createAccount(long long customerId, double balance);
        void deposit();
        void withdraw();
        void displayBalance() const;
};