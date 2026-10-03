#include <stdio.h>
#include<stdlib.h>
#include <string.h>

struct students{
    int roll;
    char name[50];
    char course[50];
    int sem;
};

int main()
{
    int n;
    FILE *fptr=fopen("students.txt","wb");
    printf("Enter no. of students");
    scanf("%d",&n);

    struct students student[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter roll,name,course and semester for student",i+1);
        scanf("%d %s %s %d",&student[i].roll,student[i].name,student[i].course,&student[i].sem);
        fwrite(&student[i],sizeof(struct students),1,fptr);
        
    }
    fclose(fptr);
    // Display all those records for which course is B.Sc. IT and semester is 2.

    fptr=fopen("students.txt","r");
    struct students temp;
    printf("\nStudents in BSC.csit, Semester 2:\n");
    while(fread(&temp,sizeof(struct students),1,fptr))
    {
        if(strcmp(temp.course,"BSC.csit") ==0 && temp.sem ==2 )
        {
            printf("Roll.no , Name,course and semester 2 for BSC.csit is:%d %s %s %d",temp.roll,temp.name,temp.course,temp.sem);
        }
    }
    fclose(fptr);


    return 0;
}