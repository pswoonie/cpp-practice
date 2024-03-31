#include <iostream>
#include "exceptions.hpp"
#include "func.hpp"

Account::Account(int iParam, int bParam, string nParam) 
    : id(iParam), balance(bParam), name(nParam) 
{
    cout<<"id      : "<<id<<endl;
    cout<<"balance : "<<balance<<endl;
    cout<<"name    : "<<name<<endl;
    cout<<"Account Successfully Created"<<endl;
}

void Account::deposit(int money) {
    balance+=money;
    cout<<"Current Balance: "<<balance<<endl;
}

void Account::withdraw(int money) {
    try {
        if (money > balance) {
            throw NotEnoughBalanceException(balance);
            return;
        } else {
            balance-=money;
            cout<<"Current Balance: "<<balance<<endl;
        }
    } catch(NotEnoughBalanceException e) {
        e.showErr();
    }
}

int Account::getID() {
    return id;
}

string Account::getString() {
    return name;
}

TransactionHandler::TransactionHandler(){
    cout<<"Ready To Make Transaction"<<endl;
}

void TransactionHandler::transfer() {
    cout<<""<<endl;
}