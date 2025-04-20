#include <iostream>
using namespace std;

class Rectangle {
    int Length, Width;

public:
    void Set_dimension(int a, int b) {
        Length = a;
        Width = b;
    }

    int Calculate_area() {
        return Length * Width;
    }

    int Perimeter() {
        return 2 * (Length + Width);
    }
};

int main() {
    Rectangle rect;
    int l, w;

    cout << "Enter length and width of Rectangle: ";
    cin >> l >> w;

    rect.Set_dimension(l, w);

    int Area = rect.Calculate_area();
    int P = rect.Perimeter();

    cout << "The area of the rectangle is " << Area
         << " and the perimeter of the rectangle is " << P << "." << endl;

    return 0;
}
