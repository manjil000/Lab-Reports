#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base()
    {
        cout << "Base Desctructor" << endl;
    }
};
class Derived:public Base
{
    public:
    ~Derived()
    {
        cout << "Derived destructor" << endl;
    }
};
int main(void)
{
    Base *bptr;
    bptr=new Derived();//kunai base class ko pointer lie derived class banauna object banauxam //upcasting (should call both derived and base class)
    delete bptr;

}