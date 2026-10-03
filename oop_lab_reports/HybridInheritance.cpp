#include <iostream>
using namespace std;
class Employee
{
    protected:
    int salary=20000;
};
class Developer:public Employee{
    protected:
    int bonus=5000;
    int totalsalary()
    {
        return salary + bonus;
    }
};
class webdeveloper:public Developer
{
    protected:
    int bonus=0.1*salary;
    int totalsalary()
    {
        return salary + bonus;
    }
};
class MobileDeveloper:public webdeveloper
{
    protected:
    int totalsalary()
    {
        bonus=0.2*salary;
        return salary + bonus;
    }
};
class FrontEndDeveloper:public webdeveloper
{
    public:
    int totalSalary()
    {
        bonus=bonus + 4000;
        return salary + bonus;
    }
};
class AndroidDeveloper:public MobileDeveloper
{
    public:
    int totalSalary()
    {
        bonus=bonus + 10000;
        return salary + bonus;
    }
};
class BackendDeveloper: public webdeveloper
{
    public:
    int totalSalary()
    {
        bonus=bonus + 6000;
        return salary + bonus;
    }
};
class IODeveloper:public MobileDeveloper
{
    public:
    int totalSalary()
    {
        bonus=bonus+2000;
        return salary+bonus;
    }
};
int main()
{
    AndroidDeveloper ad;
    IODeveloper id;
    FrontEndDeveloper fd;
    BackendDeveloper bd;
    cout << "salary of IOS developer="<<id.totalSalary()<<endl;
    cout << "salary of Android developer="<<ad.totalSalary()<<endl;
    cout << "salary of Frontend developer="<<fd.totalSalary()<<endl;
    cout << "salary of backend developer="<<bd.totalSalary()<<endl;
    
    return 0;
}