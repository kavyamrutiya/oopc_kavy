#include<iostream>
#include <vector>
using namespace std;
class Person
{
    int Age;
    string Name;
    protected:
    Person(){}
    Person(int age , string name)
    {
        Age = age;
        Name = name;
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
    Employee(int age,string name,int id):Person(age,name)
    {
        ID = id;
    }
    void Display_Employee_Details()
    {
        cout<<"ID : "<<ID<<endl;
        Display_person_details();
    }
};
class Manager:private Employee
{
    string Department;
    public:
    Manager(){}
    Manager(int age , string name , int id , string department):Employee(age,name,id)
    {
        Department = department;
    }
    void Display_manager_details()
    {
        Display_Employee_Details();
        cout<<"Department :"<<Department<<endl;
    }
};
int main()
{
    vector<Employee>Emp;
    vector<Manager>Man;
    Employee emp;
    int Employee_count=0,Manager_count=0,choice,age,id;
    string department,name;
    do
    {
        cout<<"Enter 1 to add Employee"<<endl;
        cout<<"Enter 2 to add Manager"<<endl;
        cout<<"Enter 3 to display Employess"<<endl;
        cout<<"Enter 4 to display Manager"<<endl;
        cout<<"Enter 0 to exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter ID :";
                cin>>id;
                cout<<"Enter Name : ";
                cin>>name;
                cout<<"Enter Age : ";
                cin>>age;
                Emp.push_back(Employee(age,name,id));
                Employee_count++;
                break;
            case 2:
                cout<<"Enter ID :";
                cin>>id;
                cout<<"Enter Name : ";
                cin>>name;
                cout<<"Enter Age : ";
                cin>>age;
                cout<<"Enter department : ";
                cin>>department;
                Man.push_back(Manager(age,name,id,department));
                Manager_count++;
                break;
            case 3:
                for(int i=0;i<Employee_count;i++)
                {
                    Emp[i].Display_Employee_Details();
                }
                break;
            case 4:
                for(int i=0;i<Manager_count;i++)
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
    }while(choice);
}