#include <iostream>
using namespace std;

inline int square(int x)
{
    return x*x;
}
int main()
{
    int num;

    cout << "Enter a number";
    cin >> num;

    cout << "Square of " << num << "is :" << square(num) << endl;
    cout << "Square of " << num +1 << "is :"<< square(num +1)   << endl;

    return 0;
}