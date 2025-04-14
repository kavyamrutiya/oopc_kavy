#include <iostream> 
using namespace std; 

class Rectangle { 
    int l, w; // Private data members to store length and width 

public: 
    // Member function to set dimensions of the rectangle 
    void setDimension(int a, int b) { // Changed return type to void 
        l = a; 
        w = b; 
    } 

    // Member function to calculate and return the area of the rectangle 
    int area() { 
        int Area = l * w; // Area formula: length * width 
        return Area; 
    } 

    // Member function to calculate and return the perimeter of the rectangle 
    int perimeter() { 
        int Perimeter = 2 * (l + w); // Perimeter formula: 2 * (length + width) 
        return Perimeter; 
    } 
}; 

int main() { 
    Rectangle rect; // Creating a single Rectangle object 
    int l, w, Area, Perimeter; 

    cout << "Enter length and width of Rectangle: "; 
    cin >> l >> w; // Taking user input for length and width 

    rect.setDimension(l, w); // Setting dimensions for the rectangle 

    Area = rect.area();           // Calculating the area 
    Perimeter = rect.perimeter(); // Calculating the perimeter 

    // Displaying the results 
    cout << "The area of the rectangle is " << Area 
         << " and the perimeter of the rectangle is " << Perimeter << "." << endl; 
    return 0; 
}