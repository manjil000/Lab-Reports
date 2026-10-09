#include <stdio.h>

int main()
{
    int arr[10],max,min;
    printf("Enter 10 no.");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    max=min=arr[0];
    for(int i=1;i<10;i++)
    {
        if (arr[i]>max)
            max=arr[i];
        if (arr[i]<min)
            min=arr[i];
    }
    printf("The largest no. is:%d\n",max);
    printf("The smallest no is:%d",min);
    return 0;

}