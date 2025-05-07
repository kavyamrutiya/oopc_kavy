#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Item {
    char name[50];
    int quantity;
    float price;

public:
    void Get_details() {
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price: ";
        cin >> price;
    }

    void Save_to_file() {
        ofstream file("inventory.txt", ios::app);
        if (!file) {
            cout << "Error opening file.\n";
            return;
        }
        file << name << " " << quantity << " " << price << endl;
        file.close();
    }

    void Display() {
        cout << "Name: " << name
             << ", Quantity: " << quantity
             << ", Price: " << price << endl;
    }

    bool Screach(const char* searchName) {
        return strcmp(name, searchName) == 0;
    }

    bool Load_from_file(ifstream& file) {
        file >> name >> quantity >> price;
        return file.good();
    }
};

void Add_item() {
    Item item;
    item.Get_details();
    item.Save_to_file();
    cout << "Item added successfully.\n";
}

void Check_inventory() {
    ifstream file("inventory.txt");
    if (!file) {
        cout << "No inventory found.\n";
        return;
    }

    Item item;
    cout << "\nInventory:\n";
    while (item.Load_from_file(file)) {
        item.Display();
    }
    file.close();
}

void Search_item() {
    char searchName[50];
    cout << "Enter item name to search: ";
    cin >> searchName;

    ifstream file("inventory.txt");
    if (!file) {
        cout << "No inventory found.\n";
        return;
    }

    Item item;
    bool found = false;
    while (item.Load_from_file(file)) {
        if (item.Screach(searchName)) {
            cout << "Found item:\n";
            item.Display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Item not found.\n";
    }

    file.close();
}

int main() {
    int Choice;

    do {
        cout << "\n1. Add Item\n2. View Inventory\n3. Search Item\n0. Exit\n";
        cout << "Enter your Choice: ";
        cin >> Choice;

        switch (Choice) {
            case 1: Add_item(); break;
            case 2: Check_inventory(); break;
            case 3: Search_item(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice.\n";
        }
    } while (Choice != 0);

    return 0;
}