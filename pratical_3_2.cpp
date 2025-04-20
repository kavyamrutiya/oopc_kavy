#include <iostream>
using namespace std;

void Sum_itrative(int array[],int Size)
{
    int i,Sum=0;
    for(i=0 ;i<Size ; i++)
    {
        Sum = Sum+array[i];
    }
    cout<<"The Sum through itrative aaporach is "<<Sum<<endl;
}
int Sum_reccursive(int array[] , int Size)
{ 
    if(Size==0)
    {
        return 0;
    }
    else
    {
        return(array[Size-1] + Sum_reccursive(array , Size-1));
    }
}
int main()
{
    int Size , *array,i,Sum=0;
    cout<<"Enter the Size of array you want : ";
    cin>>Size;
    array = new int[Size];
    cout<<"Enter numbers"<<endl;
    for(i=0 ; i<Size ; i++)
    {
        cin>>array[i];
    }
    Sum_itrative(array , Size);
    Sum = Sum_reccursive(array , Size);
    cout<<"The Sum reccursive aaporach is "<<Sum<<endl;
}
