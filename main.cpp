#include <iostream>
#include <vector>
#include "func.hpp"
#include "exceptions.hpp"

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

int main(int argc, char *argv[]) {
    try {
        vector<Account*> list= generateAccountList(5);

        // for (auto element: list) {
        //     cout<<element->getString()<<endl;
        // }
        
        string buffer;
        cout<<"ENTER THE AMOUNT: ";
        cin>>buffer;

        for (char &c : buffer) {
            if (c < '0' || c > '9') {
                throw(NotNumberException(buffer));
                break;
            }
        }
    } catch(FailedCreatingAccountException e) {
        e.showErr();
        return EXIT_FAILURE;
    } catch(NotNumberException e) {
        e.showErr();
        return EXIT_FAILURE;
    }

    return 0;
}