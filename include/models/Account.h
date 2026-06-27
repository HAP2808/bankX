#pragma once

#include <string>

class Account{
    private:
        long long accountNumber;
        long long customerId;
        double balance;

    public:
        Account(long long accountNumber, long long customerId, double balance): accountNumber(accountNumber), customerId(customerId), balance(balance) {}
       
        virtual ~Account() = default;
        
        virtual std::string getType() const = 0;
        long long getAccountNumber() const;
        long long getCustomerId() const;
        double getBalance() const;
        void deposit(double amount);
        bool withdraw(double amount);
};
