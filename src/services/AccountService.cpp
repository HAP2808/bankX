#include "services/AccountService.h"
#include "utils/RandomUtils.h"

#include <iostream>
#include <string>
#include <algorithm>

long AccountService::createAccount(long long customerId, double balance) {
    if (balance < 1000) {
        std::cout << "Need 1000 as minimum balance." << std::endl;
        return -1;
    }

    long accountNumber = generateNDigitID(12);
    Account account = Account(accountNumber, customerId, balance);
    accounts.push_back(account);
    return accountNumber;
}

const Account* AccountService::getAccountByAccountNumber(long accountNumber) const {
    auto it = std::find_if(accounts.cbegin(), accounts.cend(),
        [accountNumber](const Account& account) {
            return account.getAccountNumber() == accountNumber;
        });

    if (it == accounts.cend()) {
        return nullptr;
    }

    return &(*it);
}

bool AccountService::deposit(long accountNumber, double amount) {
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

bool AccountService::withdraw(long accountNumber, double amount) {
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
