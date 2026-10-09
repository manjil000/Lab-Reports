#include <stdio.h>
#include <string.h>
void main()
{
    int s,v=0,c=0;
    char str[100];
    printf("Enter any strings:");
    gets(str);
    for (int i=0;i<strlen(str);i++)
    {
        if (strchr("aeiouAEIOU",str[i]))
            v++;
        else
            c++;   
    }
    printf("The no. of vowels are:%d\n",v);
    printf("The no. of consonants are:%d",c);

    
}