#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() : balance(0.0) {
        cout << "Default constructor called" << endl;
    }

    BankAccount(double initialBalance) : balance(initialBalance) {
        cout << "Parameterized constructor called" << endl;
    }

    BankAccount(const BankAccount& other) : balance(other.balance) {
        cout << "Copy constructor called" << endl;
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        } else {
            cout << "Insufficient funds!" << endl;
            return false;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account1;
    cout << "Balance of account1: " << account1.getBalance() << endl;

    BankAccount account2(1000.0);  
    cout << "Balance of account2: " << account2.getBalance() << endl << endl;

    BankAccount account3(account2);

    account3.withdraw(200.0);
    
    cout << "Balance of account3: " << account3.getBalance() << endl;
    cout << "Balance of account2: " << account2.getBalance() << endl;
    
    return 0;
}
