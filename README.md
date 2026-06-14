# BankX - Banking Management System (Under development)

A modern C++ banking management system designed with clean architecture principles, featuring customer and account management, multiple account types, and fund transfer capabilities.

## Overview

BankX is a console-based banking application that provides a comprehensive solution for managing customers, accounts, and banking operations. The system is built using C++20 with a layered architecture pattern, ensuring scalability, maintainability, and separation of concerns.

## Features

### Core Banking Operations
- **Customer Management**
  - Create and manage customer profiles
  - Store customer information (ID, name, email)
  
- **Account Management**
  - Create accounts for customers
  - Support for multiple account types:
    - **Current Accounts** - For business and frequent transactions
    - **Savings Accounts** - For personal savings with interest considerations
  - View account balance and details

- **Transactions**
  - Deposit funds into accounts
  - Withdraw funds with balance validation
  - Transfer funds between accounts

### Architecture

The project follows a **layered architecture** pattern:

```
┌─────────────────────────────┐
│    Application Layer        │
│  (Menu, User Interface)     │
├─────────────────────────────┤
│    Service Layer            │
│  (Business Logic)           │
├─────────────────────────────┤
│    Repository Layer         │
│  (Data Access)              │
├─────────────────────────────┤
│    Model Layer              │
│  (Domain Objects)           │
├─────────────────────────────┤
│    Database Layer           │
│  (Persistence)              │
└─────────────────────────────┘
```

## Project Structure

```
BankX/
├── CMakeLists.txt              # Build configuration
├── README.md                   # This file
├── include/                    # Header files
│   ├── application/
│   │   ├── Application.h
│   │   └── Menu.h
│   ├── database/
│   │   └── DatabaseManager.h
│   ├── models/
│   │   ├── Account.h
│   │   ├── CurrentAccount.h
│   │   ├── Customer.h
│   │   └── SavingsAccount.h
│   ├── repository/
│   │   ├── AccountRepository.h
│   │   └── CustomerRepository.h
│   └── services/
│       ├── AccountService.h
│       ├── CustomerService.h
│       └── TransferService.h
├── src/                        # Source files
│   ├── main.cpp
│   ├── Application.cpp
│   ├── Menu.cpp
│   └── services/
│       ├── AccountService.cpp
│       └── CustomerService.cpp
├── sql/                        # Database scripts
└── build/                      # Build output directory
```

## Technologies Used

- **Language**: C++20
- **Build System**: CMake 3.20+
- **Platform**: Cross-platform (Windows, Linux, macOS)

## Build Instructions

### Prerequisites
- CMake 3.20 or higher
- C++20 compatible compiler (Visual Studio 2022, GCC 10+, Clang 10+)

### Building the Project

#### On Windows (Visual Studio)
```bash
mkdir build
cd build
cmake ..
cmake --build . --config Debug
```

#### On Linux/macOS
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Running the Application

After building, run the executable:

**Windows:**
```bash
./Debug/BankX.exe
```

**Linux/macOS:**
```bash
./BankX
```

## Usage

Once the application starts, you'll be presented with a menu-driven interface where you can:

1. **Manage Customers** - Add, view, and manage customer information
2. **Manage Accounts** - Create and manage accounts for customers
3. **Perform Transactions** - Deposit, withdraw, and transfer funds
4. **View Account Details** - Check balances and account information

## Development Guidelines

- Follow C++20 standards and best practices
- Maintain the layered architecture
- Use header files for interfaces and declarations
- Implement comprehensive error handling
- Add meaningful comments and documentation

## License

This project is provided as-is for educational and development purposes.
