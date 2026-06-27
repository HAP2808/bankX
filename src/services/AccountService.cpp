#include "services/AccountService.h"
#include "utils/RandomUtils.h"
#include "models/CurrentAccount.h"
#include "models/SavingsAccount.h"

#include <iostream>
#include <string>
#include <algorithm>

/// @brief Create a new account.
/// @param customerId 
/// @param balance 
/// @param accountType
/// @return Return account number of newly created account.
long long AccountService::createAccount(long long customerId, double balance, const std::string& accountType) {
    if (balance < 1000) {
        std::cout << "Need 1000 as minimum balance." << std::endl;
        return -1;
    }

    long long accountNumber = generateNDigitID(12);

    std::unique_ptr<Account> account;

    if (accountType == "CURRENT")
    {
        account = std::make_unique<CurrentAccount>(accountNumber, customerId, balance, 5000.0);
    }
    else if (accountType == "SAVINGS") {
        account = std::make_unique<SavingsAccount>(accountNumber, customerId, balance, 4.5, 1000.0);
    }
    else {
        std::cout << "Invalid account type." << std::endl;
        return -1;
    }
    
    accounts.push_back(std::move(account));
    return accountNumber;
}

/// @brief Get account by an account number.
/// @param accountNumber 
/// @return Return associated account.
const Account* AccountService::getAccountByAccountNumber(long long accountNumber) const {
    auto it = std::find_if(accounts.cbegin(), accounts.cend(),
        [accountNumber](const std::unique_ptr<Account>& account) {
            return account->getAccountNumber() == accountNumber;
        });

    if (it == accounts.cend()) {
        return nullptr;
    }

    return it->get();
}

/// @brief Deposit an amount to the account.
/// @param accountNumber 
/// @param amount 
/// @return Return true / false based on successful transaction.
bool AccountService::deposit(long long accountNumber, double amount) {
    auto it = std::find_if(accounts.begin(), accounts.end(),
        [accountNumber](const std::unique_ptr<Account>& account) {
            return account->getAccountNumber() == accountNumber;
        });

    if (it == accounts.end()) {
        std::cout << "Account number " << accountNumber << " does not exist." << std::endl;
        return false;
    }

    (*it)->deposit(amount);
    std::cout << "Amount " << amount << " credited to account number: " << accountNumber << std::endl;
    return true;
}

/// @brief Withdraw an amount from the account.
/// @param accountNumber 
/// @param amount 
/// @return Return true / false based on successful transaction.
bool AccountService::withdraw(long long accountNumber, double amount) {
    auto it = std::find_if(accounts.begin(), accounts.end(),
        [accountNumber](const std::unique_ptr<Account>& account) {
            return account->getAccountNumber() == accountNumber;
        });

    if (it == accounts.end()) {
        std::cout << "Account number " << accountNumber << " does not exist." << std::endl;
        return false;
    }

    if (!(*it)->withdraw(amount)) {
        std::cout << "NOT ENOUGH BALANCE" << std::endl;
        return false;
    }

    std::cout << "Amount " << amount << " debited from account number: " << accountNumber << std::endl;
    return true;
}

/// @brief Transfer an amount from one account to another.
/// @param sourceAccNum 
/// @param destAccNum 
/// @param amount 
/// @return Return true / false based on successful transaction.
bool AccountService::transfer(long long sourceAccNum, long long destAccNum, double amount) {
    auto sourceAccount = std::find_if(accounts.begin(), accounts.end(),
        [sourceAccNum](const std::unique_ptr<Account>& account) {
            return account->getAccountNumber() == sourceAccNum;
        });

    if (sourceAccount == accounts.end()) {
        std::cout << "Source account Number " << sourceAccNum << " does not exist." << std::endl;
        return false;
    }

    auto destAccount = std::find_if(accounts.begin(), accounts.end(),
        [destAccNum](const std::unique_ptr<Account>& account) {
            return account->getAccountNumber() == destAccNum;
        });

    if (destAccount == accounts.end()) {
        std::cout << "Destination account Number " << destAccNum << " does not exist." << std::endl;
        return false;
    }

    if (!(*sourceAccount)->withdraw(amount)) {
        std::cout << "NOT ENOUGH BALANCE" << std::endl;
        return false;
    }

    (*destAccount)->deposit(amount);

    std::cout << "Amount " << amount << " transferred successfully!!" << std::endl;
    return true;
}

/// @brief list all existing accounts.
void AccountService::listAccounts() const {
    std::cout << "Accounts:: " << std::endl;
    for (const std::unique_ptr<Account>& account : accounts)
    {
        std::cout << "Account ID:: " << account->getAccountNumber() << std::endl;
        std::cout << "Balance:: " << account->getBalance() << std::endl;
        std::cout << "Customer ID: " << account->getCustomerId() << std::endl; 
    }
    std::cout << std::endl;
}
