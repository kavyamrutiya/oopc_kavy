#include<iostream>
using namespace std;
class Coordinates
{       public:
        int x,y;
        void Get_Coordinates()
        {
            cout<<"Enter x and y coordinates e.g(x y) : ";
            cin>>x>>y;
        }
        void operator+(Coordinates &c1)
        {
            Coordinates c;
            c.x=x+c1.x;
            c.y=y+c1.y;
            cout<<"X Coordinates : "<<c.x<<endl;
            cout<<"Y Coordinates : "<<c.y<<endl;
        }
        void operator-(Coordinates &c1)
        {
             Coordinates c;
            c.x=x-c1.x;
            c.y=y-c1.y;
            cout<<"X Coordinates : "<<c.x<<endl;
            cout<<"Y Coordinates : "<<c.y<<endl;;

        }
        void operator==(Coordinates &c1)
        {
           if(x==c1.x && y==c1.y)
                    cout<<"The Coordinates are equal"<<endl;

            else
                 cout<<"The Coordinates are not equal"<<endl;

        }
};
int main()
{

    Coordinates N1,N2;
    N1.Get_Coordinates();
    N2.Get_Coordinates();
    N1+N2;
    N1-N2;
    N1==N2;
}
