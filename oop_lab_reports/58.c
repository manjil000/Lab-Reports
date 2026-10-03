#include <stdio.h>
int sumNatural(int n)
{
    return (n==0)?0:n+sumNatural(n-1);
}
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);

    printf("Sum of natural no is:%d",sumNatural(n));
    return 0;
}