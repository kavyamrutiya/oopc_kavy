#include <iostream>
#include <string>
using namespace std;


class GradingSystem {
protected:
    float marks; 

public:
    
    void setMarks(float m) {
        marks = m;
    }

    virtual void computeGrade() = 0;
};


class Undergraduate : public GradingSystem {
public:
    void computeGrade() {
        cout << "Undergraduate Grade: ";
        if (marks >= 80) {
            cout << "A (First Class)" << endl;
        } else if (marks >= 60) {
            cout << "B (Second Class)" << endl;
        } else if (marks >= 40) {
            cout << "C (Pass)" << endl;
        } else {
            cout << "F (Fail)" << endl;
        }
    }
};

class Postgraduate : public GradingSystem {
public:
    void computeGrade() {
        cout << "Postgraduate Grade: ";
        if (marks >= 75) {
            cout << "A (Distinction)" << endl;
        } else if (marks >= 55) {
            cout << "B (Merit)" << endl;
        } else if (marks >= 40) {
            cout << "C (Pass)" << endl;
        } else {
            cout << "F (Fail)" << endl;
        }
    }
};

int main() {
    
    Undergraduate ugStudent;
    Postgraduate pgStudent;

    float marks;
    int level;

    cout << "EDUCATIONAL GRADING SYSTEM\n";
    cout << "--------------------------\n";

    
    cout << "Enter student level (1 for Undergraduate, 2 for Postgraduate): ";
    cin >> level;

   
    cout << "Enter student marks (0-100): ";
    cin >> marks;

    
    if (level == 1) {
        ugStudent.setMarks(marks);
        ugStudent.computeGrade();
    } else if (level == 2) {
        pgStudent.setMarks(marks);
        pgStudent.computeGrade();
    } else {
        cout << "Invalid student level!" << endl;
    }

    return 0;
}