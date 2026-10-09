//C program for Secant Method
#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

float f(float x)
{
    return x*x*x + x*x - 1; //function
}

int main()
{
    float x0,x1,x2;
    int i,maxIteration;

    printf("Enter first initial guess:\n");
    scanf("%f",&x0);

    printf("Enter second initial guess:\n");
    scanf("%f",&x1);

    printf("Enter Maximum no. of Iteration:\n");
    scanf("%d",&maxIteration);

    //------------ Secant Method ------------------

    for(i=1;i<=maxIteration;i++)
    {
        if ((f(x1) - f(x0)) == 0)
        {
            printf("Mathematical Error\n");
            return 0;
        }

        x2 = x1 - (f(x1)*(x1 - x0)) / (f(x1) - f(x0));

        if (fabs(x2 - x1) < EPSILON)
        {
            printf("Iterations=%d Final Root=%f\n",i,x2);
            return 0;
        }

        printf("Iteration = %d Root = %f\n",i,x2);

        x0 = x1;
        x1 = x2;
    }

    printf("Root = %f Total Iterations = %d",x2,--i);

    return 0;
}