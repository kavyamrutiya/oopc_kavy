#include <iostream>
#include <cmath>
using namespace std;

class Loan_Info
{
    int Loan_id;
    string Applicant_name;
    int Time_period;
    int Total_loan_amount;
    double Emi;
    float Anual_intrest;
    void Emi_calculator(int amount ,int time , float intrest)
    {
       
        Emi = (amount*intrest*pow((1.0+intrest) , time))/(pow((1.0+intrest) , time) - 1);
        
    }
    public:
    void Add_loan()
    {
        cout<<"Enter Loan ID : ";
        cin>>Loan_id;
        cout<<"Enter Applicant Name : ";
        cin>>Applicant_name;
        cout<<"Enter total loan amount : ";
        cin>>Total_loan_amount;
        cout<<"Enter tenure of loan : ";
        cin>> Time_period;
        cout<<"Enter Loan Interst : ";
        cin>>Anual_intrest;
        Emi_calculator(Time_period , Total_loan_amount , Time_period);
    }
    void Display_Details()
    {
        cout<<"Loan ID : "<<Loan_id<<endl;
        cout<<"Applicant's Name : "<<Applicant_name<<endl;
        cout<<"Emi : "<<Emi<<endl;

    }
};


int main()
{
    Loan_Info lf[50];
    int Choice , Loan_count=0;
    do
    {
        cout<<"Enter 1 to add Loan details"<<endl;
        cout<<"Enter 2 to display detials"<<endl;
        cout<<"Enter 3 to EXIT"<<endl;
        cout<<"Enter your Choice : ";
        cin>>Choice;
        switch(Choice)
        {
            case 1 :
                lf[Loan_count].Add_loan();
                Loan_count++;
                break;
            case 2:
                for(int i=0 ; i<Loan_count ; i++)
                {
                    lf[i].Display_Details();
                }
                break;
            case 0:
                cout<<"THANKS FOR VISITING"<<endl;
            default :
                cout<<"INVALID : CHOICE"<<endl;
                break;
        }
    }while(Choice != 0);
    return 0;
}
