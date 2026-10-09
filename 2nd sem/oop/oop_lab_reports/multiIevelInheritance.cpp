#include<iostream>
using namespace std;

class Employee //base class
{
protected://protectes data can be inherited in derived classes
int basesalary =50000;
};
class Developer:public Employee//level one inheritance
{
protected:
    int bonus=5000;
    int totalsalary()
    {
        return basesalary +bonus;
    }
};
class MobileDeveloper:public Developer 
{
    protected:
    int allowance=10000;
    int totalsalary ()
    {
        return basesalary + bonus +allowance;
    }
};
class IOSDeveloper :public MobileDeveloper
{
    public:
    int totalsalary ()
        {
            bonus=basesalary*0.20;
            return basesalary+bonus+allowance;
        }
};
int main(void)
{
    IOSDeveloper dev;
    cout<<"IOS developer has a salary Rs. "<<dev.totalsalary()<<endl;
}