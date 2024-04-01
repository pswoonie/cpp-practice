#include <iostream>
#include <vector>
#include "func.hpp"
#include "exceptions.hpp"

#define SPACE cout<<endl

Account* getClient(int idParam) {
    switch(idParam) {
        case 1:
            return new Account(idParam, 5000, "Joshua Kali");
        case 2:
            return new Account(idParam, 14000, "Brook Johnson");
        case 3:
            return new Account(idParam, 44200, "John Borne");
        case 4:
            return new Account(idParam, 135000, "Great Piatt");
        case 5:
            return new Account(idParam, 35000, "Kevin Taylor");
        default:
            return new Account(0, 0, "Not In The List");
    }
}

vector<Account*> generateAccountList(size_t len) {
    Account* acc;
    vector<Account*> list(len);
    for (int i=0;i<list.size();i++) {
        acc = getClient(i+1);
        if (acc->getID() == 0) {
            throw(FailedCreatingAccountException("Not In The List"));
            break;
        }
        list[i] = acc;
    }
    return list;
}

void isNumber(string buffer) {
    for (char &c : buffer) {
        if (c < '0' || c > '9') {
            throw(NotNumberException(buffer));
            break;
        }
    }
}

void isSingleDigit(string buffer) {
    if (buffer.length() > 1) {
        throw MoreThanOneDigitException(buffer.length());
    }
}

int main(int argc, char *argv[]) {
    bool isError = false;
    vector<Account*> list(5);
    TransactionHandler *handler = NULL;
    try {
        list= generateAccountList(5);
        
        SPACE;
        SPACE;
        string buffer;
        cout<<"-- PLEASE SELECT FROM BELOW"<<endl;
        cout<<"-- 0: EXIT | 1: DEPOSIT | 2: WITHDRAW | 3: MAKE TRANSFER"<<endl;
        cout<<">> ENTER: ";
        cin>>buffer;
        isNumber(buffer);
        isSingleDigit(buffer);
        if (!buffer.compare("0")) {
            // finish program
        } else {
            string amt;
            cout<<">> ENTER AMOUNT: ";
            cin>>amt;
            isNumber(amt);
            switch(stoi(buffer)) {
                case 1: {
                    list[2]->deposit(stoi(amt));
                    cout<<"-- CURRENT BALANCE: "<<list[2]->getBalance()<<endl;
                } break;
                case 2: {
                    list[2]->withdraw(stoi(amt));
                    cout<<"-- CURRENT BALANCE: "<<list[2]->getBalance()<<endl;
                } break;
                case 3: {
                    string receiver;
                    cout<<">> ";
                    for (int i=0;i<list.size();i++) {
                        cout<<i+1<<": "<<list[i]->getName()<<" | ";
                    }
                    SPACE;
                    cout<<">> SELECT RECEIVER NAME: ";
                    cin>>receiver;
                    isNumber(receiver);
                    isSingleDigit(receiver);
                    handler = new TransactionHandler();
                    int index = stoi(receiver);
                    handler->transfer(stoi(amt), list[2], list[index-1]);
                    cout<<"-- "<<list[2]->getName()<<": "<<list[2]->getBalance()<<" | ";
                    cout<<list[index-1]->getName()<<": "<<list[index-1]->getBalance()<<endl;
                } break;
                default:
                    cout<<"-- EXIT"<<endl;
            }
        }
    } catch(FailedCreatingAccountException e) {
        e.showErr();
        isError = true;
    } catch(NotNumberException e) {
        e.showErr();
        isError = true;
    } catch(MoreThanOneDigitException e) {
        e.showErr();
        isError = true;
    } catch(NotEnoughBalanceException e) {
        e.showErr();
        isError = true;
    }

    if (handler != NULL) {
        delete handler;
    }
    for (int i=0;i<list.size();i++) {
        delete list[i];
    }
    return (isError) ? EXIT_FAILURE : EXIT_SUCCESS;
}