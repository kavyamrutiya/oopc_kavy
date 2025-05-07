#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Student {
    string name;
    int score;
};


bool compareByScore(const Student& a, const Student& b) {
    return a.score > b.score;
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<Student> students;
    Student temp;

    cout << "Enter student name and score:\n";
    for (int i = 0; i < n; ++i) {
        cin >> temp.name >> temp.score;
        students.push_back(temp);
    }

   
    sort(students.begin(), students.end(), compareByScore);
    cout << "\nRanked Student List:\n";
    for (int i = 0; i < students.size(); ++i) {
        cout << i + 1 << ". " << students[i].name << " - " << students[i].score << endl;
    }

    return 0;
}