#include <iostream>
using namespace std;

int main()
{
    int *ptr;
    ptr=new int;

    cout << " Enter an integer: ";
    cin >> *ptr;

    cout << "You entered: " << *ptr << endl;

    delete ptr;

    int *arr=new int[5];
    cout << "\n Enter 5 integers:\n";
    for(int i=0;i<5;i++)
    {
        cout << "Element "<< i+1 << ":";
        cin >> arr[i];
    }
    cout << "You Entered:\n";
    for (int i=0;i<5;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}