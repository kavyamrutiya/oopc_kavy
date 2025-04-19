#include <iostream>
using namespace std;

class Bank_account
{
    static int Minimum_balance;
    int Account_number;
    string Account_holder_name;
    float Balance;

public:
    void Add_account()
    {
        float Temp_balance;
        cout << "Enter your Account number : ";
        cin >> Account_number;
        cout << "Enter Account holder name : ";
        cin >> Account_holder_name;
        cout << "Enter Balance : ";
        cin >> Temp_balance;
        if (Temp_balance >= Minimum_balance)
        {
            Balance = Temp_balance;
        }
        else
        {
            cout << "ERROR : Enter amount greater than or equal to " << Minimum_balance << endl;
        }
    }
    void Deposit()
    {
        float Temp_amount;
        cout << "Enter amount to be deposited : ";
        cin >> Temp_amount;
        Balance = Balance + Temp_amount;
        cout << "Amount deposited successfuly : " << endl;
    }
    void Withdraw()
    {
        float Temp_amount;
        cout << "Enter amount to withdrawn : ";
        cin >> Temp_amount;
        if (Balance - Temp_amount >= Minimum_balance)
        {
            Balance = Balance - Temp_amount;
            cout << "RS." << Temp_amount << " withdrawm successffuly" << endl;
        }
        else
        {
            cout << "ERROR : INSUFFICENT BALANCE " << endl;
        }
    }
    int Search(int Temp_account_number)
    {
        if (Account_number == Temp_account_number)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void Display_details()
    {
        cout << "\nAccount holder name : " << Account_holder_name << endl;
        cout << "Account Number : " << Account_number << endl;
        cout << "Account Balance : " << Balance << endl;
    }
};
int Bank_account ::Minimum_balance = 5000;
int main()
{
    int Choice, Account_count = 0, Temp_account_number, i;
    Bank_account a[10];
    do
    {
        cout << "\nEnter 1 to add account" << endl;
        cout << "Enter 2 to Deposit amount" << endl;
        cout << "Enter 3 to Withdraw amount" << endl;
        cout << "Enter 4 to display Account details" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << "Enter your Choice : ";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            a[Account_count].Add_account();
            Account_count++;
            break;
        case 2:
            cout << "Enter account number : ";
            cin >> Temp_account_number;
            for (i = 0; i < Account_count; i++)
            {
                if (a[i].Search(Temp_account_number))
                {
                    a[i].Deposit();
                    break;
                }
                else if (i == Account_count - 1)
                {
                    cout << "ERROR : INVALID ACCOUNT NUMBER" << endl;
                }
            }
            break;
        case 3:
            cout << "Enter account number : ";
            cin >> Temp_account_number;
            for (i = 0; i < Account_count; i++)
            {
                if (a[i].Search(Temp_account_number))
                {
                    a[i].Withdraw();
                    break;
                }
                else if (i == Account_count - 1)
                {
                    cout << "ERROR : INVALID ACCOUNT NUMBER" << endl;
                }
            }
            break;
        case 4:
            cout << "Enter account number : ";
            cin >> Temp_account_number;
            for (i = 0; i < Account_count; i++)
            {
                if (a[i].Search(Temp_account_number))
                {
                    a[i].Display_details();
                    break;
                }
                else if (i == Account_count - 1)
                {
                    cout << "ERROR : INVALID ACCOUNT NUMBER" << endl;
                }
            }
            break;
        }

    } while (Choice != 0);
    return 0;
}
