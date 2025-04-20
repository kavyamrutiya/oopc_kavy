#include <iostream>
#include <vector>
using namespace std;

class Employee
{
    int Employee_id;
    string Employee_name;
    float Basic_salary;
    float Bonus;
    float Total_salary;
    void Calculate_total_salary()
    {
        Total_salary = Basic_salary + Bonus;
    }
    void Update_total_salary()
    {
        Total_salary = Total_salary - Bonus;
    }

    public:
    Employee()
    {
        Employee_name = "N.A.";
        Basic_salary = 00.00;
        Bonus = 5000;
    }
    void Add_employee(int Temp_id);
    void Display_details();
    void Set_bonus();
    int Search(int Temp_id);

};

int main()
{
    vector<Employee> Emp;
    Employee Emp0;
    int Choice,Employee_count=0,Temp_id,i;
    do
    { 
        cout<<"\nEnter 1 to add Employee"<<endl;
        cout<<"Enter 2 to set  Coustom Bouns"<<endl;
        cout<<"Enter 3 to Dislpay employee data"<<endl;
        cout<<"Enter 4 to EXIT"<<endl;
        cout<<"Enter your Choice : ";
        cin>>Choice;

        switch(Choice)
        {
            case 1:
            if(Employee_count == 0)
            {
                cout<<"Enter Employee ID : ";
                cin>>Temp_id;
                Emp0.Add_employee(Temp_id);
                Emp.push_back(Emp0);
                Employee_count++;
            }
            else
            {
                cout<<"Enter Employee ID : ";
                cin>>Temp_id;
                for(i=0;i<Employee_count;i++)
                {
                    if(Emp[i].Search(Temp_id))
                    {
                        cout<<"ERROR : INVALID ID"<<endl;
                        break;
                    }
                    if(i == Employee_count-1)
                    {
                        Emp0.Add_employee(Temp_id);
                        Employee_count++;
                        Emp.push_back(Emp0);
                    }
                }
                
            }
            break;

            case 2:
                cout<<"Enter Employee ID : ";
                cin>>Temp_id;
                for(i=0;i<Employee_count;i++)
                {
                    if(Emp[i].Search(Temp_id))
                    {
                        Emp[i].Set_bonus();
                        cout<<"Bonus updated sucessfully"<<endl;
                        break;
                    }
                    if(i == Employee_count-1)
                    {
                        cout<<"ERROR : NO RECORD FOUND"<<endl;
                    }
                    break;
                }
                break;
               
            
            case 3:
            cout<<"Enter Employee ID : ";
            cin>>Temp_id;
            for(i=0;i<Employee_count;i++)
            {
                if(Emp[i].Search(Temp_id))
                {
                    Emp[i].Display_details();
                    break;
                }
                if(i == Employee_count-1)
                {
                    cout<<"ERROR : NO RECORD FOUND"<<endl;
                }
            }
           
            break;
        case 4:
            cout<<"Have a nice day"<<endl;
            break;
        default :
            cout<<"IVALID CHOISE : Please try again"<<endl;

        }
    }while(Choice);

    return 0;
}
 void Employee :: Add_employee( int Temp_id)
{
    Employee_id = Temp_id;
    cout<<"Enter employee name : ";
    cin>>Employee_name;
    cout<<"Enter salary : ";
    cin>>Basic_salary;
    Calculate_total_salary();
}
void Employee :: Display_details()
{
    cout<<"ID : "<<Employee_id<<endl;
    cout<<"Name : "<<Employee_name<<endl;
    cout<<"Basic salary : "<<Basic_salary<<endl;
    cout<<"Bonus : "<<Bonus<<endl;
    cout<<"Total salary : "<<Total_salary<<endl;
}
void Employee :: Set_bonus()
{
    Update_total_salary();
    cout<<"Enter bonus amount : ";
    cin>>Bonus;
    Calculate_total_salary();
}
int Employee :: Search(int Temp_id)
{
    if(Employee_id == Temp_id)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
