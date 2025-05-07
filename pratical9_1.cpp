#include <iostream>
#include <string>  
#include <stdexcept> 
#include <sstream>

using namespace std;


double convertToDouble(const string& str) {
    stringstream ss(str);
    double value;
    ss >> value; 
    if (ss.fail() || !ss.eof()) {
        throw invalid_argument("Invalid numerical input.");
    }
    return value;
}

int main() {
    string loanAmountStr, annualIncomeStr;
    double loanAmount, annualIncome;

    try {
       
        cout << "Enter the loan amount: ";
        getline(cin, loanAmountStr);
        loanAmount = convertToDouble(loanAmountStr);  
      
        cout << "Enter the annual income: ";
        getline(cin, annualIncomeStr);
        annualIncome = convertToDouble(annualIncomeStr); 

        
        if (annualIncome == 0) {
            throw runtime_error("Error: Annual income cannot be zero.");
        }

      
        double ratio = loanAmount / annualIncome;

       
        cout << "The loan-to-income ratio is: " << ratio << endl;
    }
    catch (const invalid_argument& e) {
      
        cout << "Error: " << e.what() << endl;
    }
    catch (const runtime_error& e) {
      
        cout << "Error: " << e.what() << endl;
    }
    catch (...) {
       
        cout << "An unexpected error occurred." << endl;
    }

    return 0;
}