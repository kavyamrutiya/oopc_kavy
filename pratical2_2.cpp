#include <iostream>
using namespace std;

class Student
{
    int Rollno;
    string Name;
    int Marks[3];
    public:
    Student()
    {
        Rollno = 0;
        Name = "N.A";
        Marks[0] = 0;
        Marks[1] = 0;
        Marks[2] = 0;    
    }
    void Add_student()
    {
        cout<<"Enter student roll number : ";
        cin >> Rollno;
        cout<<"Enter student Name : ";
        cin >> Name;
        cout << "Enter student marks"<<endl;
        cout<<"Maths : ";
        cin >> Marks[0];
        cout <<"Physics : ";
        cin >> Marks[1];
        cout<<"Chemistry : " ;
        cin >> Marks[2];
    }
    void Average()
    {
        cout<< ":::::::Marks obtained::::::::"<<endl;
        cout<<"Maths : "<<Marks[0]<<endl;
        cout<<"Physics : "<<Marks[1]<<endl;
        cout<<"Chemistry : "<<Marks[2]<<endl;
        cout<<"Average : "<<((Marks[0]+Marks[1]+Marks[2])/3)<< endl;
    }
    void Display_details()
    {
        cout<<"ID : "<<Rollno<<endl;
        cout<<"Name : "<<Name<<endl;
        cout<<"Marks Obtained"<<endl;
        cout<<"Maths : "<<Marks[0]<<endl;
        cout<<"Physcis : " << Marks[1]<<endl;
        cout<<"Chmistry : "<<Marks[2]<<endl;
    }
    int Search(int roll)
    {
        if(Rollno== roll)
        {
            return 1;
        }
        else{
            return 0;
        }
    }
};


int main()
{
    Student s[10];
    int Student_count=0 , Choice , Temp;
    char x;
    do
    {
    cout<<"Enter 1 to add student"<<endl;
    cout<<"Enter 2 to dislpay Student Average Marks"<<endl;
    cout<<"Enter 3 to dislpay entire student deatils"<<endl;
    cout<<"Enter 0 to exit"<<endl;
    cout<<"Enter your Choice : ";
    cin >>Choice;
    switch(Choice)
    {
        case 1:
            s[Student_count].Add_student();
            Student_count++;
            break;

        case 2:
            cout<< "Enter student ID to display his/her Average Marks : " ;
            cin >> Temp;
            for(int i=0 ; i<Student_count ; i++)
            {
                if( s[i].Search(Temp))
                {
                    s[i].Average();
                    break;
                }
                else if(i==Student_count-1)
                {
                    cout<<"No matching id found"<<endl;
                }
            }
            break;
        case 3:
        
            cout<<"Enter student ID to dislpay his/her deatils : ";
            cin >> Temp;
            for(int i=0 ; i<Student_count ; i++)
            {
                if( s[i].Search(Temp))
                {
                    s[i].Display_details();
                    break;
                }
                else if(i==Student_count-1)
                {
                    cout<<"No matching id found"<<endl;
                }
            }
            break;
        case 0: 
            cout<<"HAVE A GOOD DAY"<<endl;
            break;
        default : 
            cout<<"Please retry"<<endl;
    }
}while(Choice != 0);
    return 0;
}
