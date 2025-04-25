#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
class Shape {
protected:
    double Area;
    virtual void Calculate_area() = 0;

    void Display() {
        cout<<"\nArea: "<<Area<<" sq. units";
    }
};
    
class Rectangle : public Shape {
    double Length, Width;
    
    void Calculate_area() override{
        Area = Length*Width;
    }
public:
    
    Rectangle(double l, double w) : Length(l), Width(w) { 
        Calculate_area();
        Display();
    }
};
class Circle : public Shape {
    double Radius;
    
    void Calculate_area() override{
        Area = M_PI*Radius*Radius;
    }
public:

    Circle(double r) : Radius(r) { 
        Calculate_area();
        Display();
    }
};
    
int main() {
    int Choice=1;
    double a, b;
    while(1) {
        cout<<"\n\n-~Area Calculator~-"
            <<"\nEnter 1 to for area of Circle, 2 for area of Rectangle and 0 to Exit\n\nEnter Choice: ";
        cin>>Choice;
        
        if(Choice==1) {
            cout<<"\nEnter Circle Radius: ";
            cin>>a;
            Shape* Shape = new Circle(a);
        } else if(Choice==2) {
            cout<<"\nEnter Rectangle Length: ";
            cin>>a;
            cout<<"Enter Rectangle Width: ";
            cin>>b;
            Shape* Shape = new Rectangle(a, b);
        } else if(Choice==0) {
            cout<<"\nExiting System\n\n";
            break;
        }
    }
    return 0;
}