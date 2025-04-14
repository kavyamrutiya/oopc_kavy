#include <iostream>
using namespace std;
class calculator
{
    int number1,number2;
    float fnumber1,fnumber2;
    public:
    int addNumber(int num1,int num2)
    {
        return num1 + num2;
    }
    float addNumber(float fnum1 , float fnum2)
    {
        return fnum1+fnum2;
    }
};
int main()
{
    calculator cal;
    int choice,num1,num2,answer;
    float fnum1,fnum2,fanswer;
    cout<<"Enter 1 to add integer"<<endl;
    cout<<"Enter 2 to add floating number"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        cout<<"Enter 1st number: ";
        cin>>num1;
        cout<<"Enter 2nd number: ";
        cin>>num2;
        answer=cal.addNumber(num1,num2);
        cout<<"Sum of 2 integer is: "<<answer<<endl;
        break;
        case 2:
        cout<<"Enter 1st number: ";
        cin>>fnum1;
        cout<<"Enter 2nd number: ";
        cin>>fnum2;
        fanswer=cal.addNumber(fnum1,fnum2);
        cout<<"Sum of 2 floating number is: "<<fanswer<<endl;
        break;
        default:
        cout<<"INVALID CHOICE";
    }
}