#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


void Convert_to_lower(char* str) {
    for (int i = 0; str[i]; ++i)
        str[i] = tolower(str[i]);
}
bool Check_equality(const char* a, const char* b) {
    return strcmp(a, b) == 0;
}

int main() {
    const int MAX_LEN = 1000;
    char input[MAX_LEN];

    cout << "Enter a paragraph:\n";
    cin.getline(input, MAX_LEN);

    char* words[500];
    int counts[500] = {0};
    int unique = 0;

    char* token = strtok(input, " ,.-!?");

    while (token != NULL) {
        Convert_to_lower(token);  
        bool found = false;
        for (int i = 0; i < unique; ++i) {
            if (Check_equality(words[i], token)) {
                counts[i]++;
                found = true;
                break;
            }
        }

       
        if (!found) {
            words[unique] = new char[strlen(token) + 1];
            strcpy(words[unique], token);
            counts[unique] = 1;
            unique++;
        }

        token = strtok(NULL, " ,.-!?");
    }

  
    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < unique; ++i) {
        cout << words[i] << " : " << counts[i] << endl;
        delete[] words[i];
    }

    return 0;
}