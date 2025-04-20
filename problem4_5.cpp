
#include <iostream>
#include <string>
using namespace std;


class Grading_system {
protected:
    float Marks; 

public:
    
    void Get_Marks(float m) {
        Marks = m;
    }

    virtual void Compute_grade() = 0;
};


class Undergraduate : public Grading_system {
public:
    void Compute_grade() {
        cout << "Undergraduate Grade: ";
        if (Marks >= 80) {
            cout << "A (First Class)" << endl;
        } else if (Marks >= 60) {
            cout << "B (Second Class)" << endl;
        } else if (Marks >= 40) {
            cout << "C (Pass)" << endl;
        } else {
            cout << "F (Fail)" << endl;
        }
    }
};

class Postgraduate : public Grading_system {
public:
    void Compute_grade() {
        cout << "Postgraduate Grade: ";
        if (Marks >= 75) {
            cout << "A (Distinction)" << endl;
        } else if (Marks >= 55) {
            cout << "B (Merit)" << endl;
        } else if (Marks >= 40) {
            cout << "C (Pass)" << endl;
        } else {
            cout << "F (Fail)" << endl;
        }
    }
};

int main() {
    
    Undergraduate UgStudent;
    Postgraduate PgStudent;

    float Marks;
    int level;

    cout << "EDUCATIONAL GRADING SYSTEM\n";
    cout << "--------------------------\n";

    
    cout << "Enter student level (1 for Undergraduate, 2 for Postgraduate): ";
    cin >> level;

   
    cout << "Enter student Marks (0-100): ";
    cin >> Marks;

    
    if (level == 1) {
        UgStudent.Get_Marks(Marks);
        UgStudent.Compute_grade();
    } else if (level == 2) {
        PgStudent.Get_Marks(Marks);
        PgStudent.Compute_grade();
    } else {
        cout << "Invalid student level!" << endl;
    }

    return 0;
}
