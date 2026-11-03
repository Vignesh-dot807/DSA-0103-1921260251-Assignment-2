#include <iostream>
using namespace std;

class SavingsAccount {
private:
    long long accountNumber;
    double balance;
    double transactions[10];
    int count;

    void record(double amount) {
        if (count < 10) {
            transactions[count++] = amount;
        } else {
            for (int i = 1; i < 10; ++i)
                transactions[i - 1] = transactions[i];
            transactions[9] = amount;
        }
    }

public:
    SavingsAccount(long long number, double openingBalance)
        : accountNumber(number), balance(openingBalance), count(0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            record(amount);
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            record(-amount);
            return true;
        }
        return false;
    }

    void miniStatement() const;
    double getBalance() const { return balance; }
};

void SavingsAccount::miniStatement() const {
    cout << "Account: " << accountNumber << '\\n';
    cout << "Balance: " << balance << '\\n';
    cout << "Last transactions (oldest to newest):\\n";
    for (int i = 0; i < count; ++i)
        cout << transactions[i] << '\\n';
}

int main() {
    SavingsAccount account(123456, 1000.0);
    account.deposit(200);
    account.withdraw(100);
    account.deposit(50);
    account.miniStatement();
    return 0;
}