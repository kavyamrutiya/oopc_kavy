#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int Integer,i,j,Temp;
    vector<int>V1,V2;
     cout<<"Enter your Integer array and pres 0 to stop"<<endl;
     for(i=0;Integer!=0;i++)
     {
        cin>>Integer;
        if(Integer!=0)
        {
           
            V1.push_back(Integer);
            V2.push_back(Integer);
        }
     }
     reverse(V1.begin(),V1.end());
     j = V2.size()-1;
     for(i=0;i<V2.size()/2;i++,j--)
     {
        Temp=V2[i];
        V2[i]=V2[j];
        V2[j]=Temp;
     }
     cout<<"Reversed array through reverse funtion : ";
     for(i=0;i<V1.size();i++)
     {
        cout<<V1[i];
     }
     cout<<endl;
     cout<<"Reversed array through itrative method : ";
     for(i=0;i<V2.size();i++)
     {
        cout<<V2[i];
     }
     return 0;
}
