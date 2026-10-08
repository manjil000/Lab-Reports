//spline interpolation (linear spline)
#include<stdio.h>

int main()
{
    int n,i;
    float x,y;

    printf("Enter no. of terms\n");
    scanf("%d",&n);

    float X[n],Y[n];

    printf("Enter values of X\n");
    for(i=0;i<n;i++)
        scanf("%f",&X[i]);

    printf("Enter values of Y\n");
    for(i=0;i<n;i++)
        scanf("%f",&Y[i]);

    printf("Enter value of x for which you want y\n");
    scanf("%f",&x);

    //Finding interval and applying linear spline
    for(i=0;i<n-1;i++)
    {
        if(x>=X[i] && x<=X[i+1])
        {
            y = Y[i] + ((Y[i+1]-Y[i])/(X[i+1]-X[i]))*(x-X[i]);
            printf("\nValue at x=%g is %f",x,y);
            return 0;
        }
    }

    printf("Given x is out of range\n");

    return 0;
}