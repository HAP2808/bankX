#pragma once

#include "Account.h"

class CurrentAccount : public Account{
    private:
        double overdraftLimit;

    public:
        CurrentAccount(long long accountNumber, long long customerId, double balance, double overdraftLimit)
        : Account(accountNumber, customerId, balance), overdraftLimit(overdraftLimit) {}

        std::string getType() const override { return "CURRENT"; }

        double getOverdraftLimit() const { return overdraftLimit; }
};
