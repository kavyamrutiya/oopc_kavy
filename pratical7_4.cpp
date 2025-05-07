#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


ostream& tab(ostream& os) {
    return os << setw(15) << left;
}

int main() {
    ifstream file("students.txt");

    if (!file) {
        cout << "Error: Could not open file.\n";
        return 1;
    }

    char Name[50];
    int Marks;
    char Grade;


    cout << tab << "Name" << tab << "Marks" << tab << "Grade" << endl;
    cout << "-------------------------------------------" << endl;

  
    while (file >> Name >> Marks >> Grade) {
        cout << tab << Name << tab << Marks << tab << Grade << endl;
    }

    file.close();
    return 0;
}