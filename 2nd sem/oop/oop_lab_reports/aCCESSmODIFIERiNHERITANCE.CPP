#include <iostream>
using namespace std;
class A
{
    public:
        int a=20,b=30;

};
class B:protected A //when public oUTPUT is 2030
{
    public:
        void display()
        {
            cout << "," <<b << endl;
        }
};
int main(void)
{
    B bo;
   // cout << bo.a << bo.b << endl;
    b.display();
}