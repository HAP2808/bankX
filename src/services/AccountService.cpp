#include "services/AccountService.h"
#include "utils/RandomUtils.h"

#include <iostream>
#include <string>

bool AccountService::createAccount(long long customerId, double balance) {
    if (balance < 1000) {
        std::cout << "Need 1000 as minimum balance." << std::endl;
        return false;
    }

    long accountNumber = generateNDigitID(12);
    Account account = Account(accountNumber, customerId, balance);
    accounts.push_back(account);
    return true;
}
