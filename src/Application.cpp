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
                std::cout << "Create Customer\n";
                customerService.createCustomer();
                break;

            case 2:
                std::cout << "Create Account\n";
                accountService.createAccount();
                break;

            case 3:
                std::cout << "Deposit\n";
                break;

            case 4:
                std::cout << "Withdraw\n";
                break;

            case 5:
                std::cout << "Transfer\n";
                break;
            
            case 6:
                std::cout << "View Balance\n";
                break;
            
            case 7:
                std::cout << "List Customers\n";
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