#include <stdio.h>

struct student {
    int roll;
    char name[50];
    int marks[5];
    float percentage;
};

int main() {
    int n, total = 500;

    // Ask for the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Declare an array of students based on the input number
    struct student students[n];

   

    // Loop to take input for 'n' students
    for (int i = 0; i < n; i++) {
        printf("\nEnter Roll No, Name, and marks in 5 subjects for student %d:\n", i + 1);

        // Read roll number and name of the student
        printf("Roll No: ");
        scanf("%d", &students[i].roll);
        printf("Name: ");
        scanf(" %[^\n]%*c", students[i].name);  // To read the entire name with spaces

        int sum = 0;
        // Input marks for 5 subjects
        for (int j = 0; j < 5; j++) {
            printf("Marks for subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
            sum += students[i].marks[j];
        }
        // Calculate percentage
        students[i].percentage = (sum * 100.0) / total;
    }

    // Display all students' records along with their percentage
    printf("\nStudents' records with percentages are:\n");
    for (int i = 0; i < n; i++) {
        printf("Roll: %d, Name: %s, Percentage: %.2f%%\n", students[i].roll, students[i].name, students[i].percentage);
    }

    return 0;
}
