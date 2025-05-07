#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class BankAccount {
    string Name;
    double Balance;
    string* History;  
    int Capacity;
    int Count;

    void Log_transaction(const string& entry) {
        if (Count == Capacity) {
           
            int newCapacity = Capacity * 2;
            string* newHistory = new string[newCapacity];
            for (int i = 0; i < Count; ++i) {
                newHistory[i] = History[i];
            }
            delete[] History;
            History = newHistory;
            Capacity = newCapacity;
        }
        History[Count++] = entry;
    }

public:
    BankAccount(string accName, double initialBalance = 0) {
        Name = accName;
        Balance = initialBalance;
        Capacity = 10;
        Count = 0;
        History = new string[Capacity];
        Log_transaction("Account created with Balance: " + to_string(Balance));
    }

    ~BankAccount() {
        delete[] History;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            Log_transaction("Invalid deposit attempt: " + to_string(amount));
            throw invalid_argument("deposit amount must be positive.");
        }
        Balance += amount;
        Log_transaction("Deposited: " + to_string(amount));
    }

    void Withdraw(double amount) {
        if (amount <= 0) {
            Log_transaction("Invalid withdrawal attempt: " + to_string(amount));
            throw invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > Balance) {
            Log_transaction("Failed withdrawal (insufficient funds): " + to_string(amount));
            throw runtime_error("Insufficient funds.");
        }
        Balance -= amount;
        Log_transaction("Withdrawn: " + to_string(amount));
    }

    void Display_balance() const {
        cout << "Current Balance: ₹" << Balance << endl;
    }

    void Dispaly_history() const {
        cout << "\nTransaction History for " << Name << ":\n";
        for (int i = 0; i < Count; ++i) {
            cout << i + 1 << ". " << History[i] << endl;
        }
    }
};


int main() {
    BankAccount acc("John Doe", 1000);

    try {
        acc.deposit(500);
        acc.Withdraw(200);
        acc.Withdraw(2000);  
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    acc.Display_balance();
    acc.Dispaly_history();

    return 0;
}
