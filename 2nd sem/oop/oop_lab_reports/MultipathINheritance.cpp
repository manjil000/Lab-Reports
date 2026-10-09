#include <iostream>
using namespace std;

class First
{
    public:
    int a=40;
    int aval()
    {
        return a;
    }
};
class Second: virtual public First{
    public:
    int aval()
    {
        return a;
    }
};
class Third:virtual public First //virtual means kunai ma ek baki rakha 
{
    public:
    int aval()
    {
        return a;
    }
};
class Fourth:public Second,public Third{
    public:
    int aval()
    {
        return a;
    }
};
int main()
{
    Fourth f;
    cout << "a=" <<f.aval()<<endl;
}
//virtual keyword is used to remove ambiquity while inherting the data in multipath inheritance by inheriting the base class vulnerability.