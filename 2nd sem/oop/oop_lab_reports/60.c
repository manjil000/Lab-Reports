#include <stdio.h>

int fibo(int n)
{
    return (n<=1) ?n:fibo(n-1)+fibo(n-2);
}
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);

    printf("The fibonacci number at position %d is:%d",n,fibo(n));
}