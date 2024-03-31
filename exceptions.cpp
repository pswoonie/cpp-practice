#include <iostream>
#include "exceptions.hpp"

NotEnoughBalanceException::NotEnoughBalanceException(int curr) 
    : currBalance(curr) {}

void NotEnoughBalanceException::showErr() {
    cout<<"Please Enter the Amount Less Than or Equal To the Current Balance"<<endl;
}

NotNumberException::NotNumberException(string iParam) 
    : input(iParam) {}

void NotNumberException::showErr() {
    cout<<"Value Entered is Not A Number: "<<input<<endl;
    cout<<"Please Check If the Amount is Entered Correctly"<<endl;
}

FailedCreatingAccountException::FailedCreatingAccountException(string nParam) 
    : name(nParam) {};

void FailedCreatingAccountException::showErr() {
    cout<<"Failed to Create New Account!! Name: "<<name<<endl;
}