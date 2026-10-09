//C program for Newton Raphson Method
#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

float f(float x)
{
    return x*x*x + x*x - 1; //function
}

float differentiate(float x)
{
    return 3*x*x + 2*x; //derivative
}

int main()
{
    float x0,x1;
    int i,maxIteration;

    printf("Enter Initial Guess:\n");
    scanf("%f",&x0);

    printf("Enter Maximum no. of Iteration:\n");
    scanf("%d",&maxIteration);

    //------------ Newton Raphson Method ------------------

    for(i=1;i<=maxIteration;i++)
    {
        if (differentiate(x0) == 0)
        {
            printf("Mathematical Error\n");
            return 0;
        }

        x1 = x0 - (f(x0)/differentiate(x0));

        if (fabs(x1 - x0) < EPSILON)
        {
            printf("Iterations=%d Final Root=%f\n",i,x1);
            return 0;
        }

        printf("Iteration = %d Root = %f\n",i,x1);

        x0 = x1;
    }

    printf("Root = %f Total Iterations = %d",x1,--i);   

    return 0;
}