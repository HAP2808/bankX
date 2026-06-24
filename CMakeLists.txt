cmake_minimum_required(VERSION 3.20)

project(BankX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(
    BankX

    src/main.cpp
    src/Application.cpp
    src/Menu.cpp
    src/models/Customer.cpp
    src/services/AccountService.cpp
    src/services/CustomerService.cpp
    src/utils/RandomUtils.cpp
)