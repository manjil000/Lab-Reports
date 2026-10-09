#include <iostream>
using namespace std;

class A
{
    public:
    int a;
    A(int x =0) : a(x) //x=5 and a=5 a(x) means initialization
    {
        //a=5;
    }
};
int main(void)
{
    A obj(5);
    cout << obj.a << endl;
}