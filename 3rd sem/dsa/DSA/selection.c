#include <stdio.h>
int main()
{
    int i,j,n;
    int a[n];
    int temp = 0;

printf("enter size of arraty");
scanf("%d",&n);

    printf("enter no. of elemennts");
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    // --------------- Selkectionn sort -----------------
    // for (i=0;i<n;i++)
    // {
    //     for(j=i+1;j<n;j++)
    //     {
    //         if (a[i] > a[j]){
            
    //             temp = a[i];
    //             a[i] = a[j];
    //             a[j] = temp;                
    //         }

    //     }
    // }

// --------------- Buble sort --------------------

   for (i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if (a[j] > a[j+1]){
            
                temp = a[i];
                a[j] = a[j+1];
                a[j+1] = temp;                
            }

        }
    }

    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
        printf ("\t");
    }
return 0;
}