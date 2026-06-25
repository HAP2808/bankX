#include "services/AccountService.h"
#include "utils/RandomUtils.h"

#include <iostream>
#include <string>
#include <algorithm>

long long AccountService::createAccount(long long customerId, double balance) {
    if (balance < 1000) {
        std::cout << "Need 1000 as minimum balance." << std::endl;
        return -1;
    }

    long long accountNumber = generateNDigitID(12);
    Account account = Account(accountNumber, customerId, balance);
    accounts.push_back(account);
    return accountNumber;
}

const Account* AccountService::getAccountByAccountNumber(long long accountNumber) const {
    auto it = std::find_if(accounts.cbegin(), accounts.cend(),
        [accountNumber](const Account& account) {
            return account.getAccountNumber() == accountNumber;
        });

    if (it == accounts.cend()) {
        return nullptr;
    }

    return &(*it);
}

bool AccountService::deposit(long long accountNumber, double amount) {
    auto it = std::find_if(accounts.begin(), accounts.end(),
        [accountNumber](Account& account) {
            return account.getAccountNumber() == accountNumber;
        });

    if (it == accounts.end()) {
        std::cout << "Account number " << accountNumber << " does not exist." << std::endl;
        return false;
    }

    it->deposit(amount);
    std::cout << "Amount " << amount << " credited to account number: " << accountNumber << std::endl;
    return true;
}

bool AccountService::withdraw(long long accountNumber, double amount) {
    auto it = std::find_if(accounts.begin(), accounts.end(),
        [accountNumber](Account& account) {
            return account.getAccountNumber() == accountNumber;
        });

    if (it == accounts.end()) {
        std::cout << "Account number " << accountNumber << " does not exist." << std::endl;
        return false;
    }

    if (!it->withdraw(amount)) {
        std::cout << "NOT ENOUGH BALANCE" << std::endl;
        return false;
    }

    std::cout << "Amount " << amount << " debited from account number: " << accountNumber << std::endl;
    return true;
}

bool AccountService::transfer(long long sourceAccNum, long long destAccNum, double amount) {
    auto sourceAccount = std::find_if(accounts.begin(), accounts.end(),
        [sourceAccNum](Account& account) {
            return account.getAccountNumber() == sourceAccNum;
        });

    if (sourceAccount == accounts.end()) {
        std::cout << "Source account Number " << sourceAccNum << " does not exist." << std::endl;
        return false;
    }

    auto destAccount = std::find_if(accounts.begin(), accounts.end(),
        [destAccNum](Account& account) {
            return account.getAccountNumber() == destAccNum;
        });

    if (destAccount == accounts.end()) {
        std::cout << "Destination account Number " << destAccNum << " does not exist." << std::endl;
        return false;
    }

    if (!sourceAccount->withdraw(amount)) {
        std::cout << "NOT ENOUGH BALANCE" << std::endl;
        return false;
    }

    destAccount->deposit(amount);

    std::cout << "Amount " << amount << " transferred successfully!!" << std::endl;
    return true;
}

void AccountService::listAccounts() const {
    std::cout << "Accounts:: " << std::endl;
    for (const Account& account : accounts)
    {
        std::cout << "Account ID:: " << account.getAccountNumber() << std::endl;
        std::cout << "Balance:: " << account.getBalance() << std::endl;
        std::cout << "Customer ID: " << account.getCustomerId() << std::endl; 
    }
    std::cout << std::endl;
}
