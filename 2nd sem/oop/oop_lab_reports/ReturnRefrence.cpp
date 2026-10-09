#include <iostream>
using namespace std;

int& getElement(int arr[],int index)
{
    return arr[index];
}
int main()
{
    int number[5]={10,20,30,40,50};

    cout << "Original array";
    for(int i=0;i<5;i++)
    {
        cout << number[i] << " ";
    }
    cout << endl;
    getElement(number,2)=99;
    cout << "Modified Array: ";
    for (int i=0;i<5;i++)
    {
        cout << number[i] << " ";

    }
    cout << endl;
    return 0;

}