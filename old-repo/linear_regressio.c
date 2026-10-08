//linear regression (least squares method) / Fit Straight Line Method
#include<stdio.h>

int main()
{
    int n,i;
    float sumx=0,sumy=0,sumxy=0,sumx2=0,a,b;

    printf("Enter no. of observations\n");
    scanf("%d",&n);

    float x[n],y[n];

    printf("Enter values of x\n");
    for(i=0;i<n;i++)
        scanf("%f",&x[i]);

    printf("Enter values of y\n");
    for(i=0;i<n;i++)
        scanf("%f",&y[i]);

    //calculating sums
    for(i=0;i<n;i++)
    {
        sumx = sumx + x[i];
        sumy = sumy + y[i];
        sumxy = sumxy + x[i]*y[i];
        sumx2 = sumx2 + x[i]*x[i];
    }

    //calculating slope (b) and intercept (a)
    b = (n*sumxy - sumx*sumy)/(n*sumx2 - sumx*sumx);
    a = (sumy - b*sumx)/n;

    printf("\nIntercept = %f and Slope = %f\n",a,b);
    printf("Equation of line: y = %f + %fx",a,b);

    return 0;
}