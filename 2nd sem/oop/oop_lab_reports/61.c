#include <stdio.h>

int fibo(int n)
{
    return (n<=1) ? n:fibo(n-1)+fibo(n-2);
}
int main()
{
    int n;
    printf("Enter no of terms:");
    scanf("%d",&n);

    printf("The fibonacci series is:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",fibo(i));
    }
    printf("\n");
    return 0;
}