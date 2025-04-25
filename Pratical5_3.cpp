#include<iostream>
using namespace std;
class Cordinates
{       public:
        int x,y;
        void Get_cordinates()
        {
            cout<<"Enter x and y coordinates e.g(x y) : ";
            cin>>x>>y;
        }
        void operator+(Cordinates &c1)
        {
            Cordinates c;
            c.x=x+c1.x;
            c.y=y+c1.y;
            cout<<"X cordinates : "<<c.x<<endl;
            cout<<"Y cordinates : "<<c.y<<endl;
        }
        void operator-(Cordinates &c1)
        {
             Cordinates c;
            c.x=x-c1.x;
            c.y=y-c1.y;
            cout<<"X cordinates : "<<c.x<<endl;
            cout<<"Y cordinates : "<<c.y<<endl;;

        }
        void operator==(Cordinates &c1)
        {
           if(x==c1.x && y==c1.y)
                    cout<<"The cordinates are equal"<<endl;

            else
                 cout<<"The cordinates are not equal"<<endl;

        }
};
int main()
{

    Cordinates N1,N2;
    N1.Get_cordinates();
    N2.Get_cordinates();
    N1+N2;
    N1-N2;
    N1==N2;
}
