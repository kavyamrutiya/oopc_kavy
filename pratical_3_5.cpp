#include<iostream>
#include<string>
using namespace std;

int SuperDigit(long long Number, int z){
    if(z==1) 
    return Number;
    else{
        long long Super =0;
        int y=0;

        while(Number>=1){
            Super+= Number%10; 
            Number/=10;
            y++;
        }

        return SuperDigit(Super, y); 
    }
}

int main()
{
    string Number, N;
    int k;

    cout<<"\n\nEnter the Number: ";cin>>N;
    cout<<"Enter the number of concatenations of this number: ";cin>>k;

    for(int i=0; i<k; i++){
        Number+=N;
    }

    cout<<"\nThe Super Digit of "<<Number<<" is "<<SuperDigit(stoll(Number), Number.size()); 
    return 0;
}
