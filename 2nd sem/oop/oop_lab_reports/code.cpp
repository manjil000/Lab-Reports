#include <iostream>
#define size 100
using namespace std;
void sorting(int[],int);//prototype
void display(int[],int);
int main(void)
{
    int i,n,num[size];
    cout << "Enter how many nos." << endl;
    cin >>n;
    for(i =0;i<n;i++)
    {
        cout << "num[" << i <<"]=";
        cin >> num[i];

    }
    cout << "array BEfore sortingg" << endl;
    display(num,n);
    cout << "Array after sorting" << endl;
    sorting(num,n);
}
void sorting(int a[],int n)
{
    int x;
    for (int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j]);
            a[i]=a[j];
            a[j]=x;
        }
    }
    display(a,n);
}

void display(int a[],int n)
{
    cout << endl;
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
}