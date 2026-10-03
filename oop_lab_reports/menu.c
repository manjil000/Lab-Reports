#include <stdio.h>
#include <conio.h>

void main()
{
    char choice;
    int n,sum;
    float area,radius;
   do
   {
    printf("1. To find area of circle\n");
    printf("2. To check the given number is odd or even.\n");
    printf("3. To find the sum of N numbers.\n");
    printf("4. Exit\n");
    printf("enter your choice");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
         printf("Enter radius: ");
                scanf("%f", &radius);
                area = 3.1416 * radius * radius;
                printf("Area: %.2f\n", area);
                break;
            case 2:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf(n % 2 == 0 ? "Even\n" : "Odd\n");
                break;
            case 3:
                printf("Enter n: ");
                scanf("%d", &n);
                for (int i = 1; i <= n; i++) sum += i;
                printf("Sum: %d\n", sum);
                break;
            case 4:
                printf("you pressed exit");
            break;
            default:
            printf("Invalid choices");
            break;

    }

   } while (choice != 4);
   

}