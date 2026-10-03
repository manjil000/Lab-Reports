#include <iostream>
using namespace std;

//euta ko properties arko ma jane is inheritance
class Base{
    public:
    int data=40;
    void display()
    {
        cout << "Data=" << data << endl;
    }
};
class Derived:public Base{ //base class ko jati pani content xa derived le use garyo.

};
int main()
{
    Derived d;
    d.display();
}
