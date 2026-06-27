// Menu for BankX services.
#include <iostream>

#include "application/Menu.h"

/// @brief Display the main menu and return the user's choice.
int Menu::display()
{
    std::cout << "\n";
    std::cout << "========================\n";
    std::cout << "      BankX\n";
    std::cout << "========================\n";

    std::cout << "1. Create Customer\n";
    std::cout << "2. Create Account\n";
    std::cout << "3. Deposit\n";
    std::cout << "4. Withdraw\n";
    std::cout << "5. Transfer\n";
    std::cout << "6. View Balance\n";
    std::cout << "7. List Customers\n";
    std::cout << "8. Exit\n";

    int choice;

    std::cout << "\nEnter choice:: ";
    std::cin >> choice;

    return choice;
}