#include <iostream>
using namespace std;

class Product {
    int id;
    string name;
    int quantity;
    int rate;

public:
    void add(int idno, string naam, int qty, int r) {
        id = idno;
        name = naam;
        quantity = qty;
        rate = r;
    }

    int check(int idno) {
        return id == idno;
    }

    void updateQuantity(int qty) {
        quantity += qty;
    }

    int getValue() {
        return quantity * rate;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << ", Rate: " << rate << ", Value: " << getValue() << endl;
    }
};

int main() {
    Product p[100];
    int productCount = 0;
    int choice;

    do {
        cout << "\n1. Add/Update Product\n2. View Inventory\n3. Total Inventory Value\n4. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, rate, qty;
            string name;
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Product Name: ";
            cin >> name;
            cout << "Enter Quantity: ";
            cin >> qty;
            cout << "Enter Rate: ";
            cin >> rate;

            bool found = false;
            for (int i = 0; i < productCount; i++) {
                if (p[i].check(id)) {
                    p[i].updateQuantity(qty);
                    found = true;
                    break;
                }
            }

            if (!found) {
                p[productCount].add(id, name, qty, rate);
                productCount++;
            }
        }

        else if (choice == 2) {
            for (int i = 0; i < productCount; i++) {
                p[i].display();
            }
        }

        else if (choice == 3) {
            int total = 0;
            for (int i = 0; i < productCount; i++) {
                total += p[i].getValue();
            }
            cout << "Total Inventory Value: " << total << endl;
        }

    } while (choice != 4);

    return 0;
}
