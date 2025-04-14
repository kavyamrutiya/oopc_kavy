#include <iostream>
#include <vector>
using namespace std;

class Shape
{   
    protected:
    float Dimension;
};
class Cricle : protected Shape
{
    float Area;
    void Calculate_area()
    {
        Area = 3.14*Dimension*Dimension;
    }
    public :
    void Display()
    {
        cout<<Area<<endl;
    }
    void Get_radius(float radius)
    {
        Dimension = radius;
        Calculate_area();
    }
};

int main()
{
    vector<Cricle>Cr;
    Cricle c;
    int choice,cricle_count=0 ;
    float radius;
    do
    {
        cout<<"Enter 1 to add cricle"<<endl;
        cout<<"Enter 2 to display cricle details"<<endl;
        cout<<"Enter 0 to Exit"<<endl;
        cout<<"Entre your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter raduis : ";
                cin>>radius;
                c.Get_radius(radius);
                Cr.push_back(c);
                cricle_count++;
                break;
            case 2 : 
                for(int i=0;i<cricle_count;i++)
                {
                    cout<<"Area of cricle "<<i+1<<" is ";
                    Cr[i].Display();
                }
                break;
            case 0:
                cout<<"Have a nice day"<<endl;
                break;
            default :
                cout<<"INVALID CHOICE"<<endl;
                
        }
    }while(choice);

}