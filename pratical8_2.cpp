#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;


string Convert_to_lowercase(string word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    map<string, int> freq;
    string word;
    istringstream stream(sentence);

    while (stream >> word) {
        word = Convert_to_lowercase(word);
        ++freq[word];
    }

    cout << "\nWord Frequencies:\n";
    for (auto pair : freq) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}