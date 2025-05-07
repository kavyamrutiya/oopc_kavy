#include <iostream>
#include <iomanip>
using namespace std;



ostream& currency(ostream& os) {
    return os << "₹";
}

int main() {
   
    
    const int numStudents = 4;
    string names[numStudents] = {"Alice", "Bob", "Charlie", "David"};
    double marks[numStudents] = {90.5, 78.0, 85.75, 65.3};
    double tuitionFees[numStudents] = {25000.50, 18000.75, 22000.00, 20000.00};

 
    
    cout << setw(15) << left << "Name" << setw(10) << "Marks" << setw(15) << "Tuition Fees" << endl;
    cout << "-----------------------------------------------" << endl;

   
    
    for (int i = 0; i < numStudents; ++i) {
        cout << setw(15) << left << names[i]
             << setw(10) << fixed << setprecision(2) << marks[i]
             << setw(15) << currency << tuitionFees[i] << endl;  
    }

    return 0;
}