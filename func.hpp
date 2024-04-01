#ifndef FUNC_HPP
#define FUNC_HPP

#include <string>

using namespace std;

class Account {
    private:
        int id;
        int balance;
        string name;
    public:
        Account(int iParam, int bParam, string nParam);
        void deposit(int money);
        void withdraw(int money);
        int getID();
        int getBalance();
        string getName();
};

class TransactionHandler {
    public:
        TransactionHandler();
        void transfer(int amount, Account *sender, Account *receiver);
};

#endif /* FUNC_HPP */