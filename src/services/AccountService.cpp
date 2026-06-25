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