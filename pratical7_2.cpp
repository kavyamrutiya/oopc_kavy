#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    const int MAX_LINE = 1000;
    char filename[100];
    
    cout << "Enter file name: ";
    cin >> filename;

    ifstream file(filename);
    
    if (!file) {
        cout << "Error: Cannot open file." << endl;
        return 1;
    }

    char* line = new char[MAX_LINE];
    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;

    while (file.getline(line, MAX_LINE)) {
        lineCount++;
        charCount += strlen(line); 
        charCount++; 

       
        char* token = strtok(line, " \t\n\r,.!?;:");
        while (token != NULL) {
            wordCount++;
            token = strtok(NULL, " \t\n\r,.!?;:");
        }
    }

    cout << "\nStatistics:\n";
    cout << "Lines: " << lineCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Characters: " << charCount << endl;

    delete[] line;
    file.close();
    return 0;
}