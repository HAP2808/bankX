#pragma once

#include <vector>

#include "models/Account.h"

class AccountService{
    private:
        std::vector<Account> accounts;
    
    public:
        void createAccount();
        void deposit();
        void withdraw();
        void displayBalance() const;
};