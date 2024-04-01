#include <iostream>
#include "exceptions.hpp"
#include "func.hpp"

Account::Account(int iParam, int bParam, string nParam) 
    : id(iParam), balance(bParam), name(nParam) 
{
    cout<<"id      : "<<id<<endl;
    cout<<"balance : "<<balance<<endl;
    if (!name.compare("John Borne")) {
        cout<<"name    : "<<name<<"  <- This Is You"<<endl;
    } else {
        cout<<"name    : "<<name<<endl;
    }
    cout<<"-- Account Successfully Created"<<endl;
}

void Account::deposit(int money) {
    // cout<<"BEFORE: "<<balance<<" | ";
    balance+=money;
    // cout<<"Current Balance: "<<balance<<endl;
}

void Account::withdraw(int money) {
    if (money > balance) {
        throw NotEnoughBalanceException(balance);
    } else {
        balance-=money;
        // cout<<"Current Balance: "<<balance<<endl;
    }
}

int Account::getID() {
    return id;
}

int Account::getBalance() {
    return balance;
}

string Account::getName() {
    return name;
}

TransactionHandler::TransactionHandler(){
    cout<<"-- Please Wait For Transaction To Finish"<<endl;
}

void TransactionHandler::transfer(int amount, Account *sender, Account *receiver) {
    sender->withdraw(amount);
    receiver->deposit(amount);
}