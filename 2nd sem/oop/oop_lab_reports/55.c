#include <stdio.h>

int sumofDigits(int num,int a,int b,int c, int d)
{
    int sum=a+b+c+d+num;
    
    return sum;
}
int main()
{
    int num,a,b,c,d;
    printf("Enter any 5 digit integer");
    scanf("%d%d%d%d%d",&num,&a,&b,&c,&d);

    printf("The sum is:%d",sumofDigits(num,a,b,c,d));
}