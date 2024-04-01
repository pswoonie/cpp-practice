#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>

using namespace std;

class NotEnoughBalanceException{
    private:
        int currBalance;
    public:
        NotEnoughBalanceException(int amount);
        void showErr();
};

class NotNumberException {
    private:
        string input;
    public:
        NotNumberException(string iParam);
        void showErr();
};

class FailedCreatingAccountException {
    private:
        string name;
    public:
        FailedCreatingAccountException(string name);
        void showErr();
};

class MoreThanOneDigitException {
    private:
        int len;
    public:
        MoreThanOneDigitException(int length);
        void showErr();
};

#endif /* EXCEPTIONS_HPP */