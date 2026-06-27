#pragma once

#include "Account.h"

class SavingsAccount : public Account {
    private:
        double interestRate;
        double minimumBalance;
        
    public:
        SavingsAccount(long long accountNumber, long long customerId, double balance,
                   double interestRate, double minimumBalance)
            : Account(accountNumber, customerId, balance),
            interestRate(interestRate),
            minimumBalance(minimumBalance) {}

        std::string getType() const override { return "SAVINGS"; }

        double getInterestRate() const { return interestRate; }
        double getMinimumBalance() const { return minimumBalance; }
};
