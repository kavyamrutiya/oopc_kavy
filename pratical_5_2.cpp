#include <iostream>
using namespace std;
class complex{
    public:
    int realPart,imaginaryPart;
    void input()
    {
        cout<<"Enter your number:";
        cin>>realPart>>imaginaryPart;
    }
    void operator+(complex &b)
    {
        complex ans;
        ans.realPart = realPart + b.realPart;
        ans.imaginaryPart=imaginaryPart+b.imaginaryPart;
        cout<<ans.realPart<<"+"<<ans.imaginaryPart<<"i";
    }
};
int main()
{
    complex a,b;
    a.input();
    b.input();
    a+b;
    return 0;
}
