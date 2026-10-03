#include <stdio.h>
int main()
{
    int a[3][3],b[3][3],mul[3][3];
    printf("Enter 1st matrix:\n");
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter 2nd matrx\n");
    for(int i=0;i<3;i++)
    {
       for(int j=0;j<3;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("THe first matrix is:\n");
    for(int i=0;i<3;i++)
    {
       for (int j=0;j<3;j++)
       {
         printf("%d  \t",a[i][j]);
       }
       printf("\n");
    }
    printf("THe second matrix is:\n");
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
       {
         printf("%d \t",b[i][j]);
       }
       printf("\n");
    }
    int sum[3][3];
    printf("sum or conjection for the 2 matrix is:\n");
     for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
       {
        sum[i][j]=a[i][j]+b[i][j];
       }
    }
     for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
       {
        printf("%d \t",sum[i][j]);
       }
       printf("\n");
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            mul[i][j]=a[i][j]*b[i][j];
        }
    }
    printf("the disjunction/multiplication for the matrix is:\n");
      for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
       {
        printf("%d \t",mul[i][j]);
       }
       printf("\n");
    }

    
}
