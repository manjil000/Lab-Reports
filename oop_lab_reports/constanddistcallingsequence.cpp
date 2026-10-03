#include <iostream>
using namespace std;
//constructor always excutes with base class from down
//desctructor from up
class A
{
    public:
    A(){
        cout << "Constructor of class A" << endl;
    }
    ~A()
    {
        cout << " Destructor of class A" <<endl;
    }
};
class B:public A{
    public:
        B()
        {
             cout << "Constructor of class B" << endl;
        }
        ~B()
        {
             cout << "Desctructor of class B" << endl;
        }
};
class C:public B{
    public:
        C()
        {
             cout << "Constructor of class C" << endl;
        }
        ~C()
        {
             cout << "Desctructor of class C" << endl;
        }
};
int main(void)
{
    C c;//calls the default constructor
}