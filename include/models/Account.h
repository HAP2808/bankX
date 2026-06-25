#pragma once

class Account{
    private:
        long accountNumber;
        long long customerId;
        double balance;

    public:
        Account(long accountNumber, long long customerId, double balance): accountNumber(accountNumber), customerId(customerId), balance(balance) {}
       
        long getAccountNumber() const;
        long long getCustomerId() const;
        double getBalance() const;
        void deposit(double amount);
        bool withdraw(double amount);
};