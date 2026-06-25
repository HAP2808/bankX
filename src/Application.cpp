// Application entry point.

#include <iostream>

#include "application/Application.h"
#include "services/CustomerService.h"
#include "services/AccountService.h"

void Application::run() {
    Menu menu;
    CustomerService customerService;
    AccountService accountService;

    bool running = true;

    while (running)
    {
        int choice = menu.display();

        switch(choice)
        {
            case 1:
                std::cout << "Create Customer\n\n";
                customerService.createCustomer();
                break;

            case 2: {
                double balance;
                long long customerId;
                long accountNumber;
                const Customer* customer;
                std::cout << "Create Account\n\n";
                
                std::cout << "Enter customer ID: \n";
                std::cin >> customerId;

                std::cout << "Opening Balance: \n";
                std::cin >> balance;

                customer = customerService.getCustomerById(customerId);
                if (!customer)
                {
                    std::cout << "Customer does not exist. \nPlease create customer.\n";
                    break;
                }
                
                accountNumber = accountService.createAccount(customerId, balance);
                if (accountNumber != -1)
                {
                    std::cout << "Account created: " << accountNumber << std::endl;
                }
                break;
            }

            case 3:
                std::cout << "Deposit\n\n";
                break;

            case 4:
                std::cout << "Withdraw\n\n";
                break;

            case 5:
                std::cout << "Transfer\n\n";
                break;
            
            case 6: {
                std::cout << "View Balance\n\n";
                
                long accountNumber;
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
            
            case 7:
                std::cout << "List Customers\n\n";
                customerService.listCustomers();
                break;

            case 8:
                std::cout << "\nThank you for choosing BankX!!\n";
                running = false;
                break;

            default:
                std::cout << "Invalid choice\n";
        }
    }
    
}