#include <stdio.h>
int main()
{
    int n;
    printf("ENter no. of terms\n");
    scanf("%d",&n);

    float X[n],Y[n],x,sum=0,term;
    int i,j;

    printf("Enter values of X:\n ");
    for (i=0;i<n;i++)
    {
        scanf("%f",&X[i]);
    }

    printf("Enter the value of Y\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&Y[i]);
    }

    printf("Enter value of x for which u want y\n");
    scanf("%f",&x);

    //Applying the Formula
    for(i=0;i<n;i++)
    {
        term = 1;
        for(j=0;j<n;j++)
        {
            if (i!=j)
            {
                term = term * ((x-X[j])/(X[i]-X[j]));
            }
        }
        sum = sum + term * Y[i];
    }

    printf("\n Value at X=%g is =%f",x,sum);

    return 0;
}