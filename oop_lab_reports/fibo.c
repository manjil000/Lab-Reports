#include <stdio.h>
int main()
{
    int i,n,t1=0,t2=1,nextTerm=t1+t2;
    printf("Enter no of terms:");
    scanf("%d",&n);
    printf("Fibonnaci series:%d ,%d",t1,t2);

    for( i=3;i<=n;i++)
    {
        nextTerm=t1+t2;
        printf("%d",nextTerm);
        t1=t2;
        t2=nextTerm;
    }

}