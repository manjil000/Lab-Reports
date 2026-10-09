#include <iostream>

using namespace std;
int &function(int &x)
{
    cout << "MEm location of x=" << &x << endl;
    return x;
}
int main(void)
{
    int a;
    cout << "Enter the value of a " << endl;
    cin >> a;
   cout << function(a) << endl;

   cout << "mem location of a=" << &a << endl;
   
}