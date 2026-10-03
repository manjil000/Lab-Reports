#include <stdio.h>


int greater(int,int);

void main()
{
    int a,b;
    printf("Enter 2 no.s");
    scanf("%d%d",&a,&b);

    printf("The greatest no. is:%d",greater(a,b));

}
int greater(int x, int y)
{
    if  (x >y)
        return x;
    else
        return y;
}
