#include <iostream>
using namespace std;

class Product {
    int Product_id;
    string Product_name;
    int Product_quantity;
    float Product_price;

public:
    void Add(int id, string name, int quantity, float price) {
        Product_id = id;
        Product_name = name;
        Product_quantity = quantity;
        Product_price = price;
    }

    void Update_quantity(int qty) {
        Product_quantity += qty;
    }

    float Get_value() {
        return Product_quantity * Product_price;
    }

    void Display() {
        cout << "ID: " << Product_id
             << ", Name: " << Product_name
             << ", Quantity: " << Product_quantity
             << ", Price: " << Product_price << endl;
    }

    int Get_id() {
        return Product_id;
    }
};

int main() {
    Product inventory[100];
    int productCount = 0, choice, id, qty;
    string name;
    float price;

    do {
        cout << "\n1. Add Product\n2. Update Quantity\n3. Display All\n4. Calculate Total Value\n0. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Product ID, Name, Quantity, Price: ";
                cin >> id >> name >> qty >> price;
                inventory[productCount].Add(id, name, qty, price);
                productCount++;
                break;

            case 2:
                cout << "Enter Product ID to update quantity: ";
                cin >> id;
                cout << "Enter Quantity to add: ";
                cin >> qty;
                for (int i = 0; i < productCount; i++) {
                    if (inventory[i].Get_id() == id) {
                        inventory[i].Update_quantity(qty);
                        cout << "Quantity updated.\n";
                        break;
                    }
                    if (i == productCount - 1) {
                        cout << "Product not found.\n";
                    }
                }
                break;

            case 3:
                for (int i = 0; i < productCount; i++) {
                    inventory[i].Display();
                }
                break;

            case 4:
                float total;
                total = 0;
                for (int i = 0; i < productCount; i++) {
                    total += inventory[i].Get_value();
                }
                cout << "Total Inventory Value: Rs. " << total << endl;
                break;

            case 0:
                cout << "Thank you!" << endl;
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
