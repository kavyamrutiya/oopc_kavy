#include<iostream>
#include <vector>
using namespace std;
class Person
{
    int Age;
    string Name;
    protected:
    Person(){}
    Person(int Age , string Name)
    {
        this->Age = Age;
        this->Name = Name;
    }
    void Display_person_details()
    {
        cout<<"Age : "<<Age<<endl;
        cout<<"Name : "<<Name<<endl;
    }
};
class Employee:private Person
{
    int ID;
    public:
    Employee(){}
    Employee(int Age,string Name,int Id):Person(Age,Name)
    {
        ID = Id;
    }
    void Display_employee_details()
    {
        cout<<"\nID : "<<ID<<endl;
        Display_person_details();
    }
};
class Manager:private Employee
{
    string Department;
    public:
    Manager(){}
    Manager(int Age , string Name , int Id , string Department):Employee(Age,Name,Id)
    {
       this->Department = Department;
    }
    void Display_manager_details()
    {
        Display_employee_details();
        cout<<"Department :"<<Department<<endl;
    }
};
int main()
{
    vector<Employee>Emp;
    vector<Manager>Man;
    Employee emp;
    int Employee_count=0,ManAger_count=0,Choice,Age,Id;
    string Department,Name;
    do
    {
        cout<<"\nEnter 1 to add Employee"<<endl;
        cout<<"Enter 2 to add Manager"<<endl;
        cout<<"Enter 3 to display Employess"<<endl;
        cout<<"Enter 4 to display Manager"<<endl;
        cout<<"Enter 0 to exit"<<endl;
        cout<<"Enter your Choice : ";
        cin>>Choice;
        switch(Choice)
        {
            case 1:
                cout<<"Enter your ID :";
                cin>>Id;
                cout<<"Enter your Name : ";
                cin>>Name;
                cout<<"Enter your  Age : ";
                cin>>Age;
                Emp.push_back(Employee(Age,Name,Id));
                Employee_count++;
                break;
            case 2:
                cout<<"Enter your ID :";
                cin>>Id;
                cout<<"Enter your Name : ";
                cin>>Name;
                cout<<"Enter your Age : ";
                cin>>Age;
                cout<<"Enter your Department : ";
                cin>>Department;
                Man.push_back(Manager(Age,Name,Id,Department));
                ManAger_count++;
                break;
            case 3:
                for(int i=0;i<Employee_count;i++)
                {
                    Emp[i].Display_employee_details();
                }
                break;
            case 4:
                for(int i=0;i<ManAger_count;i++)
                {
                    Man[i].Display_manager_details();
                }
                break;
            case 0:
                cout<<"Thanks for visiting"<<endl;
                break;
            default:
                cout<<"INVALID CHOICE"<<endl;
        }
    }while(Choice);
}
