#include <iostream>
using namespace std;

class OneClass
{
    public:
        void print()
        {
            cout << "I am from one class" <<endl;
        }
};
class AnotherClass
{
    private:
        OneClass *ptr;
    public:    
    //AnotherClass(myData *p):ptr(p) {},we can initialize
    AnotherClass(OneClass *p)//euta class ko objec le arko lie call garyo through arrow operator;
    {
        ptr =p;
    }
    OneClass *operator ->()
    {
        return ptr;
    }
};
int main(void)
{
    OneClass *data=new OneClass();
    AnotherClass aptr(data);
    aptr->print();//calls print() through the overloaded

}