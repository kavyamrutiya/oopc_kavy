#include <iostream>
using namespace std;

class Product
{
    int Product_id;
    int Product_quantity;
    string Product_name;
    float Product_price;
    int User_quantitty = 0;

    float Display_total(float Price, int quantity)
    {
        return Price * quantity;
    }

public:
    void Add(int Id, int Quantitty, string Name, float Price)
    {
        Product_id = Id;
        Product_quantity = Quantitty;
        Product_name = Name;
        Product_price = Price;
    }

    int Search(int idno)
    {
        if (Product_id == idno)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void Update_purchase()
    {
        User_quantitty++;
        Product_quantity--;
    }

    void Update_stockup(int Quantitty)
    {
        Product_quantity = Product_quantity + Quantitty; // FIXED: assignment, not comparison
    }

    void Display_bill()
    {
        if (User_quantitty > 0)
        {
            cout << "\nID : " << Product_id << endl;
            cout << "Name : " << Product_name << endl;
            cout << "Rate : " << Product_price << endl;
            cout << "Quantity : " << User_quantitty << endl; // FIXED: used wrong variable and syntax
            cout << "TOTAL : " << Display_total(Product_price, User_quantitty) << endl;
            User_quantitty = 0;
        }
    }
};

int main()
{
    Product p[10];
    int Product_count = 0, Choice, Temp_Id, Temp_uantity, Choice2;
    float Temp_Rate;
    string Temp_Name;

    do
    {
        cout << "\nEnter 1 to add Item" << endl;
        cout << "Enter 2 to purchase item" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << "Enter your Choice : ";
        cin >> Choice;

        if (Choice == 1)
        {
            cout << "Enter Product ID : ";
            cin >> Temp_Id;
            cout << "Enter product quantity : ";
            cin >> Temp_uantity;

            if (Product_count == 0)
            {
                cout << "Enter product Name :";
                cin >> Temp_Name;
                cout << "Enter product rate : ";
                cin >> Temp_Rate;
                Product_count++;
                p[0].Add(Temp_Id, Temp_uantity, Temp_Name, Temp_Rate);
            }
            else
            {
                bool found = false;
                for (int i = 0; i < Product_count; i++)
                {
                    if (p[i].Search(Temp_Id))
                    {
                        p[i].Update_stockup(Temp_uantity);
                        cout << "Product quantity Updated successfully" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Enter product Name :";
                    cin >> Temp_Name;
                    cout << "Enter product rate : ";
                    cin >> Temp_Rate;
                    p[Product_count].Add(Temp_Id, Temp_uantity, Temp_Name, Temp_Rate);
                    Product_count++;
                }
            }
        }
        else if (Choice == 2)
        {
            do
            {
                cout << "\nEnter 1 to purchase product" << endl;
                cout << "Enter 2 to display bill" << endl;
                cout << "Enter 0 to exit" << endl;
                cout << "Enter Your Choice : ";
                cin >> Choice2;

                switch (Choice2)
                {
                case 1:
                    cout << "Enter product Id : ";
                    cin >> Temp_Id;
                    for (int i = 0; i < Product_count; i++)
                    {
                        if (p[i].Search(Temp_Id))
                        {
                            p[i].Update_purchase();
                            break;
                        }
                        else if (i == Product_count - 1)
                        {
                            cout << "NO product with matching Id found" << endl;
                        }
                    }
                    break;

                case 2:
                    for (int i = 0; i < Product_count; i++)
                    {
                        p[i].Display_bill();
                    }
                    break;

                case 0:
                    cout << "Thank you for visiting" << endl;
                    break;

                default:
                    cout << "ERROR : INVALID CHOICE" << endl;
                    break;
                }
            } while (Choice2 != 0);
        }
        else
        {
            cout << "Invalid Choice";
        }

    } while (Choice != 0);

    return 0;
}
