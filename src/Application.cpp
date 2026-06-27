// Application entry point.

#include <iostream>

#include "application/Application.h"
#include "services/CustomerService.h"
#include "services/AccountService.h"

void Application::run() {
    Menu menu;
    CustomerService customerService;
    AccountService accountService;

    // flag to control the application
    bool running = true;

    while (running)
    {
        // Display menu.
        int choice = menu.display();

        switch(choice)
        {
            // Create new customer.
            case 1: {
                long long customerId;
                std::cout << "Create Customer\n\n";
                customerId = customerService.createCustomer();
                
                std::cout << "Customer registered: " << customerId << std::endl;
                break;
            }

            // Create new account.
            case 2: {
                double balance;
                long long customerId;
                long long accountNumber;
                int accountTypeChoice;
                const Customer* customer;

                std::cout << "Create Account\n\n";
                
                std::cout << "Enter customer ID: \n";
                std::cin >> customerId;

                std::cout << "Opening Balance: \n";
                std::cin >> balance;

                std::cout << "Choose account type:\n";
                std::cout << "1. Current Account\n";
                std::cout << "2. Savings Account\n";
                std::cin >> accountTypeChoice;

                std::string accountType = (accountTypeChoice == 1) ? "CURRENT" : "SAVINGS";

                customer = customerService.getCustomerById(customerId);
                if (!customer)
                {
                    std::cout << "Customer does not exist. \nPlease create customer.\n";
                    break;
                }
                
                accountNumber = accountService.createAccount(customerId, balance, accountType);
                if (accountNumber != -1)
                {
                    std::cout << "Account created: " << accountNumber << std::endl;
                }
                break;
            }

            // Deposit to account.
            case 3: {
                std::cout << "Deposit\n\n";

                long long accountNumber;
                double amount;
                const Account* account;
                std::cout << "Enter Account Number:: ";
                std::cin >> accountNumber;

                std::cout << "Enter amount to deposit:: ";
                std::cin >> amount;
                accountService.deposit(accountNumber, amount);
                break;
            }

            // Withdraw from account.
            case 4: {
                std::cout << "Withdraw\n\n";

                long long accountNumber;
                double amount;
                const Account* account;
                std::cout << "Enter Account Number:: ";
                std::cin >> accountNumber;

                std::cout << "Enter amount to withdraw:: ";
                std::cin >> amount;
                accountService.withdraw(accountNumber, amount);
                break;
            }

            // Transfer from one account to another.
            case 5: {
                std::cout << "Transfer\n\n";

                long long sourceAccountNumber, destAccountNumber;
                double amount;
                std::cout << "Enter source account number:: ";
                std::cin >> sourceAccountNumber;

                std::cout << "Enter destination account number:: ";
                std::cin >> destAccountNumber;

                std::cout << "Enter amount to transfer:: ";
                std::cin >> amount;

                accountService.transfer(sourceAccountNumber, destAccountNumber, amount);
                break;
            }
            
            // View current balance of any account.
            case 6: {
                std::cout << "View Balance\n\n";
                
                long long accountNumber;
                const Account* account;
                std::cout << "Enter Account Number:: ";
                std::cin >> accountNumber;
                
                account = accountService.getAccountByAccountNumber(accountNumber);
                if (!account)
                {
                    std::cout << "Account does not exist. \nPlease create an account.\n";
                    break;
                }

                std::cout << "Account balance of " << accountNumber << ":: " << account->getBalance() << std::endl;                
                
                break;
            }
            
            // List all customers of BankX.
            case 7:
                std::cout << "List Customers\n\n";
                customerService.listCustomers();
                break;

            // List accounts created in BankX.
            case 8:
                std::cout << "List Accounts\n\n";
                accountService.listAccounts();
                break;

            // Exit application.
            case 9:
                std::cout << "\nThank you for choosing BankX!!\n";
                running = false;
                break;

            default:
                std::cout << "Invalid choice\n";
        }
    }
}