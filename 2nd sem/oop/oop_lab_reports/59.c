#include <stdio.h>

int product(int n)
{
    return (n==1) ? 1:n*product(n-1);
}
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    printf("The product of n natural no. is:%d",product(n));
    return 0;
}
