#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "prime numbers between 1 to 100 are: \n";

    for( num=2; num<=100;num++)
    {
            bool isPrime=true;
        
        for (int i=2;i*i<=num ;i++)
        {
            if(num % i ==0)
            {
                isPrime=false;
                break;
            }

        }
        if(isPrime)
        {
            cout << num << " ";
        }
    }    
        return 0;
}