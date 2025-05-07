#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, num;
    cout << "Enter the number of transaction IDs: ";
    cin >> n;

    set<int> uniqueIDs;

    cout << "Enter the transaction IDs:\n";
    for (int i = 0; i < n; ++i) {
        cin >> num;
        uniqueIDs.insert(num); 
    }

    cout << "\nUnique Transaction IDs (sorted):\n";
    for (int id : uniqueIDs) {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}