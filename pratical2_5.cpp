#include <iostream>
#include <cmath>
using namespace std;

class loan_information {
    int loan_id;
    string appl_name;
    int time_period;  
    int total_loan_amount;
    float annual_interest;
    float emi;

    void emi_calculator(int amount, int time, float interest) {
        
        float R = interest / 12 / 100;  
        emi = (amount * R * pow(1 + R, time)) / (pow(1 + R, time) - 1); 
    }

public:
    void get_details() {
        cout << "Enter your loan id: ";
        cin >> loan_id;
        cout << "Enter your name: ";
        cin >> appl_name;
        cout << "Enter your time period (in months): ";
        cin >> time_period;
        cout << "Enter your total loan amount: ";
        cin >> total_loan_amount;
        cout << "Enter your annual interest rate (%): ";
        cin >> annual_interest;
    }

    void display_details() {
        
        emi_calculator(total_loan_amount, time_period, annual_interest);
        cout << "Loan ID: " << loan_id << endl;
        cout << "Applicant's name: " << appl_name << endl;
        cout << "Loan time period (in months): " << time_period << endl;
        cout << "Total loan amount: " << total_loan_amount << endl;
        cout << "Annual interest rate: " << annual_interest << "%" << endl;
        cout << "Your EMI is: " << emi << endl;
    }
};

int main() {
    loan_information loan;
    loan.get_details();
    loan.display_details();
    return 0;
}
