#include <iostream>
using namespace std;
void swap(int &a,int *b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}
void swap(int a, int b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}
int main(void)
{
    int a,b;
    cout << "Enter a and b" << endl;
    cin >> a>>b;
    cout"BEfore swaping using refrence(" << a <<","<< b << ")" <<endl;
    swap(a,b);  
    cout"After swaping using Pointer(" << a <<","<< b << ")" <<endl;

    
}