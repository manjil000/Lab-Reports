#include <stdio.h>
int main()
{
    int n,i;
    float sum=0;
    printf("Enter the no. of elements");
    scanf("%d",&n);

    float arr[n];
    printf("Enter %d numbers\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%f",&arr[i]);
        sum+=arr[i];
    }
    printf("Sum: %.2f\n", sum);
    printf("Average: %.2f\n", sum / n);

    return 0;
}