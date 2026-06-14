#pragma once

class Account{
    private:
        long accountNumber;
        int customerId;
        double balance;

    public:
        Account(long accountNumber, double balance): accountNumber(accountNumber), balance(balance) {}
        long getAccountNumber() const;
        double getBalance() const;
        void deposit(double amount);
        void withdraw(double amount);
};