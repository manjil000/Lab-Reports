#include <iostream>
#include <string.h>
#define SIZE 20
using namespace std;

class Employee{
    public:
    int id;
    string name;
    float salary;
    void getData(){
        cout << "Enter id of an employee"<<endl;
        cin >> id;
        cout << "ENter the salary" << endl;
        cin >> salary;
        cout << "ENter the name of the employees" << endl;
       cin >> name;
    }
    Employee sorting(Employee emp)
    {
        return emp;
    }
    void sorting (Employee emp[],int n)
    {
        for(int i=0;i<n-1;i++)
        {
            for (int j=0;j<n-i-1;j++)
            {
                Employee temp;
                if(emp[i].name.compare(emp[j].name)>0)
                {
                    temp=emp[i];
                    emp[i]=emp[j];
                    emp[j]=temp;
                }
            }
        }
        display(emp,n);

    }
    void display(Employee emp[],int n)
    {
        cout << "id\t"<< "name\t" << "salary"<<endl;
       for(int i=0;i<n;i++)
       {
         cout << emp[i].id << "\t" << emp[i].name << "\t" << emp[i].salary <<endl;
       }
         
    }
    
};
int main(void)
{
    int n;
    Employee *emp=new Employee[SIZE],temp;
    cout << "Enter how many employees?" << endl;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        emp[i].getData();
    }
    temp.sorting(emp,n);//it calls

    
}