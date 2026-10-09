#include <stdio.h>
long int fact(int n)
{
    if (n==1)
        return 1;
    else
        return (n*fact(n-1));    
}
int fact2(int n1)
{
    int i,f=1;
    for(i=1;i<=n1;i++)
    {
        f=f*i;
    }
    return f;
}
int main()
{
    int no;
    long int x;
    printf("Enter any number:");
    scanf("%d",&no);
    x=fact(no);
    printf("\n The factorial using recursion is:%ld",x);
    int w=fact2(no);
    printf("\n The factorial without using recursion is:%d",w);
    return 0;
}
