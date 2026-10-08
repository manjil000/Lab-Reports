//newton divided difference interpolation
#include<stdio.h>

int main()
{
    float x,y;
    int i,j,n;

    printf("Enter no. of terms\n");
    scanf("%d",&n);

    float a[n][n+1];

    printf("Enter value of X \n");
    for(i=0;i<n;i++)
        scanf("%f",&a[i][0]);

    printf("Enter values of Y \n");
    for(i=0;i<n;i++)
        scanf("%f",&a[i][1]);

    printf("Enter value of x for which you want Y \n");
    scanf("%f",&x);

    //Divided Difference Table
    for(j=2;j<n+1;j++)
    {
        for(i=0;i<n-j+1;i++)
        {
            a[i][j] = (a[i+1][j-1] - a[i][j-1]) / (a[i+j-1][0] - a[i][0]);
        }
    }

    printf("The Divided Difference Table is as follows\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i+1;j++)
            printf("%f ",a[i][j]);
        printf("\n");
    }

    //Interpolation
    y = a[0][1];

    for(i=2;i<=n;i++)
    {
        float term = a[0][i];
        for(j=0;j<i-1;j++)
        {
            term = term * (x - a[j][0]);
        }
        y = y + term;
    }

    printf("\n\nValue at x=%g is %f",x,y);

    return 0;
}