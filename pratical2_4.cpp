#include <iostream>
using namespace std;

class Product {
    int Product_Id;
    int Product_Quantity;
    string Product_Name;
    float Product_Price;

public:
    Product() {
        Product_Id = 0;
        Product_Quantity = 0;
        Product_Name = "N/A";
        Product_Price = 0.0;
    }

    void Add(int id, int quantity, string name, float price) {
        Product_Id = id;
        Product_Quantity = quantity;
        Product_Name = name;
        Product_Price = price;
    }

    int check(int idno) {
        return Product_Id == idno;
    }

    void update() {
        int add_qty;
        cout << "Enter quantity to add: ";
        cin >> add_qty;
        Product_Quantity += add_qty;
        cout << "Stock updated successfully.\n";
    }

    void update(int purchase_qty) {
        if (Product_Quantity >= purchase_qty) {
            Product_Quantity -= purchase_qty;
            cout << "Purchase successful!\n";
            cout << "Total cost: " << Product_Price * purchase_qty << endl;
        } else {
            cout << "Error: Not enough stock available.\n";
        }
    }

    void display() {
        cout << "Product ID    : " << Product_Id << endl;
        cout << "Product Name  : " << Product_Name << endl;
        cout << "Product Price : " << Product_Price << endl;
        cout << "Quantity Left : " << Product_Quantity << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    Product p[10];
    int Product_count = 0, choice, Temp_Id, Temp_Quantity, choice2;
    float Temp_Rate;
    string Temp_Name;

    while (true) {
        cout << "\n=== Inventory Management ===\n";
        cout << "1. Add stock\n";
        cout << "2. Purchase item / Display inventory\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Product ID: ";
            cin >> Temp_Id;

            bool found = false;
            for (int i = 0; i < Product_count; i++) {
                if (p[i].check(Temp_Id)) {
                    p[i].update();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Enter product name: ";
                cin >> Temp_Name;
                cout << "Enter product price: ";
                cin >> Temp_Rate;
                cout << "Enter product quantity: ";
                cin >> Temp_Quantity;
                p[Product_count].Add(Temp_Id, Temp_Quantity, Temp_Name, Temp_Rate);
                Product_count++;
                cout << "New product added.\n";
            }
        }

        else if (choice == 2) {
            if (Product_count == 0) {
                cout << "No products in inventory. Please add stock first.\n";
            } else {
                cout << "1. Purchase item\n";
                cout << "2. Display inventory summary\n";
                cout << "0. Back to main menu\n";
                cout << "Enter your choice: ";
                cin >> choice2;

                if (choice2 == 1) {
                    cout << "Enter product ID to purchase: ";
                    cin >> Temp_Id;
                    bool found = false;
                    for (int i = 0; i < Product_count; i++) {
                        if (p[i].check(Temp_Id)) {
                            cout << "Enter quantity to purchase: ";
                            cin >> Temp_Quantity;
                            p[i].update(Temp_Quantity);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "No product with matching ID found.\n";
                    }
                }

                else if (choice2 == 2) {
                    cout << "\n=== Inventory Summary ===\n";
                    for (int i = 0; i < Product_count; i++) {
                        p[i].display();
                    }
                }

                else if (choice2 == 0) {
                    cout << "Returning to main menu...\n";
                }

                else {
                    cout << "Invalid choice.\n";
                }
            }
        }

        else if (choice == 0) {
            cout << "Exiting...\n";
            break;
        }

        else {
            cout << "Invalid main menu choice.\n";
        }
    }

    return 0;
}
