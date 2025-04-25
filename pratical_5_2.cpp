#include <iostream>
using namespace std;

class Complex
{
    public:
    int Real_part, Imgnary_part;
    void input()
    {
        cout<<"Enter num :";
        cin>>Real_part>>Imgnary_part;

    }
    void operator+(Complex &b)
    {
        Complex Ans;
        Ans.Real_part = Real_part + b.Real_part;
        Ans.Imgnary_part= Imgnary_part+b.Imgnary_part;
        cout<<Ans.Real_part<<"+"<<Ans.Imgnary_part<<"i";
    }

};
int main()
{
    Complex a,b ,x;
    a.input();
    b.input();
    a+b;
    return 0;

}

