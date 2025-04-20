#include <iostream>
#include <vector>
using namespace std;

class Fule
{   
    string Fuel_type;

protected:
    Fule(string fuel) { Fuel_type = fuel; }
    void Display_fuel_type()
    {
        cout << "\nFuel Type : " << Fuel_type << endl;
    }
};

class Brand
{
    string Brand_name;

protected:
    Brand(string brand) { Brand_name = brand; }
    void Display_brand()
    {
        cout << "Brand name : " << Brand_name << endl;
    }
};

class Car : private Fule, private Brand
{
public:
    Car(string fuel, string brand) : Fule(fuel), Brand(brand) {}
    void Display_car_details()
    {
        Display_fuel_type();  
        Display_brand();
    }
};

int main()
{
    vector<Car> car;
    int Car_count = 0, choice;
    string fuel, brand;

    do
    {
        cout << "\nEnter 1 to add car details" << endl;
        cout << "Enter 2 to display car details" << endl;
        cout << "Enter 0 to Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Fuel type : ";
            cin >> fuel;  
            cout << "Brand : ";
            cin >> brand;
            car.push_back(Car(fuel, brand));
            Car_count++;
            break;

        case 2:
            for (int i = 0; i < Car_count; i++)
            {
                car[i].Display_car_details();
            }
            break;

        case 0:
            cout << "Thanks for visiting" << endl;
            break;

        default:
            cout << "INVALID CHOICE" << endl;
        }
    } while (choice);

    return 0;
}
