#include <stdio.h>

long power(int b,int n)
{
    if (n == 0)
        return 1;
    else
        return (b*power(b,n-1));       
} 
long power2(int b,int n)
{
    long result=1;
    for (int i=0;i<n;i++)
    {
        result *=b;
    }
    return result;
}
int main()
{
    int base,exp;
    printf("Enter base and exponent");
    scanf("%d%d",&base,&exp);

    printf("Using recursion:%d^%d=%ld\n",base,exp,power(base,exp));
    printf("Not Using recursion:%d^%d=%ld",base,exp,power2(base,exp));
    return 0;
}