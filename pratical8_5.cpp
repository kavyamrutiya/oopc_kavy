#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    map<string, vector<string>> Directory;
    int Choice;
    string Folder, File;

    while (true) {
        cout << "\n1. Add Folder\n2. Add File to Folder\n3. Show Directory\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> Choice;

        if (Choice == 1) {
            cout << "Enter Folder name: ";
            cin >> Folder;
            Directory[Folder];
            cout << "Folder added.\n";
        } 
        else if (Choice == 2) {
            cout << "Enter Folder name: ";
            cin >> Folder;
            if (Directory.find(Folder) != Directory.end()) {
                cout << "Enter File name: ";
                cin >> File;
                Directory[Folder].push_back(File);
                cout << "File added.\n";
            } else {
                cout << "Folder not found.\n";
            }
        } 
        else if (Choice == 3) {
            cout << "\nDirectory Structure:\n";
            for (auto it = Directory.begin(); it != Directory.end(); ++it) {
                cout << it->first << ":\n";
                for (string f : it->second) {
                    cout << "  - " << f << endl;
                }
            }
        } 
        else if (Choice == 4) {
            break;
        } 
        else {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}