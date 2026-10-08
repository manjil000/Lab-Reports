//C program for Bisection Method
#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

float f(float x)
{
    return x*x*x + x*x - 1; //function
}

int main()
{
    float a,b,c;
    int i,maxIteration;

    printf("Enter Maximum no. of Iteration:\n");
    scanf("%d",&maxIteration);

    //------------ Compute a and b ------------------

    do
    {
        printf("Enter the value of a and b(starting boundary): ");
        scanf("%f%f",&a,&b);

        if (f(a)*f(b) > 0)
        {
            printf("Boundary Values are Invalid\n");
            continue;
        }
        else
        {
            printf("Root lies between %f and %f\n",a,b);
            break;
        }

    } while(1);

    //------------ Bisection Method ------------------

    for(i=1;i<=maxIteration;i++)
    {
        c = (a+b)/2;

        if (fabs(f(c)) < EPSILON)
        {
            printf("Iterations=%d Final Root=%f\n",i,c);
            return 0;
        }

        if (f(a)*f(c) < 0)
            b = c;
        else
            a = c;

        printf("Iteration = %d Root = %f\n",i,c);
    }

    printf("Root = %f Total Iterations = %d",c,--i);

    return 0;
}