#include <iostream>
#include <fstream>
using namespace std;

class bank_account {
protected:
    int acc_num;
    float balance, prev_balance;
    string file_name;
    fstream history_file;

public:
    bank_account(int an, float bal) {
        acc_num = an;
        prev_balance = bal;
        balance = bal;
    }

    void deposit(float amount) {
        prev_balance = balance;
        balance += amount;

        history_file.open(file_name, ios::app);
        history_file.seekp(SEEK_END);
        if (!history_file.is_open()) {
            cerr << endl << "Unable to open file!";
        }
        history_file << "\nDeposited Rs. " << amount << " | Current Balance: Rs. " << balance;
        history_file.close();
    }

    void print_history() {
        history_file.open(file_name, ios::in);
        if (!history_file.is_open()) {
            cerr << endl << "Unable to open file!";
        }

        cout << "\n\nPrinting All Transaction History:\n";
        string line;
        while (getline(history_file, line)) {
            cout << endl << line;
        }
        history_file.close();
    }

    void undo_last() {
        balance = prev_balance;

        history_file.open(file_name, ios::app | ios::in);
        history_file.seekp(SEEK_SET);
        if (!history_file.is_open()) {
            cerr << endl << "Unable to open file!";
        }

        history_file << "\nUndid Last Transaction | Current Balance: Rs. " << balance;
        history_file.close();
    }

    ~bank_account() {}
};

class savings_account : public bank_account {
    float interest_rate;

public:
    savings_account(int an, float bal, float ir) : bank_account(an, bal) {
        interest_rate = ir;
        file_name = "savings_account_history.txt";

        history_file.open(file_name, ios::out | ios::trunc);
        history_file.close();

        history_file.open(file_name, ios::app);
        history_file.seekp(SEEK_END);
        history_file << "Savings Account No. " << acc_num << " Transaction History | Initial Balance: Rs. " << balance;
        history_file.close();
    }

    int withdraw(float amount) {
        if (amount <= balance) {
            prev_balance = balance;
            balance -= amount;

            history_file.open(file_name, ios::app);
            history_file.seekp(SEEK_END);
            if (!history_file.is_open()) {
                cerr << endl << "Unable to open file!";
            }

            history_file << "\nWithdrew Rs." << amount << " | Current Balance: Rs. " << balance;
            history_file.close();

            return 0;
        } else {
            return 1;
        }
    }

    void display_details() {
        cout << "\nAccount Number: " << acc_num;
        cout << "\nInterest Rate: " << interest_rate;
        cout << "\nCurrent Balance: Rs. " << balance;
    }

    ~savings_account() {}
};

class current_account : public bank_account {
    float overdraft_limit;

public:
    current_account(int an, float bal, float ol) : bank_account(an, bal) {
        overdraft_limit = ol;
        file_name = "current_account_history.txt";

        history_file.open(file_name, ios::out | ios::trunc);
        history_file.close();

        history_file.open(file_name, ios::app);
        history_file.seekp(SEEK_END);
        history_file << "Current Account No. " << acc_num << " Transaction History | Initial Balance: Rs. " << balance;
        history_file.close();
    }

    int withdraw(float amount) {
        if (amount <= balance + overdraft_limit) {
            prev_balance = balance;
            balance -= amount;

            history_file.open(file_name, ios::app);
            history_file.seekp(SEEK_END);
            if (!history_file.is_open()) {
                cerr << endl << "Unable to open file!";
            }

            history_file << "\nWithdrew Rs." << amount << " | Current Balance: Rs. " << balance;
            history_file.close();

            return 0;
        } else {
            return 1;
        }
    }

    void display_details() {
        cout << "\nAccount Number: " << acc_num;
        cout << "\nOverdraft Limit: " << overdraft_limit;
        cout << "\nCurrent Balance: Rs. " << balance;
    }

    ~current_account() {}
};

int main() {
    int choice = 1, acc_num, sub_choice;
    float interest, balance, overdraft;
    savings_account* sa = nullptr;
    current_account* ca = nullptr;

    while (choice > 0 && choice < 8) {
        cout << "\n\nBanking System\nChoices:\n1. Create Savings Account\n2. Create Current Account\n3. Withdraw Money"
             << "\n4. Deposit Money\n5. View Transaction History\n6. Display Account Details\n7. Undo Last Transaction"
             << "\n0. Exit System\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter Savings Account Details:\nAccount Number: ";
                cin >> acc_num;
                cout << "Interest Rate: ";
                cin >> interest;
                cout << "Initial Balance: Rs. ";
                cin >> balance;
                sa = new savings_account(acc_num, balance, interest);
                break;

            case 2:
                cout << "\nEnter Current Account Details:\nAccount Number: ";
                cin >> acc_num;
                cout << "Overdraft Limit: ";
                cin >> overdraft;
                cout << "Initial Balance: Rs. ";
                cin >> balance;
                ca = new current_account(acc_num, balance, overdraft);
                break;

            case 3:
                cout << "\nWithdraw from:\n1. Savings Account\n2. Current Account\nChoice: ";
                cin >> sub_choice;
                cout << "Amount: ";
                cin >> balance;

                if (sub_choice == 1 && sa != nullptr) {
                    if (!sa->withdraw(balance)) {
                        cout << "\nRs. " << balance << " withdrawn from Savings Account";
                    } else {
                        cout << "\nInsufficient balance";
                    }
                } else if (sub_choice == 2 && ca != nullptr) {
                    if (!ca->withdraw(balance)) {
                        cout << "\nRs. " << balance << " withdrawn from Current Account";
                    } else {
                        cout << "\nInsufficient balance";
                    }
                } else {
                    cout << "\nNo such account found!";
                }
                break;

            case 4:
                cout << "\nDeposit to:\n1. Savings Account\n2. Current Account\nChoice: ";
                cin >> sub_choice;
                cout << "Amount: ";
                cin >> balance;

                if (sub_choice == 1 && sa != nullptr) {
                    sa->deposit(balance);
                    cout << "\nRs. " << balance << " deposited into Savings Account";
                } else if (sub_choice == 2 && ca != nullptr) {
                    ca->deposit(balance);
                    cout << "\nRs. " << balance << " deposited into Current Account";
                } else {
                    cout << "\nNo such account found!";
                }
                break;

            case 5:
                cout << "\nView history of:\n1. Savings Account\n2. Current Account\nChoice: ";
                cin >> sub_choice;

                if (sub_choice == 1 && sa != nullptr) {
                    sa->print_history();
                } else if (sub_choice == 2 && ca != nullptr) {
                    ca->print_history();
                } else {
                    cout << "\nNo such account found!";
                }
                break;

            case 6:
                cout << "\nDisplay details of:\n1. Savings Account\n2. Current Account\nChoice: ";
                cin >> sub_choice;

                if (sub_choice == 1 && sa != nullptr) {
                    sa->display_details();
                } else if (sub_choice == 2 && ca != nullptr) {
                    ca->display_details();
                } else {
                    cout << "\nNo such account found!";
                }
                break;

            case 7:
                cout << "\nUndo transaction in:\n1. Savings Account\n2. Current Account\nChoice: ";
                cin >> sub_choice;

                if (sub_choice == 1 && sa != nullptr) {
                    sa->undo_last();
                    cout << "\nUndid last transaction in Savings Account";
                } else if (sub_choice == 2 && ca != nullptr) {
                    ca->undo_last();
                    cout << "\nUndid last transaction in Current Account";
                } else {
                    cout << "\nNo such account found!";
                }
                break;

            default:
                break;
        }
    }

    cout << "\n\nExiting System...";

    delete sa;
    delete ca;
    return 0;
}
