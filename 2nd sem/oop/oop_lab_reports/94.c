#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    int marks[3];
    int total;
};

void sort_students(struct Student students[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].total < students[j + 1].total) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        students[i].total = 0;
        for (int j = 0; j < 3; j++) {
            printf("Marks in subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
            students[i].total += students[i].marks[j];
        }
    }

    sort_students(students, n);

    printf("\nSorted Student Records (Descending Order of Total Marks):\n");
    for (int i = 0; i < n; i++) {
        printf("Roll No: %d, Name: %s, Total Marks: %d\n", students[i].roll, students[i].name, students[i].total);
    }

    return 0;
}
