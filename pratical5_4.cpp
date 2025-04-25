#include<iostream>
using namespace std;

class Fahrenheit;
    
class Celsius {
    float Temperature;
public:
    Celsius() : Temperature(0) {}

    Celsius(float f) : Temperature(f) {}

    float ReturnTemp() { return Temperature; }

    void operator=(Fahrenheit); 

    bool operator==(Fahrenheit);
};
    
class Fahrenheit {
    float Temperature;
public:
    Fahrenheit() : Temperature(0) {}

    Fahrenheit(float f) : Temperature(f) {}

    float ReturnTemp() { return Temperature; }

    void operator=(Celsius);

    bool operator==(Celsius);
};
    
bool Celsius::operator==(Fahrenheit F) {
    float temp = F.ReturnTemp();
    temp = temp - 32;
    temp = temp*5;
    temp = temp/9;

    if(temp == Temperature)
    return true;
    else
    return false;
}

void Celsius::operator=(Fahrenheit F) {
    Temperature = F.ReturnTemp();
    Temperature = Temperature - 32;
    Temperature = Temperature*5;
    Temperature = Temperature/9;
}
bool Fahrenheit::operator==(Celsius C) {
    float temp = C.ReturnTemp();
    temp = temp*9;
    temp = temp/5;
    temp = temp + 32;

    if(temp == Temperature)
    return true;
    else
    return false;
}

void Fahrenheit::operator=(Celsius C) {
    Temperature = C.ReturnTemp();
    Temperature = Temperature*9;
    Temperature = Temperature/5;
    Temperature = Temperature + 32;
}
        
int main() {
    int choice=1;
    float Temperature;
    while(choice==1) {
        cout<<"\n\n~-Temperature Comparator-~\n\nEnter Temperature in Celsius: ";
        cin>>Temperature;
        Celsius C(Temperature);
        
        cout<<"\nEnter Temperature in Fahrenheit: ";
        cin>>Temperature;
        Fahrenheit F(Temperature);
        
        Celsius Cel;
        Cel=F;
        Fahrenheit Fah;
        Fah=C;
        
        cout<<endl<<fixed<<C.ReturnTemp()<<" ^C in Fahrenheit is "<<Fah.ReturnTemp()<<" ^F";
        cout<<endl<<endl<<F.ReturnTemp()<<" ^F in Celsius is "<<Cel.ReturnTemp()<<" ^C\n\nSo, ";
        
        if(C==F & F==C)
        cout<<"Celsius temperature is the same as Fahrenheit temperature";
        else
        cout<<"Celsius temperature is not the same as Fahrenheit temperature"<<"\nDo you want to perform operations again with different Temperatures?"<<"\nEnter 1 for yes and 0 for no: ";
        cin>>choice;
    }
    
    
    return 0;
}